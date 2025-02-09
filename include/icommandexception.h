#ifndef ICOMMANDEXCEPTION_H
#define ICOMMANDEXCEPTION_H

#include <memory>
#include "icommand.h"
#include "icommandexception.h"

class ICommandException 
{
public:
    virtual ~ICommandException() {}
    virtual ICommandPtr getCommand() = 0;
};
#endif // ICOMMANDEXCEPTION_H
