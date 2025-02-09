
#include <stdexcept>

#include "repeatcommand.h"
 
RepeatCommand::RepeatCommand(ICommandQueuePtr commandQueue, ICommandPtr command)
{
    m_commandQueue = commandQueue;
    m_command = command;
}

void RepeatCommand::execute() 
{
    if(m_commandQueue == nullptr)
    {
        throw std::runtime_error("m_commandQueue is nullptr");
        return;
    }   

    if(m_command == nullptr)
    {
        throw std::runtime_error("m_command is nullptr");
        return;
    }

    m_commandQueue->push_back(m_command);
}
