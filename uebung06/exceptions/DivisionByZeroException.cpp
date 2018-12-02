#include "DivisionByZeroException.hpp"

DivisionByZeroException::DivisionByZeroException(const char* _obj):BaseException(_obj)
{
}

DivisionByZeroException::DivisionByZeroException(const char* _obj, const char* _inFunction):
    BaseException(_obj),
    obj(_inFunction)
{   
}

const char* DivisionByZeroException::getInfo()
{
    std::ostringstream str;
    str << "Es wurde versucht durch 0 zu Teilen.\nFehlermeldung: " << msg 
        << " Fehler in in Funktion " << obj << " aufgetreten.";
    return str.str().c_str();
}