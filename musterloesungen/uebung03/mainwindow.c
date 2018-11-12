/*
 *  mainwindow.c
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

/* C library includes */
#include <stdio.h>

/* Project includes */
#include "mainwindow.h"

int createSDLWindow(SDL_Window** mainWindow, SDL_GLContext* mainContext)
{
	/* Initialize SDL's Video subsystem */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to init SDL\n");
		return 0;
	}

	/* Create our window centered at 512x512 resolution */
	*mainWindow = SDL_CreateWindow("SDL Main Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1024, 768, SDL_WINDOW_OPENGL);

	/* Check that everything worked out okay */
	if (!mainWindow)
	{
		printf("Unable to create window\n");
		printSDLError(__LINE__);
		return 0;
	}

	/* Create our opengl context and attach it to our window */
	*mainContext = SDL_GL_CreateContext(*mainWindow);
	
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
	
	
	SDL_GL_SwapWindow(*mainWindow);

	/* Init OpenGL projection matrix */
	glClearColor(0.0, 0.0, 0.0, 1.0);
	float ratio =  1024 * 1.0 / 768;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 1027, 768);
	gluPerspective(45,ratio,1,10000);

	/* Ender model view mode */

	glMatrixMode(GL_MODELVIEW);

	return 1;
}

void mainLoop(SDL_Window* mainWindow, Model* model)
{
    int loop = 1;
    int i, a, b, c, index;

	/* Set camera position and direction */
	glLoadIdentity();
	gluLookAt(0.0, 0.0, -750.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);

	while (loop)
	{
	

		glClear(GL_COLOR_BUFFER_BIT );

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			/* Check if window has been closed */
			if (event.type == SDL_QUIT)
			{
				loop = 0;
			}
		}

		/* Render model */
		for (i = 0; i < model->numFaces; i++)
		{
			/* Get position og current triangle in buffer */
			index = 3 * i;

			/* Get vertex indices of triangle vertices */
			a = 3 * model->indexBuffer[index];
			b = 3 * model->indexBuffer[index + 1];
			c = 3 * model->indexBuffer[index + 2];

			//printf("%d %d %d\n", a, b, c);

			/* Render wireframe model */
			glBegin(GL_LINE_LOOP);
			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(model->vertexBuffer[a], model->vertexBuffer[a + 1], model->vertexBuffer[a + 2]);
			glVertex3f(model->vertexBuffer[b], model->vertexBuffer[b + 1], model->vertexBuffer[b + 2]);
			glVertex3f(model->vertexBuffer[c], model->vertexBuffer[c + 1], model->vertexBuffer[c + 2]);
			glEnd();
			glFlush();
		}

		/* Bring up back buffer */
		SDL_GL_SwapWindow(mainWindow);

	}
}

void cleanupSDL(SDL_Window* mainWindow, SDL_GLContext* mainContext)
{
	/* Delete our OpengL context */
	SDL_GL_DeleteContext(mainContext);

	/* Destroy our window */
	SDL_DestroyWindow(mainWindow);

	/* Shutdown SDL 2 */
	SDL_Quit();
}

void printSDLError(int line)
{
	const char* error = SDL_GetError();

	if (error != "")
	{
		printf("SLD Error : %s\n", error);

        if(line != -1)
        {
			printf("Line : %d\n",line);
        }
		SDL_ClearError();
	}
}
