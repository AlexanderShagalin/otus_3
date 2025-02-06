#include <exception>
#include "commandqueue.h"
#include "moveforward.h"

CommandQueue::CommandQueue(std::list<ICommandPtr> commandList) 
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
        catch(std::exception &e)
        {

        }

    }
}
