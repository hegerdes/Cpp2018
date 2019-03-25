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

int main(int argc, char** argv)
{
    asteroids::MainWindow mainWindows("Asteroids", argv[1], 1024, 768);
    mainWindows.execute();

    //Das ist ein Test
    return 0;
}
