#ifndef LOGEXCEPTION_H
#define LOGEXCEPTION_H

#include <exception>
#include <memory>

class LogException : public std::exception
{
public:
    LogException();
};

typedef std::shared_ptr<LogException> LogExceptionPtr;
#endif // LOGEXCEPTION_H