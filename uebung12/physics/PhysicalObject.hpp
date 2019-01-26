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
#include "../rendering/Sphere.hpp"
#include "Transformable.hpp"


namespace asteroids
{

/**
 * @brief   Class to render particle effects
 */
class PhysicalObject : public Transformable, public Renderable
{
public:

    using Ptr = std::shared_ptr<PhysicalObject>; 

    /**
     * @brief Construct a new Physical Object object
     * 
     * @param position 
     * @param bound_radius 
     */
    PhysicalObject(const Vector3f& position, const float bound_radius);

    PhysicalObject() = delete;

    /**
     * @brief Destroy the Physical Object object
     * 
     */
    virtual ~PhysicalObject() = default;

    /**
     * @brief virtual render
     * 
     */
    virtual void render() override;

    /**
     * @brief Returns if a collison between two objects happen 
     * Gets distance between both positions and checks if distance
     * is smaller than the combind radius
     * 
     * @param p The other PhysicalObject
     * @return true If collision happend
     * @return false If not
     */
    bool collision(PhysicalObject::Ptr& p);


protected:

    //radius of the bounding ball
    float m_radius;

    //The renderable
    Renderable::Ptr m_renderable;

};

}//asteroids

#endif