/**
 * @file Vector.tcc
 * @author Henrik Gerdes
 * @brief   Template-Class for a Vector with Dimension between 2 and 3.
 *          Types must implement *  + -/ and =
 *  
 * @version 0.1
 * @date 2018-12-07
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "Vector.hpp"

namespace asteroids
{
    template<typename T, int L>Vector<T,L>::Vector()
    {
        static_assert(L<4 && L>1);
        for(int i = 0; i < L; i++)
        {
            m[i] = 0;
        }
    }
    
    template<typename T, int L>Vector<T,L>::Vector(T x, T y , T z)
    {
        static_assert(L<4 && L>1);

        m[0] = x;
        m[1] = y;

        if(L == 3)
        {
            m[2] = z;
        }
    }

    template<typename T, int L> void Vector<T,L>::normalize()
    {
        // Normalize the Vector3f
        T mag2 = 0;
        //For every Vector-Dimension
        for(int i = 0; i < L; i++)
        {
            mag2 += m[i] * m[i];
        }

        //Sholud do the samle as the old class
        if (fabs(mag2 - 1.0f) > 0.00001)
        {
            float mag = sqrt(mag2);
            for(int i = 0; i < L; i++)
            {
                m[i] /=mag;
            }
        }
    }

    template<typename T, int L> void Vector<T,L>::operator=(const Vector& vec)
    {
        for(int i = 0; i < L; i++)
        {
            m[i] = vec[i];
        }
    }

    template<typename T, int L> Vector<T,L> Vector<T,L>::operator+(const Vector& vec) const
    {
        T tmp[3] = {0};
        for(int i = 0; i < L; i++)
        {
            tmp[i] = m[i] + vec[i];
        }
        return Vector<T,L>(tmp[0], tmp[1], tmp[2]);

    }

    template<typename T, int L> void Vector<T,L>::operator+=(const Vector& vec)
    {
        *this = *this + vec;
    }

    template<typename T, int L> Vector<T,L> Vector<T,L>::operator-(const Vector& vec) const
    {
        T tmp[3] = {0};
        for(int i = 0; i < L; i++)
        {
            tmp[i] = this[i] - vec[i];
        }
        return Vector<T,L>(tmp[0], tmp[1], tmp[2]);

    }

    template<typename T, int L> void Vector<T,L>::operator-=(const Vector& vec)
    {
        *this = *this - vec;
    }

    template<typename T, int L> Vector<T,L> Vector<T,L>::operator*(const T& scale) const
    {
        return Vector<T,L>(m[0] * scale, m[1] * scale, m[2] * scale);
    }

    template<typename T, int L> T Vector<T,L>::operator*(const Vector& vec) const
    {
        T res = 0;
        for(int i = 0; i < L; i++)
        {
            res += m[i]*vec[i];
        }
        return res;
    }

    template<typename T, int L> T Vector<T,L>::operator[](const int& index)const
    {
        if(index >= L || index < 0)
        {
            throw std::invalid_argument("Außerhalb der Vector-Dimension");
        }
        else 
        {
            return m[index];
        }
    }

    template<typename T, int L> T& Vector<T,L>::operator[](const int& index)
    {
        if(index >= L || index < 0)
        {
            throw std::invalid_argument("Außerhalb der Vector-Dimension");
        }
        else 
        {
            return m[index];
        }
    }

    template<typename T, int L> void Vector<T,L>::printVector()
    {
        std::cout << "Vector-Daten: " << std::flush;
        for(int i = 0; i < L; i++)
        {
            std::cout << m[i] << " " << std::flush;
        }
        std::cout << std::endl;
    }

    template<typename T, int L>Vector<T,L>::~Vector()
    {
        //Do nothing
    }


}