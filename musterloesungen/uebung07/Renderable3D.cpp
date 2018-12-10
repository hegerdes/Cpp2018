/*
 *  Renderable3D.cpp
 *
 *  Created on: Nov. 25 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "Renderable3D.hpp"

namespace asteroids
{

void Renderable3D::initTransformations()
 {
    // Setup rotation and position
	m_xAxis 		= Vector3f(1.0, 0.0, 0.0);
	m_yAxis 		= Vector3f(0.0, 1.0, 0.0);
	m_zAxis 		= Vector3f(0.0, 0.0, 1.0);
	m_position		= Vector3f(0.0, 0.0, 0.0);
	m_rotation.fromAxis(Vector3f(0.0, 0.0, 1.0), 0.0f);
 }

 void Renderable3D::rotate(ACTION axis, float s)
{
    Quaternion nq;

	// Get the wanted operation and calculate the new coordinates
	switch(axis)
	{
	case YAW:
		nq.fromAxis(m_yAxis, s);
		m_xAxis = nq * m_xAxis;
		m_zAxis = nq * m_zAxis;
		break;

	case PITCH:
		nq.fromAxis(m_zAxis, s);
		m_xAxis = nq * m_xAxis;
		m_yAxis = nq * m_yAxis;
		break;

	case ROLL:
		nq.fromAxis(m_xAxis, s);
		m_yAxis = nq * m_yAxis;
		m_zAxis = nq * m_zAxis;
		break;
    default:
        return;
	}

	// Update mesh rotation 
	m_rotation = m_rotation * nq;
}

void Renderable3D::move(ACTION axis, float speed)
{
    Vector3f direction;

	// Determine the correct axis of the local system
	switch(axis)
	{
	case ACCEL:
		direction = m_xAxis;
		break;
	case STRAFE:
		direction = m_yAxis;
		break;
	case LIFT:
		direction = m_zAxis;
        break;
    default:
        return;
	}

	// Update mesh position
	m_position = m_position + direction * speed;
}

void Renderable3D::computeMatrix()
{
    // Compute the transformation matrix for this object
	// according to the current position and rotation
	// state
	m_transformation[0][0]  = m_yAxis[0];
	m_transformation[0][1]  = m_yAxis[1];
	m_transformation[0][2]  = m_yAxis[2];

	m_transformation[1][0]  = m_xAxis[0];
	m_transformation[1][1]  = m_xAxis[1];
	m_transformation[1][2]  = m_xAxis[2];

	m_transformation[2][0]  = m_zAxis[0];
	m_transformation[2][1]  = m_zAxis[1];
	m_transformation[2][2] = m_zAxis[2];

	m_transformation[3][0] = m_position[0];
	m_transformation[3][1] = m_position[1];
	m_transformation[3][2] = m_position[2];
}


}