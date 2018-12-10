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

	/// Internal proxy class to implement safe index 
	/// access with boundary checking
	class MatrixProxy
	{
	public:
	    /// Creates a new proxy objects that wraps the 
	    /// given pointer
	    MatrixProxy(float* chunk) : m_ptr(chunk) {}

	    /// Index operator access
	    float& operator[](const int& index);
	
	private:

	    /// Pointer to the accessed chunk
	    float*	m_ptr;
	};

	/**
	 * @brief 	Default constructor. Initializes a identity matrix.
	 */
	Matrix();

	/**
	 * @brief	Initializes a matrix wit the given data array. Ensure
	 * 			that the array has exactly 16 fields.
	 */
	Matrix(float* matrix);
	/**
	 * @brief 	Copy constructor.
	 */
	Matrix(const Matrix& other);
    
	/**
	 * @brief	Constructs a matrix from given axis and angle. Trys to
	 * 			avoid a gimbal lock.
	 */
	Matrix(const Vector3f& axis, float angle);
	
	Matrix(const Vector3f &position, const Vector3f &angles);

    
	~Matrix();

	/**
	 * @brief	Scales the matrix elemnts by the given factor
	 */
	
	Matrix operator*(const float &scale) const;
	/**
	 * @brief	Matrix-Matrix multiplication. Returns the new
	 * 			matrix
	 */
	
	Matrix operator*(const Matrix &other) const;
	/**
	 * @brief 	Matrix addition operator. Returns a new matrix
	 *
	 */
	
	Matrix operator+(const Matrix &other) const;
	/**
	 * @brief 	Matrix addition operator
	 */
	
	Matrix operator+=(const Matrix &other);
    
	/**
	 * @brief	Matrix-Matrix multiplication (array based). Mainly
	 * 			implemented for compatibility with other math libs.
	 * 			ensure that the used array has at least 16 elements
	 * 			to avoid memory access violations.
	 */
	
	Matrix operator*(const float* &other) const;
	/**
	 * @brief	Multiplication of Matrix and Vector types
	 */
	
	Vector3f operator*(const Vector3f &v) const;
    
	/**
	 * @brief	Sets the given index of the Matrix's data field
	 * 			to the provided value.
	 *
	 * @param	i		Field index of the matrix
	 * @param	value	new value
	 */
	void set(const int& i, const float& value);

	/**
	 * @brief	Transposes the current matrix
	 */
	void transpose();
    
	/**
	 * @brief	Computes an Euler representation (x, y, z) plus three
	 * 			rotation values in rad. Rotations are with respect to
	 * 			the x, y, z axes.
	 */
	void toPostionAngle(float pose[6]);
 

	/**
	 * @brief	Matrix scaling with self assignment.
	 */
	void operator*=(const float& scale);
    
	/**
	 * @brief 	Matrix-Matrix multiplication with self assigment.
	 */
	void operator*=(const Matrix& other);
    
	/**
	 * @brief	Matrix-Matrix multiplication (array based). See \ref{operator*}.
	 */
	void operator*=(const float* other);
    
	/**
	 * @brief	Returns the internal data array. Unsafe. Will probably
	 * 			removed in one of the next versions.
	 */
	float* getData();

	/**
	 * @brief	Returns the element at the given index.
	 */
	float at(const int& i) const;


    
	/**
	 * @brief   Returns the matrix's determinant
	 */
	float det();
    
	/** 
	 * @brief   Inverts the matrix. Success is true if operation was successful
	 */
	Matrix inv(bool& success);

	/// Assignment operator
	Matrix& operator=(const Matrix& other);

	/// Index operator
	MatrixProxy operator[](const int& index);

	/// Index operator (allows reading values from internal linear storage)
	float operator[](const int& index) const;
	
    private:

	/**
	 * @brief   Returns a sub matrix without row \ref i and column \ref j.
	 */
	void submat(float* submat, const int& i, const int& j);
    
	/**
	 * @brief    Calculates the determinant of a 3x3 matrix
	 *
	 * @param    M  input 3x3 matrix
	 * @return   determinant of input matrix
	 */
	float det3( const float *M );
    
    
	/// Internal data array
	float m[16];
    };

/**
 * @brief Output operator for matrices.
 */

    inline ostream& operator<<(ostream& os, Matrix& matrix){
	os << "Matrix:" << endl;
	os << fixed;
	for(int i = 0; i < 4; i++)
	{
	    for(int j = 0; j < 4; j++)
	    {
		os << setprecision(4) << matrix[i][j] << " ";
	    }
	    os << endl;
	}
	os << endl;
	return os;
    }


} // namespace asteroids
#endif /* MATRIX_H_ */
