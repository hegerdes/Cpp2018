/**
 * @file PhysicalObject.hpp
 * @author Henrik Gerdes (hegerdes)
 * @brief 
 * @version 0.1
 * @date 2019-01-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include "../rendering/Renderable.hpp"
#include "Transformable.hpp"


namespace asteroids
{

/**
 * @brief   Class to render particle effects
 */
class PhysicalObject : public Renderable, Transformable
{
public:

};

}//asteroids

#endif