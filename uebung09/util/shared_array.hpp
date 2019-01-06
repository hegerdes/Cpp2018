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
	shared_array();

	/**
	 * @brief Construct a new shared array object
	 * 
	 * @param arr 
	 */
	shared_array(T* arr);

	operator T()
	{
		return T();
	}

    /**
	 * @brief	Indexed element (reading) access.
	 */
    T& operator[](const int index);


	/**
	 * @brief	Indexed element (reading) access.
	 */
    T operator[](const int index) const;

	// a lamda array deleter:
	struct Del {    
		void operator()(T* p) 
		{
			delete[] (p);
		}
	};
}; 

}; //asteroids

#include "shared_array.tcc"
#endif