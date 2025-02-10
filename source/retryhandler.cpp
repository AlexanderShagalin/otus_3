#include "stdio.h"

#include "retryhandler.h"
#include "retrycommand.h"

RetryHandler::RetryHandler(ICommandQueuePtr commandQueue) : IHandler()
{
    m_commandQueue = commandQueue;
}

void RetryHandler::handle(ICommandPtr command)
{
    printf("RetryHandler handle\n");
    if(m_commandQueue && command)
        m_commandQueue->push_back(std::make_shared<RetryCommand>(command));
}
