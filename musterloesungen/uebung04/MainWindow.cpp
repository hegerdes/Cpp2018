/*
 *  MainWindow.cpp
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "MainWindow.hpp"

#include <iostream>

namespace asteroids
{

MainWindow::MainWindow(
    std::string title, 
    std::string plyname, int w, int h)
    : m_camera(Vector(0.0f, 0.0f, -700.0f), 0.05f, 5.0f) 
{
    // Save width and height
    m_height = h;
    m_width = w;

    // Setup window
    m_sdlWindow = SDL_CreateWindow(
        "SDL Main Window", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		m_width, m_height, SDL_WINDOW_OPENGL);

    if(!m_sdlWindow)
    {
        std::cout << "MainWindow: Unable to create SDL window" << std::endl;
    }

    m_sdlGlcontext = SDL_GL_CreateContext(m_sdlWindow);

    if(!m_sdlGlcontext)
    {
        std::cout << "MainWindow: Unable to creade SDL GL context" << std::endl;
    } 

    if(m_sdlWindow && m_sdlGlcontext)
    {
        // Set our OpenGL version.
	    // SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled 
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        // 3.2 is part of the modern versions of OpenGL, 
        // but most video cards whould be able to run it 
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

        // Turn on double buffering with a 24bit Z buffer.
	    // You may need to change this to 16 or 32 for your system 
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        // This makes our buffer swap syncronized with the monitor's vertical refresh 
        SDL_GL_SetSwapInterval(1);

#ifndef __APPLE__
        glewExperimental = GL_TRUE;
        glewInit();
#endif
        SDL_GL_SwapWindow(m_sdlWindow);

        // Init OpenGL projection matrix 
        glClearColor(0.0, 0.0, 0.0, 1.0);
        float ratio = m_width * 1.0 / m_height;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, m_width, m_height);
        gluPerspective(45, ratio, 1, 10000);

        // Enter model view mode 
        glMatrixMode(GL_MODELVIEW);
    }

    // Load model
    m_model = new Model(plyname);
}

void MainWindow::execute()
{
    if(m_model && m_sdlWindow && m_sdlGlcontext)
    {
        bool loop = true;

        // Set camera position and direction 
        glLoadIdentity();
        
        while (loop)
        {
            // Clear background
            glClear(GL_COLOR_BUFFER_BIT );

            m_camera.apply();

            // Handle events
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                /* Check if window has been closed */
                switch(event.type)
                {
                    case SDL_QUIT:
                        loop = false;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_w:    m_camera.move(Camera::FORWARD);    break;
                            case SDLK_s:    m_camera.move(Camera::BACKWARD);   break;
                            case SDLK_a:    m_camera.move(Camera::LEFT);       break;
                            case SDLK_d:    m_camera.move(Camera::RIGHT);      break;
                            case SDLK_KP_4: m_camera.turn(Camera::LEFT);       break;
                            case SDLK_KP_6: m_camera.turn(Camera::RIGHT);      break;
                        }
                        break;
                    default:
                        break;
                }

            }

            // Render model
            m_model->render();

            // Bring up back buffer 
		    SDL_GL_SwapWindow(m_sdlWindow);
        }
    }
}

MainWindow::~MainWindow()
{
    // Delete model
    if(m_model)
    {
        delete m_model;
    }

    // Cleanup SDL stuff
	SDL_GL_DeleteContext(m_sdlGlcontext);

	// Destroy our window 
	SDL_DestroyWindow(m_sdlWindow);

	// Shutdown SDL 2 
	SDL_Quit();
}

} // namespace asteroids
