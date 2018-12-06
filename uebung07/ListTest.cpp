/**
 * @file ListTest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "List.hpp"


/**
 * @brief 
 * 
 * @param x 
 */
void print_ints(int& x)
{
    std::cout << "Zahl in Liste: " << x << std::endl;
}

int main(int argc, char** argv)
{
    ///Creates a new List
    asteroids::List<int> IntList;

    ///Put some numbers in
    for(int i = 0; i < 10; i++)
    {
        IntList.insert(i);
    }
    

    void (*pointer)(int&);
    pointer = &print_ints;

    ///Do something with every emlement
    IntList.for_each(pointer);



    return 0;
}
