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
    m_alive(true), m_flightAxis(fighter_axis), m_fighter_position(fighter_position), 
    m_sphere(fighter_position,10)
    {
        //m_sphere = fighter_position;
    }

void Bullet::render()
{
    m_sphere.render();
}

void Bullet::run()
{

    int i = 0;
    // Modify the bullet's position until the lifetime is over
	while(i < Bullet::m_lifetime){

        //m_sphere.move(Renderable3D::ACCEL, 5);
        m_sphere.setPosition(m_sphere.getPosition() + m_flightAxis);
		
		i++;
		std::this_thread::sleep_for(std::chrono::microseconds(1000));
	}
	m_alive = false;
    
}

void Bullet::start()
{
    m_thread = std::thread(&Bullet::run, this);
}

void Bullet::stop()
{
    m_thread.join();
}

Bullet::~Bullet()
{
    //stop();
}


}//asteroids