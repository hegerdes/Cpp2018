/*
 *  plyio.c
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
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

	while(strcmp(buffer,"end_header\n") !=0)
	{
		fgets(buffer,80,fp);
		sscanf(buffer, "element vertex %i", &numVertex);
		sscanf(buffer, "element face %i", &numFace);
		printf("OUT: %s", buffer);
	}
	
	
	printf("VertexNum: %d und FaceNum: %d\n",numVertex,numFace);

	if(!isPly || !numFace)
	{
		printf("If Falsche\n");
		model->numVertices = 0;
		model->numFaces = 0;
		model->vertexBuffer = 0;
		model->indexBuffer = 0;
	}
	else
	{

		float*  vertexBuffer = (float*)malloc(3 * numVertex * sizeof(float));
		int* indexBuffer = (int*)malloc(3 * numFace * sizeof(int));

		if(vertexBuffer == NULL || indexBuffer == NULL)
		{
			printf("Interner Fehler: Speicher konnte nicht reserviert werden.\n");
			exit(1);
		}

		model->vertexBuffer = vertexBuffer;
		model->indexBuffer = indexBuffer;
		model->numFaces = numFace;
		model->numVertices = numVertex;

		fread(vertexBuffer, sizeof(float), 3*numVertex, fp);
		fread(indexBuffer, sizeof(int), 3* numFace, fp);
	}

	fclose(fp);

}


void freeModel(Model* model)
{
	free(model->indexBuffer);
	free(model->vertexBuffer);
}
