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
#include "util/PathPlanner.hpp"
#include "math/Vector.hpp"

int main(int argc, char** argv)
{


    // asteroids::PathPlanner searchPath("../models/01.map");
    // searchPath.getPath(asteroids::Vector3f(0,0,0), "Akis", "Argent");
    
    // asteroids::MainWindow mainWindow("Asteroids", "../models/level.xml", "../models/01.map", "NewHope", "Akis", 1024, 768);
    // mainWindow.execute();

    if(argc != 5)
    {
        std::cout << "Usage: ./astroids <xml-File> <map-File> <startnode> <endnode>" << std::endl; 
    }
    else
    {
        asteroids::MainWindow mainWindow("Asteroids", argv[1], argv[2], argv[3], argv[4], 1024, 768);
    }

    return 0;
}
