#!/bin/bash

dir=build

if [ $# -eq 0 ]; then
    if [ ! -d "$dir" ]; then
        mkdir build
        cd build
        cmake ..
        make -j
    else
        cd "$dir"
        make -j
    fi
else
    if [ "$1" = "debug" ]; then
        if [ ! -d "$dir" ]; then
            mkdir build
        fi
        cd "$dir"
        cmake -DCMAKE_BUILD_TYPE=Debug ..
        echo makefile for Debug done
        make -j
    fi
    if [ "$1" = "clean" ]; then
        if [ ! -d "$dir" ]; then
            echo Nothing to clean
        fi
        rm "$dir" -r
    fi
    if [ "$1" = "launch" ]; then
        if [ ! -d "$dir" ]; then
        mkdir build
        cd build
        cmake ..
        make -j
    else
        cd "$dir"
        make -j
    fi
        ./asteroids ../models/arrow.ply
    fi
fi


