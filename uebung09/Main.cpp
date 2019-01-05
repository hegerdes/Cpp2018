/*
 *  Main.cpp
 *
 *  Created on: Nov. 04 2018
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#include "view/MainWindow.hpp"
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>


int main(int argc, char** argv)
{
    using namespace std::placeholders;
    asteroids::MainWindow mainWindow("Asteroids", "../models/", 1024, 768);
    //asteroids::MainWindow mainWindow("Asteroids", argv[1], 1024, 768);
    mainWindow.execute();


    // /**
    //  * @brief Test for task 1
    //  * 
    //  */
    // std::vector<int> v = {1,4,2,8,7};
    // //Output to cout
    // copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << std::endl;

    // auto it = std::bind(std::bind(std::equal_to<int>(),_1,0),
    //     std::bind(std::modulus<int>(),_1,2));

    // std::iterator<int> inter = std::remove_if(v.begin(), inter, it);

    
    // auto it = std::remove_if(v.begin(),v.end(), 
    //     std::bind(std::bind(std::equal_to<int>(),_1,0),
    //     std::bind(std::modulus<int>(),_1,2)));

    // auto it = std::remove_if(v.begin(),v.end(),
    //         std::bind(std::modulus<int>(),2,_1));

    // auto it = std::remove_if(v.begin(),v.end(), 
    //     std::bind1st(std::bind2nd(std::equal_to<int>(),0),
    //     std::bind2nd(std::modulus<int>(),2)));


    //Output to cout
    // copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << std::endl;


    return 0;
}
