#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <list>
#include "icommand.h"
#include "exceptionmanager.h"

class CommandQueue
{
    ExceptionManagerPtr m_exManager;
    std::list<ICommandPtr> m_commandList;
public:
    CommandQueue(ExceptionManagerPtr exManager, std::list<ICommandPtr> commandList = {});
    void push_back(ICommandPtr command);
    void start();
};

#endif // COMMANDQUEUE_H
