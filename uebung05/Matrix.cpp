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
}
Matrix::Matrix(Vector axis, float angle)
{

}

void Matrix::printMatrix(){
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



Matrix::~Matrix()
{
    /* if(m)
    {
        delete m;
    } */
}


} // namespace asteroids

