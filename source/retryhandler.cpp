#include "retryhandler.h"
#include "retrycommand.h"

RetryHandler::RetryHandler(ICommandQueuePtr commandQueue)
{
    m_commandQueue = commandQueue;
}

void RetryHandler::handle(ICommandPtr command)
{
    if(m_commandQueue && command)
        m_commandQueue->push_back(std::make_shared<RetryCommand>(m_commandQueue, command));
}
