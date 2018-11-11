/*
 *  plyio.c
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 * 
 * @edited Henrik Gerdes, Manuel Eversmeyer
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "plyio.h"


void loadply(char *file, Model *model)
{
	FILE* fp;

	fp = fopen(file, "r");
	char buffer[81] = {0};
	int canOpen = 0;
	int isPly = 0;
	int numVertex = 0;
	int numFace = 0;

	if(fp == NULL)
	{
		canOpen = 1;
		printf("Fehler beim Laden der der Datei: %s\n", file);
	}

	//Check Ply
	fgets(buffer,80,fp);
	if(strcmp(buffer,"ply\n") == 0)
	{
		isPly = 1;
	}
	//Parse header
	while(strcmp(buffer,"end_header\n") !=0)
	{
		fgets(buffer,80,fp);
		sscanf(buffer, "element vertex %i", &numVertex);
		sscanf(buffer, "element face %i", &numFace);
		//printf("OUT: %s", buffer);
	}

	// Set 0 Model if any error
	if(!isPly || canOpen || !numFace || !numVertex)
	{
		printf("If Falsche\n");
		model->numVertices = 0;
		model->numFaces = 0;
		model->vertexBuffer = 0;
		model->indexBuffer = 0;
	}
	else
	{
		//Allocate memory
		float*  vertexBuffer = (float*)malloc(3 * numVertex * sizeof(float));
		int* indexBuffer = (int*)malloc(3 * numFace * sizeof(int));

		if(vertexBuffer == NULL || indexBuffer == NULL)
		{
			printf("Interner Fehler: Speicher konnte nicht reserviert werden.\n");
			exit(1);
		}

		//Save info to model
		model->vertexBuffer = vertexBuffer;
		model->indexBuffer = indexBuffer;
		model->numFaces = numFace;
		model->numVertices = numVertex;

		//Read all Vertex
		fread(vertexBuffer, sizeof(float), 3*numVertex, fp);
		int count;
		char buf;
		//Read all Index
		for(count = 0; count<model->numFaces;count++)
		{
			fread(&buf, sizeof(unsigned char), 1, fp);
			fread(&indexBuffer[3 * count], sizeof(int), 1, fp);
			fread(&indexBuffer[3 * count+1], sizeof(int), 1, fp);
			fread(&indexBuffer[3 * count+2], sizeof(int), 1, fp);
		}
		//fread(indexBuffer, sizeof(int), 3*numFace, fp);
	}

	fclose(fp);

}


void freeModel(Model* model)
{
	free(model->indexBuffer);
	free(model->vertexBuffer);

	model->numFaces = 0;
	model->numVertices = 0;
}
