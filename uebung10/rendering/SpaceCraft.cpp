/*
 *  SpaceCraft.cpp
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "SpaceCraft.hpp"
#include "Bullet.hpp"
#include <iterator>
#include <algorithm>
#include "io/TriangleMeshFactory.hpp"

namespace asteroids
{

SpaceCraft::SpaceCraft(const std::string &filename, const Vector3f& position, float movespeed, float rotatespeed)
    : m_movespeed(movespeed), m_rotatespeed(rotatespeed)
{
    m_mesh = TriangleMeshFactory::instance().getMesh(filename);
    if(m_mesh)
    {
        m_mesh->setPosition(position);
    }
}

void SpaceCraft::handleKeyInput(const Uint8* keyStates)
{
    if (keyStates[SDL_SCANCODE_UP])
    {
        m_mesh->rotate(TriangleMesh::YAW, m_rotatespeed);
    }
    if (keyStates[SDL_SCANCODE_DOWN])
    {
        m_mesh->rotate(TriangleMesh::YAW, -m_rotatespeed);
    }
    if (keyStates[SDL_SCANCODE_LEFT])
    {
        m_mesh->rotate(TriangleMesh::ROLL, m_rotatespeed);
    }
    if (keyStates[SDL_SCANCODE_RIGHT])
    {
        m_mesh->rotate(TriangleMesh::ROLL, -m_rotatespeed);
    }
    if (keyStates[SDL_SCANCODE_W])
    {
        m_mesh->move(TriangleMesh::ACCEL, -m_movespeed);
    }
    if (keyStates[SDL_SCANCODE_S])
    {
        m_mesh->move(TriangleMesh::ACCEL, m_movespeed);
    }
    if (keyStates[SDL_SCANCODE_A])
    {
        m_mesh->move(TriangleMesh::STRAFE, -m_movespeed);
    }
    if (keyStates[SDL_SCANCODE_D])
    {
        m_mesh->move(TriangleMesh::STRAFE, m_movespeed);
    }
    if (keyStates[SDL_SCANCODE_SPACE])
    {
        shoot();
    }
}

void SpaceCraft::render()
{
    m_mesh->render();

    // for(auto const &b:m_bullets)
    // {
    //     b->render();
    // }

    // auto it = remove_if(m_bullets.begin(), m_bullets.end(), [](Bullet::Ptr b)->bool{
    //     return !(b->isAlive());
    // });

    // m_bullets.erase(it,m_bullets.end());

    for(std::list<Bullet::Ptr>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    {
        if(it->get()->isAlive())
        {
            it->get()->render();
        }
        else
        {
            it = m_bullets.erase(it);
        }
    }
}

bool SpaceCraft::hasMesh() const
{
    return m_mesh != nullptr;
}

void SpaceCraft::shoot()
{
    Bullet::Ptr b(new Bullet(m_mesh->getPosition(),m_mesh->getxAxis() * -1.0));

    b->start();
    
    m_bullets.push_back(b);
}

SpaceCraft::~SpaceCraft()
{ 
}

} // namespace asteroids
