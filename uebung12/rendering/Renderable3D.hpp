/*
 *  Renderable3D.hpp
 *
 *  Created on: Nov. 25 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#ifndef __RENDERABLE3D_HPP__
#define __RENDERABLE3D_HPP__

#include "Renderable.hpp"
#include "math/Matrix.hpp"
#include "math/Quaternion.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

namespace asteroids
{
/**
 * @brief A class to represent renderable objects in 3D space.
 * 
 */
class Renderable3D : public Renderable 
{
public:
    enum MoveTransform {FORWARD, BACKWARD, STRAFE_LEFT, STRAFE_RIGHT, LIFT_UP, LIFT_DOWN};
    enum RotationTransfrom{YAW_LEFT, YAW_RIGHT, PITCH_LEFT, PITCH_RIGHT, ROLL_LEFT, ROLL_RIGHT};

    Renderable3D();
    virtual ~Renderable3D() = default;

    /**
     * @brief   Rotates a triangle mesh at the given axis with the given speed
     * @param axis axis to rotate
     * @param speed speed of rotation
     */
    void rotate(RotationTransfrom axis, float speed);

    /// Performs the given rotation
    void rotate(RotationTransfrom axis);

    /**
     * @brief   Moves a triangle mesh at the given axis with the given speed
     * @param axis axis to move
     * @param speed speed of movement
     */
    virtual void move(MoveTransform axis, float speed);

    /// Performs the giving move action
    virtual void move(MoveTransform axis);

    /// Moves along the current direction
    virtual void move();

    virtual void render() = 0;

    /**
     * @brief Sets a new flight direction
     * @param dir   The new direction
     */
    void setDirection(Vector<float> dir)
    {
        m_direction = dir;
    }


    /**
     * @brief Return the current flight direction
     */
    Vector<float> getDirection()
    {
       return m_direction;
    }


    /**
     * @brief gives the current position
     * @return the current position
     */
    virtual Vector<float> getPosition()
    {
       return m_position;
    }

    /**
     * @brief set a new position
     * @param pos the new position
     */
    virtual void setPosition(Vector<float> pos)
    {
        m_position = pos;
    }

    /**
     * @brief gives the current speed
     * @return the current speed
     */
    virtual float getSpeed()
    {
        return m_speed;
    }

    /**
     * @brief set a new speed
     * @param s the new speed
     */
    virtual void setSpeed(float s)
    {
        m_speed = s;
    }

    /**
     * @brief   Returns the orientation of the x in the global coordinate system
     */
    Vector<float> getXAxis() { return m_xAxis;}

    /**
     * @brief   Returns the orientation of the y in the global coordinate system
     */
    Vector<float> getYAxis() { return m_yAxis;}

    /**
     * @brief   Returns the orientation of the z in the global coordinate system
     */
    Vector<float> getZAxis() { return m_zAxis;}

    protected:

    /**
     * @brief   Computes the 4x4 transformation matrix of this object (needed for OpenGL)
     */
    void computeMatrix();

    /**
     * @brief   The transformation matrix for this object
     */
    Matrix   m_transformation;

    /**
     * @brief   The current orientation of the x axis
     */
    Vector<float>    m_xAxis;

    /**
     * @brief   The current orientation of the y axis
     */
    Vector<float>    m_yAxis;

    /**
     * @brief   The current orientation of the z axis
     */
    Vector<float>    m_zAxis;


    /**
     * @brief   The current position of the mesh object
     */
    Vector<float>    m_position;

    /**
     * @brief   A quaternion representing the current rotation
     */
    Quaternion  m_rotation;


    /**
     * @brief   The current moving direction
     */
    Vector<float>   m_direction;

    /**
     * @brief   The current moving speed
     */
    float           m_speed;

    float           m_rotationSpeed;
};

} // asteroids


#endif