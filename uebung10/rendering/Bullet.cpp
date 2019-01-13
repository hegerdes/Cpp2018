/**
 * @file Bullet.cpp
 * @author Henrik Gerdes (hegerdes)
 * @brief 
 * @version 0.1
 * @date 2019-01-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Bullet.hpp"

namespace asteroids
{

Bullet::Bullet(const Vector3f& fighter_position, const Vector3f fighter_axis):
    m_alive(true), m_flightAxis(fighter_axis), m_fighter_position(fighter_position), m_sphere(fighter_position,10)
    {
        //m_sphere = fighter_position;
    }

void Bullet::render()
{
    m_sphere.render();
}

void Bullet::run()
{
    
}


}//asteroids