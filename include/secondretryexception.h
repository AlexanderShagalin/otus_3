#ifndef SECONDRETRYEXCEPTION_H
#define SECONDRETRYEXCEPTION_H

#include <exception>
#include <memory>

class SecondRetryException : public std::exception
{
public:
    SecondRetryException() {}
};

#endif // RETRYEXCEPTION_H
