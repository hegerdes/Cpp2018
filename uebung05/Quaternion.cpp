/**
 *  @file Quaternion.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "Quaternion.hpp"

namespace asteroids
{

Quaternion::Quaternion()
{
	// Default Quaternion
	x = 1.0;
	y = 0.0;
	z = 0.0;
	w = 0.0; 
}

Quaternion::~Quaternion()
{
	// Do nothing
}

Quaternion::Quaternion(const Vector& vec, float angle)
{
	// Calculate the quaternion
	fromAxis(vec, angle);
}

Quaternion::Quaternion(float _x, float _y, float _z, float _angle)
{
	// Set the values
	x = _x;
	y = _y;
	z = _z;
	w = _angle;
}

Quaternion::Quaternion(float* vec, float _w)
{
	// Set the values
	x = vec[0];
	y = vec[1];
	z = vec[2];
	w = _w;
}

Quaternion::Quaternion(const Quaternion& other)
{
	w = other.w;
	x = other.x;
	y = other.y;
	z = other.z;
}

void Quaternion::fromAxis(const Vector& axis, float angle)
{
	float sinAngle;
	angle *= 0.5f;

	// Create a copy of the given vector and normalize the new vector
	Vector vn(axis.x, axis.y, axis.z);
	vn.normalize();
 
	// Calculate the sinus of the given angle
	sinAngle = sin(angle);
 
	// Get the quaternion
	x = (vn.x * sinAngle);
	y = (vn.y * sinAngle);
	z = (vn.z * sinAngle);
	w = cos(angle);
}

Quaternion& Quaternion::operator=(const Quaternion &other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;

	return *this;
}

Quaternion Quaternion::operator*(const Quaternion& rq)const
{
	return Quaternion(	w * rq.x + x * rq.w + y * rq.z - z * rq.y, 
						w * rq.y + y * rq.w + z * rq.x - x * rq.z, 
						w * rq.z + z * rq.w + x * rq.y - y * rq.x, 
						w * rq.w - x * rq.x - y * rq.y - z * rq.z);
}

Quaternion& Quaternion::operator*=(const Quaternion& rq)
{
	*this = *this * rq;
	return *this;
}

Vector Quaternion::operator* (const Vector& vector) const 
{ 
	Vector vn(vector); 
	vn.normalize(); 
	Quaternion vecQuat, resQuat; 
	vecQuat.x = vn.x; 
	vecQuat.y = vn.y; 
	vecQuat.z = vn.z; 
	vecQuat.w = 0.0f; 
	
	resQuat = vecQuat * Quaternion(-x, -y, -z, w); 
	resQuat = *this * resQuat; 
	return (Vector(resQuat.x, resQuat.y, resQuat.z)); 
}

void Quaternion::print()
{
	std::cout << "(" << this->x << ", " << this->y << ", " << this->z 
		<< ", " << this->w << ")" << std::endl;
}

Vector& Quaternion::operator*=(Vector& vector) const
{
	vector = *this * vector;
	return vector;
}

    
}
