/**
 *  @file Vector.hpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#ifndef __Vector_HPP__
#define __Vector_HPP__

#include <iostream>
#include <cmath>

namespace asteroids
{

/**
 * @brief   Vector representation with three floats for OpenGL
 *
 */
class Vector {

public:

	/**
	 * @brief   Construcs a default Vector object
	 */
	Vector();

	/**
	 * @brief   Construcs a Vector object with given values
	 * @param x x-value
	 * @param y y-value
	 * @param z z-value
	 */
	Vector(float x, float y, float z);

	/**
	 * @brief   Normalize a Vector
	 */
	void normalize();
  
	/**
	 * @brief   The three values of a vector
	 */
	float x, y, z;

	/**
	 * @brief	Adds two vectors and returns a new vector
	 * @param other	The vector to add
	 */
	Vector operator+(const Vector& other)const;

	/**
	 * @brief	Adds two vectors and returns this modifyed vector
	 * @param other	The vector to add
	 */
	Vector& operator+=(const Vector& other);

	/**
	 * @brief	Substracts two vectors and returns a new vector
	 * @param other	The vector to subtract
	 */
	Vector operator-(const Vector& other)const;

	/**
	 * @brief	Substracts two vectors and returns this modifyed vector
	 * @param other	The vector to substract
	 */
	Vector& operator-=(const Vector& other);

	/**
	 * @brief	Returns a new vector scalled by scale
	 * @param scale	The factor to sacle with
	 */
	Vector operator*(const float scale)const;

	/**
	 * @brief	Returns this vector scalled by scale
	 * @param scale	The factor to sacle with
	 */
	Vector& operator*=(const float scale);

	/**
	 * @brief	Returns a new vector scalled by scale
	 * @param scale	The factor to sacle with
	 */
	Vector operator/(const float scale)const;

	/**
	 * @brief	Returns this vector scalled by scale
	 * @param scale	The factor to sacle with
	 */
	Vector& operator/=(const float scale);

	/**
	 * @biref	Returns the number at index
	 */
	float operator[](const int& index) const;

	/**
	 * @brief	Rethrns the standard saclar in a 3d room;
	 */
	double scalar();


	/**
	 * @brief	Prints the vector to console
	 */
	void print();
};
    
} // namespace asteroids

#endif
