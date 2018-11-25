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
	 * @brief	Constructs a matrix out of a 16 float array
	 */
	Matrix(float* array);

	/**
	 * @brief	Constructs a matrix from given axis and angle. Trys to
	 * 			avoid a gimbal lock.
	 */
    Matrix(Vector axis, float angle);

	/**
	 * @brief 	Copy constructor
	 * @param other	The Matrix to copy
	 * 
	 */
	Matrix(const Matrix &other);
	
	/// Destructor
    ~Matrix();

	/**
	 * @brief	Print matrix
	 * 
	 */
	void printMatrix();

    
	/**
	 * @brief	Returns the internal data array. Unsafe. Will probably
	 * 			removed in one of the next versions.
	 */
	float* getData() { return m; }

	/**
	 * @brief	Returns the determinate of the matrix
	 * 
	 */
	int determinate();

	bool isInitializedCorrect(){return initializedOk;};

	/**
	 * @brief	Assigns the other Matrix to this;
	 * @return	An matrix with the values of other
	 */
	Matrix& operator=(const Matrix& other);

	/**
	 * @brief	Returns the product of two matrix's. Will create a
	 * 			new matrix and will not change m or this.
	 * @param other	Matrix to multiplicate with
	 */
	Matrix operator*(const Matrix& other) const;

	/**
	 * @brief	Retrns the product of this matrix and other.
	 * @param other	The matrix to multiplicate with.
	 */
	Matrix& operator*=(const Matrix& other);

	/**
	 * @brief	Returns the Sum of two matrix's. Will create a
	 * 			new matrix and will not change m or this.
	 * @param other The matrix to add.
	 */
	Matrix operator+(const Matrix& other) const;

	/**
	 * @brief	Returns the Sum of two matrix's. Will override
	 * 			this matrix.
	 * @param other The matrix to add.
	 */
	Matrix& operator+=(const Matrix& other);

	/**
	 * @brief	Returns the difference of two matrix's. Will create a
	 * 			new matrix and will not change m or this.
	 * @param other The matrix to substract.
	 */
	Matrix operator-(const Matrix& other) const;

	/**
	 * @brief	Returns the difference of two matrix's. Will override
	 * 			this matrix.
	 * @param other The matrix to substract.
	 */
	Matrix& operator-=(const Matrix& other);

	/**
	 * @brief	Returns a new matrix that will be scalled by scal. 
	 * 			Will not override the original matrix.
	 * @param scal The float to scale with.
	 */
	Matrix operator*(const float scal) const;

	/**
	 * @brief	Returns a matrix that will be scalled by scal. 
	 * 			Will override the original (this) matrix.
	 * @param scal The float to scale with.
	 */
	Matrix& operator*=(const float scal);

	/**
	 * @brief	Returns a new matrix that will be scalled by scal. 
	 * 			Will not override the original matrix.
	 * @param scal The float to scale with.
	 */
	Matrix operator/(const float scal) const;

	/**
	 * @brief	Returns a matrix that will be scalled by scal. 
	 * 			Will override the original (this) matrix.
	 * @param scal The float to scale with.
	 */
	Matrix& operator/=(const float scal);

	/**
	 * @brief	Returns a Vector. Will multiplicate this matrix with
	 * 			vec. Will not override the original (this) matrix
	 * 			or the original Vector vec.
	 * @param vec The Vector to multiplicate with.
	 */
	Vector operator*(const Vector& vec)const;

	/**
	 * @brief	Returns a Vector. Will multiplicate this matrix with
	 * 			vec. Will not override the original (this) matrix
	 * 			but will override vec.
	 * @param vec The Vector to multiplicate with.
	 */
	Vector& operator*=(Vector& vec) const;

	/**
	 * @bief	Retrns the address of the index i in the matrix
	 */
	float& operator[](const int i);


	/// TODO: Implement [] operator


private:

	///Size of array
	const int MatrixSize = 16;

    /// Internal data array
	float m[16];

	bool initializedOk = false;
};



} // namespace asteroids
#endif /* MATRIX_H_ */
