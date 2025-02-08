#ifndef LOGEXCEPTION_H
#define LOGEXCEPTION_H

#include <exception>
#include <memory>

class LogException : public std::exception
{
public:
    LogException() {}
};

#endif // LOGEXCEPTION_H
