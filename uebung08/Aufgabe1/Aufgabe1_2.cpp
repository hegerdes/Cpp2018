#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <iostream> 
#include <string>
#include "../math/Randomizer.hpp"

//Save Randomizer instance
asteroids::Randomizer* raninst = asteroids::Randomizer::instance();

//Genarate a string by random numbers matching characters in ASCII
std::string someString()
{
    int size = (int)raninst->getRandomNumber(5,10);
    char a[size + 1];

    for(int i = 0; i < size; i++)
    {
        a[i] = (char)(int)raninst->getRandomNumber(65,90);
    }
    //Terminate c string
    a[size] = '\0';

    std::string str(a);
    return str;
}

int main(int argc, char const *argv[])
{
    ///New StringVector
    std::vector<std::string> strVec(100);

    ///Fill String
    std::generate(strVec.begin(), strVec.end(), someString);

    ///Sort String
    std::sort( strVec.begin(), strVec.end());

    //Print to std-out using a outstream interator
    std::ostream_iterator<std::string> out_it (std::cout,"\n");
    std::copy ( strVec.begin(), strVec.end(), out_it );
    std::cout << std::endl;
    
    return 0;
}
