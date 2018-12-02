#ifndef __OUTOFBOUNDSEXCEPTION_HPP__
#define __OUTOFBOUNDSEXCEPTION_HPP__

#include "BaseException.hpp"

class OutOfBoundsException: public BaseException
{
    int index;
    public:
    OutOfBoundsException(const char* _obj);
    OutOfBoundsException(const char* _obj, const int _index);
    inline int getIndex(){return index;};
    const char* getInfo();
};

#endif