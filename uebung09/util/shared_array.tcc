#include "shared_array.hpp"

namespace asteroids
{

template<class T>
shared_array<T>::shared_array()
{

}

template<class T>
shared_array<T>::shared_array(T* arr):std::shared_ptr<T>(arr, [](T* p){})
{

}

template<class T>
T shared_array<T>::operator[](const int index) const
{
    return this->get()[index];
}

template<class T>
T& shared_array<T>::operator[](const int index)
{
    return this->get()[index];
}


}; //asteroids