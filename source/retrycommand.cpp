#include <stdexcept>

#include "retrycommand.h"
 
RetryCommand::RetryCommand(ICommandQueuePtr commandQueue, ICommandPtr command)
{
    m_commandQueue = commandQueue;
    m_command = command;
}

void RetryCommand::execute() 
{
    if(m_commandQueue == nullptr)
    {
        std::runtime_error("m_commandQueue is nullptr");
    }   

    if(m_command == nullptr)
    {
        std::runtime_error("m_command is nullptr");
    }

    m_commandQueue->push_back(m_command);
}
