/**
 *  @file Vector.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "Vector.hpp"

namespace asteroids {
    
Vector::Vector()
{
	// Default values
	x = y = z = 0.0;
}


Vector::Vector(float _x, float _y, float _z)
{
	// Set the given values
	x = _x;
	y = _y;
	z = _z; 
}

void Vector::normalize()
{
	// Normalize the vector
	float mag2 = x * x + y * y + z * z;
	if (fabs(mag2 - 1.0f) > 0.00001)
	{
		float mag = sqrt(mag2);
		x /= mag;
		y /= mag;
		z /= mag;
	}
}

Vector Vector::operator+(const Vector& other)const
{
	Vector tmp;
	tmp.x = this->x + other.x;
	tmp.y = this->y + other.y;
	tmp.z = this->z + other.z;
	
	return tmp;
}

Vector& Vector::operator+=(const Vector& other)
{
	*this = *this + other;
	return *this;
}

Vector Vector::operator-(const Vector& other)const
{
	Vector tmp;
	tmp.x = this->x - other.x;
	tmp.y = this->y - other.y;
	tmp.z = this->z - other.z;
	
	return tmp;
}

Vector& Vector::operator-=(const Vector& other)
{
	*this = *this - other;
	return *this;
}

Vector Vector::operator*(const float scale)const
{
	Vector tmp;
	tmp.x = this->x * scale;
	tmp.y = this->y * scale;
	tmp.z = this->z * scale;

	return tmp;
}

Vector& Vector::operator*=(const float scale)
{
	*this = *this * scale;
	return *this;
}

Vector Vector::operator/(const float scale)const
{
	return *this * (1/scale);
}

Vector& Vector::operator/=(const float scale)
{
	*this = *this / scale;
	return *this;
}

float Vector::operator[](const int& index) const
{
	if(index >= 0 && index<4)
	{
		if(index == 0)
		{
			return x;
		}
		if(index == 1)
		{
			return y;
		}
		if(index == 2)
		{
			return z;
		}
	}
	std::cerr << "Out of Vector bounds << " << std::endl;
	return 0;
}

double Vector::scalar()
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
void Vector::print()
{
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}


    
} // namespace asteroids
