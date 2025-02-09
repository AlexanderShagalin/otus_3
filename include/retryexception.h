#ifndef RETRYEXCEPTION_H
#define RETRYEXCEPTION_H

#include <exception>
#include <memory>
#include "icommand.h"

class RetryException : public std::exception
{
public:
    RetryException() {}
};

#endif // RETRYEXCEPTION_H
