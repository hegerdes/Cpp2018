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
#include "Camera.hpp"

#include <iostream>
#include <sys/types.h>
namespace asteroids
{

MainWindow::MainWindow(
    std::string title, 
    std::string plyname, int w, int h)
{
	height = h;
	width = w;
    /* Initialize SDL's Video subsystem */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		
		printf("Failed to init SDL\n");
		exit(EXIT_FAILURE);
	}

	/* Create our window centered at 512x512 resolution */
	mainWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_OPENGL);

    if (!mainWindow)
	{
		printf("Unable to create window\n");
		exit(EXIT_FAILURE);
	}

    /* Create our opengl context and attach it to our window */
	mainContext = SDL_GL_CreateContext(mainWindow);

	/* Set our OpenGL version.
	   SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled */
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	/* 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it */
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	/* Turn on double buffering with a 24bit Z buffer.
	   You may need to change this to 16 or 32 for your system */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	/* This makes our buffer swap syncronized with the monitor's vertical refresh */
	SDL_GL_SetSwapInterval(1);

	/* Init GLEW */
	#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	glewInit();
	#endif

	SDL_GL_SwapWindow(mainWindow);

	/* Init OpenGL projection matrix */
	glClearColor(0.0, 0.0, 0.0, 1.0);
	float ratio = 1024 * 1.0 / 768;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 1027, 768);
	gluPerspective(45, ratio, 1, 10000);

	/* Ender model view mode */

	glMatrixMode(GL_MODELVIEW);

	model = new Model(plyname);
	camera = new Camera(Vector(-20.0,0.0,-40.0), 1.0, 5.0);
}

void MainWindow::execute()
{

	bool loop = true;

	/*TO DO FIX Camera. (applay)*/
	/* Set camera position and direction */
	glLoadIdentity();
	//gluLookAt(-5.0, 0.0, -30.0, 20.0, -5.0, 1.0, 0.0, 1.0, 0.0);

	while (loop)
	{
		glClear(GL_COLOR_BUFFER_BIT );

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			/* Check if window has been closed */
			/* Keybindings */
			switch(event.type)                 
			{                     
				case SDL_QUIT:                         
					loop = false;                         
					break;                     
				case SDL_KEYDOWN:                         
					switch(event.key.keysym.sym)                         
					{                             
						case SDLK_w:    camera->move(Camera::FORWARD); break;                             
						case SDLK_s:    camera->move(Camera::BACKWARD); break;                             
						case SDLK_a:    camera->move(Camera::LEFT); break;                             
						case SDLK_d:    camera->move(Camera::RIGHT); break;                             
						case SDLK_KP_4: camera->turn(Camera::LEFT); break;                             
						case SDLK_KP_6: camera->turn(Camera::RIGHT); break;                         
					}                         
					break;          
			}
			camera->apply();
			model->render();
			
		}

		/* Bring up back buffer */
		SDL_GL_SwapWindow(mainWindow);
	}

}

MainWindow::~MainWindow()
{
	if(model)
	{
		delete model;
	}
	if(camera)
	{
		delete camera;
	}

	/* Delete our OpengL context */
	SDL_GL_DeleteContext(mainContext);

	/* Destroy our window */
	SDL_DestroyWindow(mainWindow);

	/* Shutdown SDL 2 */
	SDL_Quit();
	
}

} // namespace asteroids
