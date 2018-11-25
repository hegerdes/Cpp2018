/**
 *  @file Quaternion.hpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */



#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__

#include "Vector.hpp"

#include <iostream>
#include <cmath>

namespace asteroids
{

/**
 * @brief   Quaternion representation for OpenGL. Based on: 
 *          http://gpwiki.org/index.php/OpenGL:Tutorials:Using_Quaternions_to_represent_rotation
 *
 */
class Quaternion {

public:

	/**
	 * @brief   Construcs a default quaternion object
	 */
	Quaternion();

	/**
	 * @brief   Destructor
	 */
	~Quaternion();

	/**
	 * @brief   Construcs (with fromAxis()) a quaternion with a given Vector and an angle
	 * @param vec vector
	 * @param angle angle
	 */
	Quaternion(const Vector& vec, float angle);

	/**
	 * @brief   Constructs a quaternion with three given values and an angle
	 * @param x x-value
	 * @param y y-value
	 * @param z z-value
	 * @param w angle
	 */
	Quaternion(float x, float y, float z, float w);

	/**
	 * @brief   Constructs a quaternion with a given float-pointer and an angle
	 * @param vec vector(pointer)
	 * @param w angle
	 */
	Quaternion(float* vec, float w);

	/**
	 * @brief	Copy-constructor
	 * @param other The other quaterion
	 */
	Quaternion(const Quaternion& other);
  
	/**
	 * @brief   Calculates a quaternion with a given vector and an angle
	 * @param axis vector
	 * @param angle angle
	 */
	void fromAxis(const Vector& axis, float angle);

	/**
	 * @brief	Sets a quaternion to this;
	 * @param rq	The quaternion to set.
	 */
	Quaternion& operator=(const Quaternion &rq);

	/**
	 * @brief	Multiplicats two quaternion and retruns a
	 * 			new quaternion.
	 * @param rq	The quaternion to multiplicate with.
	 */
	Quaternion operator*(const Quaternion &rq) const;

	/**
	 * @brief	Multiplicats two quaternion and retruns this 
	 * 			multiplicated with rq.
	 * @param rq	The quaternion to multiplicate with.
	 */
	Quaternion& operator*=(const Quaternion &rq);

	/**
	 * @brief	Multiplicaes a quaternion with vector.
	 * 			Will return a new vector.
	 * @param vector	The vector to multiplicate with.
	 */
    Vector operator*(const Vector &vector) const;

	/**
	 * @brief	Multiplicaes a quaternion with vector.
	 * 			Will override vector.
	 * @param vector	The vector to multiplicate with.
	 */
	Vector& operator*=(Vector &vector) const;

	/**
	 * @brief	Prints the quaternion to stdout;
	 */
	void print();
 
	/// TODO: ADD required operator signatures.
  
private:

	/**
	 * @brief   Value of angle, x, y and z
	 */
	float w, x, y, z;
};
    
} // namespace asteroids

#endif

