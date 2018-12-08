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
#include "Vector.hpp"


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


    //Test for VectorGen
    // asteroids::Vector<float,3> test1(4.0,5.4,7.3);
    // asteroids::Vector<float,3> test3(4.0,5.4,7.3);
    // asteroids::Vector<int,2> test4(4,5);
    // asteroids::Vector<int,2> test2(4,5);
    // test2 + test4;
    // test1 += test3;
    // test1.printVector();

    // std::cout << test1 * test3 << std::endl;



    return 0;
}
