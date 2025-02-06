#ifndef IEXCEPTIONHANDLER_H
#define IEXCEPTIONHANDLER_H

#include <exception>
#include <memory>

class IExceptionHandler
{
public:
    virtual ~IExceptionHandler(){}
    virtual void handle(std::exception &e) = 0;
};

typedef std::shared_ptr<IExceptionHandler> IExceptionHandlerPtr;
#endif // IEXCEPTIONHANDLER_H