/*
 *  Camera.cpp
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <GL/glu.h>

#include "Camera.hpp"
namespace asteroids

{

    Camera::Camera()
    {
        m_initial = Vector(0,0,0);
        m_l = Vector(0,0,-1);

    }

    Camera::Camera(Vector position, float turnSpeed, float moveSpeed)
    {
        m_initial = position;
        m_l = Vector(0,0,-1);
        m_trans = Vector(0,0,0);
        m_rot = Vector(0,0,0);
        m_up = Vector(0,1,0);
        m_turnSpeed = turnSpeed;
        m_moveSpeed = moveSpeed;
        
    }

    void Camera::move(CameraMovement dir)
    {  


        switch (dir)
	    { 
		    case FORWARD:	m_trans.x += m_moveSpeed * sin(m_rot.y);
						    m_trans.z += m_moveSpeed * cos(m_rot.y);
						    break;

		    case BACKWARD:	m_trans.x -= m_moveSpeed * sin(m_rot.y);
						    m_trans.z -= m_moveSpeed * cos(m_rot.y);
						    break;
		    case LEFT:		m_trans.x -= m_moveSpeed * sin(m_rot.y + 90);
                            m_trans.z -= m_moveSpeed * sin(m_rot.y );
                            break;
		    case RIGHT:		m_trans.x += m_moveSpeed * sin(m_rot.y + 90);
                            m_trans.z += m_moveSpeed * sin(m_rot.y );
                            break;

		    case UP:		m_trans.y += m_moveSpeed;break;
		    case DOWN:		m_trans.y -= m_moveSpeed;break;

		    default:		std::cout << "Error: Undefined Label!" << std::endl;
                break;
	    }
    }

    void Camera::turn(CameraMovement dir)
    {
        switch (dir) 
        {
            case LEFT:  m_rot.y -= m_turnSpeed; break;
            case RIGHT: m_rot.y -= m_turnSpeed; break;

            default:    std::cout << "Error: Undefined Label!" << std::endl;
			    break;
        }

    }

    void Camera::apply()
    {
        /* Calc look at vector based on rotation state */
        m_l.x = m_initial.x + m_trans.x + sin (m_rot.y);
        m_l.z = -m_initial.z - m_trans.z - cos (m_rot.y );
        m_l.y = m_initial.y + m_trans.y + sin (m_rot.x);

        /* Clear matrix stack */
        glLoadIdentity () ;

        /* Apply transformation */
        gluLookAt (m_initial.x + m_trans.x, m_initial.y + m_trans.y, -m_initial.z
            -m_trans.z, m_l.x, m_l.y, m_l.z, m_up.x, m_up.y, m_up.z);


    }

    Camera::~Camera()
    {
        /*Nothing to do. Everything ist static */
    }
}