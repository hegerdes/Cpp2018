/**
 *  @file Vector.hpp
 *
 *  @date 07.12.2018
 *  @author Henrik Gerdes
 * 
 */


#ifndef __Vector_HPP__
#define __Vector_HPP__

#include <iostream>
#include <cmath>

namespace asteroids
{


template<typename T, int L> class Vector
{
    public:
    Vector<T,L>();

    /**
     * @brief Construct a new Vector object
     * 
     * @param x 
     * @param y 
     * @param z 
     */
    Vector<T,L>(T x, T y ,T z = 0);

    /**
     * @brief Destroy the Vector object
     */
    ~Vector<T,L>();

	/**
	 * @brief   Normalize a Vector
	 */
    void normalize();

	/**
	 * @brief 	Assings a Vector to this object.
	 * 			Performs a copy of vec.
	 * 
	 * @param vec Vector to assign
	 */
	void operator= (const Vector& vec);
  
	/**
	 * @brief   Defines the vector addition
	 * @param vec vector
	 * @return vector
	 */
	Vector operator+ (const Vector& vec) const;

	/**
	 * @brief   Defines the vector subtraction
	 * @param vec vector
	 * @return vector
	 */
	Vector operator- (const Vector& vec) const;

	/**
	 * @brief   Construcs the scalar multiplication
	 * @param scale scalar
	 * @return vector
	 */
	Vector operator* (const T& scale) const;

	/**
	 * @brief   Defines the vector multiplication
	 * @param vec vector
	 * @return result (as T)
	 */
	T  operator* (const Vector& vec) const;

	/**
	 * @brief   Defines the access to a Vector value
	 * @param index wanted value
	 * @return vectorentry (as T)
	 */
	T operator[] (const int& index) const;
    
    /**
     * @brief   Defines the access to a Vector value
     * @param index wanted value
     * @return vectorentry (as T)
     */
    T& operator[] (const int& index);

	/**
	 * @brief   Defines the fast notation of vector addition
	 * @param v vector
	 */
	void operator+= (const Vector& v);

	/**
	 * @brief   Defines the fast notation of vector subtraction
	 * @param v vector
	 */
	void operator-= (const Vector& v);

	/**
	 * @brief Prints the Vector to stdout
	 */
	void printVector();

    private:
    ///To store the Vector-Values
    T m[L];

};

typedef Vector<float,3> Vector3f;
typedef Vector<int,2> Vector2i;


}//asteroids
#include "Vector.tcc"
#endif