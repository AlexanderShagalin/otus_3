#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <list>
#include "icommand.h"

class CommandQueue
{
    std::list<ICommandPtr> m_commandList;
public:
    CommandQueue(std::list<ICommandPtr> commandList = {});
    void start();
};

#endif // COMMANDQUEUE_H
