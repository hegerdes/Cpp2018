/**
 * @file PhysicalObject.cpp
 * @author Henrik Gerdes (hegerdes)
 * @brief 
 * @version 0.1
 * @date 2019-01-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "PhysicalObject.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

namespace asteroids
{

PhysicalObject::PhysicalObject(const float bound_radius):
    m_radius(bound_radius)
{
    m_renderable = std::make_shared<Sphere>(Vector3f(2,1,3),3);
}

void PhysicalObject::render()
{
    // Compute transformation matrix
	computeMatrix();
    // Push old transformation of the OpenGL matrix stack and
	// start rendering the bullet in according to the
	// internal transformation matrix
	glPushMatrix();
	glMultMatrixf(m_transformation.getData());
	//cout << m_transformation << endl;
	m_renderable->render();

	// Pop transformation matrix of this object
	// to restore the previous state of the OpenGL
	// matrix stack
	glPopMatrix();
}

bool PhysicalObject::collision(PhysicalObject::Ptr& p)
{
    return m_radius + p->m_radius >= p->m_position.dist(m_position);
}

}//asteroids