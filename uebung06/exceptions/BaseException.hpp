#ifndef __BASEEXCEPTION_HPP__
#define __BASEEXCEPTION_HPP__

#include <stdexcept>
#include <sstream>

class BaseException: public std::exception
{
    public:
    BaseException();
    BaseException(const char* _msg);
    inline const char* what(){return msg;};
    ~BaseException() noexcept;


    protected:
    const char* msg = "Es ist ein Feher aufgetreten!";

};
#endif