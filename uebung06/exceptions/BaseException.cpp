#include "BaseException.hpp"

BaseException::BaseException(const char* _msg):
    std::exception(),
    msg(_msg)
{
}

BaseException::~BaseException(){}