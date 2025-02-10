
#include <stdexcept>

#include "secondretrycommand.h"
#include "secondretryexception.h"
 
SecondRetryCommand::SecondRetryCommand(ICommandPtr command)
{
    m_command = command;
}

void SecondRetryCommand::execute() 
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
        throw SecondRetryException(e);
    }
}
