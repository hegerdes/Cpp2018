#include "OutOfBoundsException.hpp"

OutOfBoundsException::OutOfBoundsException(const char* _obj):BaseException(_obj)
{
}

OutOfBoundsException::OutOfBoundsException(const char* _obj, const int _index):
    BaseException(_obj),
    index(_index)
{   
}

const char* OutOfBoundsException::getInfo()
{
    std::ostringstream str;
    str << "Es ist ein Dimensionsfehler aufgetreten.\nFehlermeldung: " << msg 
        << " at Index: " << index;
    return str.str().c_str();
}