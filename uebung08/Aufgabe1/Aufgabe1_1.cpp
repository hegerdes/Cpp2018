#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <iostream> 
#include "../math/Randomizer.hpp"


int somenumber()
{
    return (int)asteroids::Randomizer::instance()->getRandomNumber(0,100); 
}

int main(int argc, char const *argv[])
{
    //New Int-Vector
    std::vector<int> numVec(100);
    
    //Call a Function-Obj to fill Vector
    std::generate(numVec.begin(), numVec.end(),somenumber);

    //OutPutInterator
    std::ostream_iterator<int> out_it (std::cout,", ");
    
    //Use Outstream to stdcout
    std::copy ( numVec.begin(), numVec.end(), out_it );
    std::cout << std::endl;

    asteroids::Randomizer::instance()->getRandomNumber(0,100); 
    //(*getRandomNumber)(0,100)

    return 0;
}
