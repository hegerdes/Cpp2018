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

#include "MainWindow.hpp"
#include "Matrix.hpp"

int main(int argc, char** argv)
{
    string buffer = "../models/arrow.ply";
    asteroids::MainWindow mainWindow("Asteroids", buffer, 1024, 768);
    //asteroids::MainWindow mainWindow("Asteroids", argv[1], 1024, 768);
    mainWindow.execute();
    
    
    
    
    // float test2[16] = { 1,2,3,4,
    //                     5,6,7,8,
    //                     9,10,11,12,
    //                     13,14,15,17};
 
    // asteroids::Matrix tm1(test2);
    // asteroids::Matrix tmp();
    // try
    // {
    //     tm1[7][8];
    // }catch(OutOfBoundsException e)
    // {
    //     std::cout << e.what() << " at " << e.getIndex() << std::endl; 
    // }
    // try
    // {
    //     tm1/0;
    // }
    // catch(DivisionByZeroException e)
    // {
    //     std::cout << e.what() << " in Funktion " << e.getFunktion() << std::endl;
    // }
    return 0;
}
