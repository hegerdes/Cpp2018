###############################################################################
# Declare the minimum cmake version required
###############################################################################
cmake_minimum_required(VERSION 3.0.2)

###############################################################################
# The name of out project
###############################################################################
project(CPP18_TASK01)
project(CPP18_TASK02)
project(CPP18_TASK03)

###############################################################################
# With cmake we can define additional compiler flags for different 
# configurations. CMAKE_CXX_FLAGS are for the default case. The debug config
# can be used to generate debug symbols for gdb. The release option uses
# special optimization flags
###############################################################################

set( CMAKE_CXX_FLAGS         "-O3 -Wall " )
set( CMAKE_CXX_FLAGS_RELEASE "-O3 -msse3 -Wno-deprecated-declarations -Wno-unused -Wcpp" )
set( CMAKE_CXX_FLAGS_DEBUG   "-g -Wall" )


###############################################################################
# Variable for the sources of the binary. In larger projects it is often a 
# good idea to use such variables because it is easy to add more source files
# and you can reuse it for several targets (maybe you want to build a library
# some day ;-)
###############################################################################

set(TASK1_SOURCES
    Aufgabe1_1.cpp
    ../math/Randomizer.cpp
)

set(TASK2_SOURCES
   Aufgabe1_2.cpp
   ../math/Randomizer.cpp
)

set(TASK3_SOURCES
    Aufgabe1_3.cpp  
)

###############################################################################
# The executable fpr our project
###############################################################################

add_executable(IntVector ${TASK1_SOURCES})
add_executable(StringVector ${TASK2_SOURCES})
add_executable(Sum ${TASK3_SOURCES})

###############################################################################
# External library dependencys
###############################################################################

