
/*
 *  PhysicsEngine.cpp
 *
 *  @date 19.01.2019
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2019 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */


#include "PhysicsEngine.hpp"

#include <iostream>
using namespace std;

namespace asteroids
{


void PhysicsEngine::addDestroyable(std::shared_ptr<PhysicalObject>& obj)
{
    // Add the object (asteroid) to the list of active objects
    m_objects.push_back(obj);
}

void PhysicsEngine::addBullet(Bullet::Ptr& bullet)
{
    // Add an bullet to the list of active bullets
    m_bullets.push_back(bullet);
}

void PhysicsEngine::process()
{
    // Iterate over all bullets und check wether they
    // collide with one of the active physical objects
    // If they collide, remove the bullet and object-

    std::list<Bullet::Ptr>::iterator it_b;
    std::list<std::shared_ptr<PhysicalObject>>::iterator it_m;

    for(it_b = m_bullets.begin(); it_b != m_bullets.end(); ++it_b)
    {
        for(it_m = m_objects.begin(); it_m != m_objects.end(); ++it_m)
        {
            if((*it_b)->collision(*it_m))
            {
                m_bullets.erase(it_b);
                m_objects.erase(it_m);
            }
        }
    }
    

}

void PhysicsEngine::render()
{
   // Render all objects and bullets-

    std::list<Bullet::Ptr>::iterator it_b;
    std::list<std::shared_ptr<PhysicalObject>>::iterator it_m;

    for(it_b = m_bullets.begin(); it_b != m_bullets.end(); ++it_b)
    {
        (*it_b)->render();
    }
    for(it_m = m_objects.begin(); it_m != m_objects.end(); ++it_m)
    {
        (*it_m)->render();
    }


}

} /* namespace asteroids */
