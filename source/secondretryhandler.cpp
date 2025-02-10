#include "stdio.h"

#include "secondretryhandler.h"
#include "secondretrycommand.h"

SecondRetryHandler::SecondRetryHandler(ICommandQueuePtr commandQueue) : IHandler()
{
    m_commandQueue = commandQueue;
}

void SecondRetryHandler::handle(ICommandPtr command)
{
    printf("SecondRetryHandler handle\n");
    if(m_commandQueue && command)
        m_commandQueue->push_back(std::make_shared<SecondRetryCommand>(command));
}
