/*
 *  TriangleMesh.cpp
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "TriangleMesh.hpp"
#include "../PLYIO.hpp"

#include <iostream>

/* OpenGL / glew Headers */
#define GL3_PROTOTYPES 1
#include <GL/glew.h>

namespace asteroids
{

TriangleMesh::TriangleMesh()
{
    // Init member variables
	m_numFaces      = 0;
	m_numVertices   = 0;
	m_vertexBuffer  = 0;
	m_indexBuffer   = 0;

	// Setup rotation and position
	m_xAxis 		= Vector(1.0, 0.0, 0.0);
	m_yAxis 		= Vector(0.0, 1.0, 0.0);
	m_zAxis 		= Vector(0.0, 0.0, 1.0);
	m_position		= Vector(0.0, 0.0, 0.0);

    // Init initial position
    initTransformations();
}

TriangleMesh::TriangleMesh(const TriangleMesh& other)
{
    m_numFaces = other.m_numFaces;
    m_numVertices = other.m_numVertices;
    m_vertexBuffer = new float[3 * m_numVertices];
    m_indexBuffer = new int[3 * m_numFaces];

    m_xAxis = other.m_xAxis;
    m_yAxis = other.m_yAxis;
    m_zAxis = other.m_zAxis;
    m_position = other.m_position;
    m_rotation = other.m_rotation;
    m_transformation = other.m_transformation;
}

TriangleMesh::TriangleMesh(int* faces, float* vertices, int a, int b)
{
	// Save mesh information and buffers
	m_numFaces      = a;
	m_numVertices   = b;
	m_vertexBuffer  = vertices;
	m_indexBuffer   = faces;

	// Init initial position
    initTransformations();
}

TriangleMesh::TriangleMesh(const std::string& filename)
{
    LoadPLY(
        filename, 
        m_vertexBuffer, m_indexBuffer, 
        m_numVertices, m_numFaces);

    // Init initial position
    initTransformations();
}

void TriangleMesh::initTransformations()
 {
    // Setup rotation and position
	m_xAxis 		= Vector(1.0, 0.0, 0.0);
	m_yAxis 		= Vector(0.0, 1.0, 0.0);
	m_zAxis 		= Vector(0.0, 0.0, 1.0);
	m_position		= Vector(0.0, 0.0, 0.0);
	m_rotation.fromAxis(Vector(0.0, 0.0, 1.0), 0.0f);

 }

void TriangleMesh::rotate(ACTION axis, float s)
{
	Quaternion qr;
 
    switch(axis)
    {
    case PITCH: qr.fromAxis(m_yAxis, s);
                m_xAxis = qr * m_xAxis;
                m_zAxis = qr * m_zAxis; break;
     
    case YAW:   qr.fromAxis(m_xAxis, s);
                m_yAxis = qr * m_yAxis;
                m_zAxis = qr * m_zAxis; break;
 
    case ROLL:  qr.fromAxis(m_zAxis, s);
                m_yAxis = qr * m_yAxis;
                m_xAxis = qr * m_xAxis; break;
     
    default: std::cout << "Will handel that key later" << std::endl;
    }
}

void TriangleMesh::move(ACTION axis, float speed)
{
	switch (axis) 
	{
		case ACCEL: 
			m_position += m_xAxis * speed;
			break;
		case STRAFE: 
			m_position += m_yAxis * speed;
			break;
		case LIFT: 
			m_position += m_zAxis * speed;
			break;
		default: 
			std::cout << "Bewegungsrichtung nicht definiert" << std::endl;
			break;
	}
}

void TriangleMesh::computeMatrix()
{
	float* matrix_trans = m_transformation.getData();
 
    matrix_trans[0]  = m_yAxis[0];
    matrix_trans[1]  = m_yAxis[1];
    matrix_trans[2]  = m_yAxis[2];
 
    matrix_trans[4]  = m_xAxis[0];
    matrix_trans[5]  = m_xAxis[1];
    matrix_trans[6]  = m_xAxis[2];
 
    matrix_trans[8]  = m_zAxis[0];
    matrix_trans[9]  = m_zAxis[1];
    matrix_trans[10] = m_zAxis[2];
 
    matrix_trans[12] = m_position[0];
    matrix_trans[13] = m_position[1];
    matrix_trans[14] = m_position[2];
}

void TriangleMesh::printTriangleMeshInformation()
{
    std::cout << "TriangleMesh statistics: " << std::endl;
    std::cout << "Num vertices: " << m_numVertices << std::endl;
    std::cout << "Num faces:    " << m_numFaces << std::endl;
}

void TriangleMesh::printBuffers()
{
    for(int i = 0; i < m_numVertices; i++)
    {
        std::cout << "v: " << m_vertexBuffer[3 * i]     << " "
                           << m_vertexBuffer[3 * i + 1] << " " 
                           << m_vertexBuffer[3 * i + 2] << std::endl;  
    }

    for(int i = 0; i < m_numFaces; i++)
    {
        std::cout << "f: " << m_indexBuffer[3 * i]     << " "
                           << m_indexBuffer[3 * i + 1] << " " 
                           << m_indexBuffer[3 * i + 2] << std::endl;  
    }
}

void TriangleMesh::render()
{
    // Compute transformation matrix
	computeMatrix();

	// Push old transformation of the OpenGL matrix stack and
	// start rendering the mesh in according to the
	// internal transformation matrix
	glPushMatrix();
	glMultMatrixf(m_transformation.getData());

	// Render mesh
	for(int i = 0; i < m_numFaces; i++)
	{
		// Get position og current triangle in buffer
		int index = 3 * i;

		// Get vertex indices of triangle vertices
		int a = 3 * m_indexBuffer[index];
		int b = 3 * m_indexBuffer[index + 1];
		int c = 3 * m_indexBuffer[index + 2];

		// Render wireframe TriangleMesh
		glBegin(GL_LINE_LOOP);
        //TODO Set color
		glColor3f(0.5f, 0.0f, 1.0f);
		glVertex3f(m_vertexBuffer[a], m_vertexBuffer[a + 1], m_vertexBuffer[a + 2]);
		glVertex3f(m_vertexBuffer[b], m_vertexBuffer[b + 1], m_vertexBuffer[b + 2]);
		glVertex3f(m_vertexBuffer[c], m_vertexBuffer[c + 1], m_vertexBuffer[c + 2]);
		glEnd();

	}

	// Pop transformation matrix of this object
	// to restore the previous state of the OpenGL
	// matrix stack
	glPopMatrix();
}


void TriangleMesh::setColor(float r, float g, float b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

TriangleMesh::~TriangleMesh()
{
    if(m_vertexBuffer)
    {
        delete[] m_vertexBuffer;
    }

    if(m_indexBuffer)
    {
        delete[] m_indexBuffer;
    }
}

} // namespace asteroids 
