#ifndef STRATEGY1_H
#define STRATEGY1_H

#include "icommandqueue.h"
#include "exceptionmanager.h"

class Strategy_1
{
    ExceptionManagerPtr m_exManager;
    ICommandQueuePtr    m_commandQueue;
    ICommandPtr         m_command;

public:
    Strategy_1(ICommandPtr command);
    void run();

};

#endif // STRATEGY1_H