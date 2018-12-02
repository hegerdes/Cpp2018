#ifndef __DIVISIONBYZEROEXCEPTION_HPP__
#define __DIVISIONBYZEROEXCEPTION_HPP__

#include "BaseException.hpp"

class DivisionByZeroException: public BaseException
{
    const char* obj;
    public:
    DivisionByZeroException(const char* _obj);
    DivisionByZeroException(const char* _obj, const char* _inFunction);
    inline const char* getFunktion(){return obj;};
    const char* getInfo();
};

#endif