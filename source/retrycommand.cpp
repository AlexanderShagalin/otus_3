
#include <stdexcept>

#include "retrycommand.h"
#include "retryexception.h"
 
RetryCommand::RetryCommand(ICommandPtr command)
{
    m_command = command;
}

void RetryCommand::execute() 
{
    if(m_command == nullptr)
    {
        throw std::runtime_error("m_command is nullptr");
        return;
    }

    try
    {
        m_command->execute();
    }
    catch(const std::exception& e)
    {
        throw RetryException(e);
    }
}
