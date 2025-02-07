#include "commandexception.h"
#include "commandqueue.h"
#include "moveforward.h"

CommandQueue::CommandQueue(ExceptionManagerPtr exManager, std::list<ICommandPtr> commandList) 
{
    m_commandList = {std::make_shared<MoveForward>(nullptr), std::make_shared<MoveForward>(nullptr)};
}

void CommandQueue::start()
{
    for(auto command : m_commandList)
    {
        try
        {
            command->execute();
        }
        catch(std::exception& e)
        {
           m_exManager->handle(e, command);
        }
    }
}

void CommandQueue::push_back(ICommandPtr command)
{
    m_commandList.push_back(command);
}
    