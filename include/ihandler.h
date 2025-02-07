#ifndef IHANDLER_H
#define IHANDLER_H

#include <memory>

class IHandler
{
public:
    virtual ~IHandler(){}
    virtual void handle() = 0;
};

typedef std::shared_ptr<IHandler> IHandlerPtr;
#endif // IHANDLER_H