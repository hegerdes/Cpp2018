#ifndef SHARED_ARRAY_HPP
#define SHARED_ARRAY_HPP

#include <memory>

namespace asteroids
{

template<typename T> class shared_array : public std::shared_ptr<T>
{
    public:
	/**
	 * @brief Construct a new shared array object
	 * 
	 */
	shared_array():std::shared_ptr<T>()
	{

	}

	/**
	 * @brief Construct a new shared array object
	 * 
	 * @param arr 
	 */
	shared_array(T* arr):std::shared_ptr<T>(arr, [](T* p){})
	{

	}

	operator T()
	{
		return T();
	}

    /**
	 * @brief	Indexed element (reading) access.
	 */
    T& operator[](const int index)
	{
		return this->get()[index];
	}

	/**
	 * @brief	Indexed element (reading) access.
	 */
    T operator[](const int index) const
	{
		return this->get()[index];
	}

	// a lamda array deleter:
	//template <typename T>
	struct Del {    
		void operator()(T* p) 
		{
			delete[] (p);
		}
	};
}; 

}; //asteroids

//#include "shared_array.tcc"
#endif