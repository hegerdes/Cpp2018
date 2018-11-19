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
#include "Camera.hpp"

#include <iostream>

int main(int argc, char** argv)
{

    if (argc == 2)
    {
    std::string buffer = argv[1];
    buffer = "../models/arrow.ply";
	asteroids::MainWindow* modelwindow = new asteroids::MainWindow("Model Render", buffer, 666,500);
    modelwindow->execute();
    delete modelwindow;

    }
    else
    {
        std::cout << "usage: asteroids <modelfile>" << std::endl;
    }
    return 0;
}
