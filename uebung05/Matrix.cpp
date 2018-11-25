/*
 * Matrix.cpp
 *
 *  @date 18.11.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "Matrix.hpp"

namespace asteroids
{

Matrix::Matrix()
{
    for(int i = 0; i < MatrixSize; i++) 
    {
        m[i] = 0;
    }
    m[0] = m[5] = m[10] = m[15] = 1;

    initializedOk = true;
}
Matrix::Matrix(Vector axis, float angle)
{
    if(fabs(angle)<0.0001)
    {
        
    }
}

Matrix::Matrix(float* array)
{
    for(int i = 0; i < MatrixSize; i++)
    {
        m[i] = array[i];
    }

    initializedOk =  true;
}

Matrix::Matrix(const Matrix &other)
{
    for(int i = 0; i < MatrixSize; i++)
    {
        m[i] = other.m[i];
    }
    initializedOk = true;
}

int Matrix::determinate()
{
    return 0;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    for(int i = 0; i < MatrixSize; i++)
    {
        this->m[i] = other.m[i];
    }

    return *this;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix tmp;
    for(int i = 0; i < 16; i++) tmp.m[i] = 0;
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 4; j ++)
        {
            for (int k = 0; k < 4; k ++)
            {
                tmp.m[i * 4 + j] += this ->m[i * 4 + k] * other.m[k * 4 + j];
            }
        }
    }
    return tmp;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    *this = *this * other;
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix tmp;
    for(int i = 0; i < MatrixSize; i++)
    {
        tmp.m[i] = this->m[i] + other.m[i];
    }

    return tmp;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    *this = *this + other;
    return *this;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    Matrix tmp;
    for(int i = 0; i < MatrixSize; i++)
    {
        tmp.m[i] = this->m[i] - other.m[i];
    }

    return tmp;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    *this = *this - other;
    return *this;
}

Matrix Matrix::operator*(const float scal) const
{
    Matrix tmp;
    for(int i = 0; i < MatrixSize; i++)
    {
        tmp.m[i] = this->m[i] * scal;
    }
    return tmp;
}

Matrix& Matrix::operator*=(const float scal)
{
    *this = *this * scal;
    return *this;
}

Matrix Matrix::operator/(const float scal) const
{
    return *this * (1/scal);
}

Matrix& Matrix::operator/=(const float scal)
{
    *this = *this / scal;
    return *this;
}

Vector Matrix::operator*(const Vector& vec)const
{
    Vector tmp;
    float val[4];
    for(int i = 0; i < 4; i++)
    {
        val[i] = vec.x * this->m[i * 4] + vec.y * this->m[i*4 + 1] + vec.z
            * this->m[i*4 + 2] + 1 * this->m[i*4 + 3]; 
    }
    tmp.x = val[0];
    tmp.y = val[1];
    tmp.z = val[2];
    return tmp;
}



Vector& Matrix::operator*=(Vector& vec)const
{
    vec = *this * vec;
    return vec;
}

float& Matrix::operator[](const int index)
{
    /*Fuer [][] brauchte man eine proxyklasse*/
    if(index >= 0 && index < 4)
    {
        return this->m[4*index];    
    }
    
    cout << "Error, out of Matrix bounds" << endl;
    return m[0];
}

void Matrix::printMatrix()
{
    int i;
    for(i = 0; i < MatrixSize; i++)
    {
        if(i%4==0)
        {
            cout << endl;
        }
        cout << m[i] << " ";
    }
    cout << endl;
}



Matrix::~Matrix(){}


} // namespace asteroids

