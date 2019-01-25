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

PhysicalObject::PhysicalObject(const Vector3f& pos, const float bound_radius):
    m_radius(bound_radius)
{
    m_position = pos;
}

void PhysicalObject::render()
{

}

bool PhysicalObject::collision(PhysicalObject::Ptr& p)
{
    return true;
}

}//asteroids