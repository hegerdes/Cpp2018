/*
 * Matrix.hpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Vector.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.141592654
#endif
using namespace std;

namespace asteroids{

/**
 * @brief	A 4x4 matrix class implementation for use with the provided
 * 			Vector types.
 */

class Matrix {
public:

	/**
	 * @brief 	Default constructor. Initializes a identity matrix.
	 */
    Matrix();

	/**
	 * @brief	Constructs a matrix from given axis and angle. Trys to
	 * 			avoid a gimbal lock.
	 */
    Matrix(Vector axis, float angle);
	
	/// Destructor
    ~Matrix();

    
	/**
	 * @brief	Returns the internal data array. Unsafe. Will probably
	 * 			removed in one of the next versions.
	 */
	float* getData() { return m; }

	/// TODO: Implement [] operator


private:

    /// Internal data array
	float m[16];
};



} // namespace asteroids
#endif /* MATRIX_H_ */
