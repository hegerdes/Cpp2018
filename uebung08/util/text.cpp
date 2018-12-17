#include "List.hpp"
#include <iostream>
#include "../math/Vector.hpp"

int main(int argc, char const *argv[])
{
    
    asteroids::List<asteroids::Vector3f> test;
    test.push_back(5);
    test.push_back(8);
    test.push_back(3);
    test.push_back(4);

    for(asteroids::Vector3f &a : test)
    {
        a.printVector();
    }


    return 0;
}
