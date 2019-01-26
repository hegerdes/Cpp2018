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

namespace asteroids
{

PhysicalObject::PhysicalObject(const float bound_radius):
    m_radius(bound_radius)
{
    m_renderable = std::make_shared<Sphere>(Vector3f(2,1,3),3);
}

void PhysicalObject::render()
{
    m_renderable->render();
}

bool PhysicalObject::collision(PhysicalObject::Ptr& p)
{
    if(m_radius + p->m_radius >= p->m_position.dist(m_position))
    {
        return true;
    }
    else
    {
        return false;
    }
}

}//asteroids