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

int main(int argc, char** argv)
{
    string buffer = "../models/arrow.ply";
    asteroids::MainWindow mainWindow("Asteroids", buffer, 1024, 768);
    //asteroids::MainWindow mainWindow("Asteroids", argv[1], 1024, 768);
    mainWindow.execute();


    return 0;
}
