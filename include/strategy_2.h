#ifndef STRATEGY2_H
#define STRATEGY2_H

#include "icommandqueue.h"
#include "exceptionmanager.h"

class Strategy_2
{
    ExceptionManagerPtr m_exManager;
    ICommandQueuePtr    m_commandQueue;
    ICommandPtr         m_command;

public:
    Strategy_2(ICommandPtr command);
    void run();

};

#endif // STRATEGY1_H