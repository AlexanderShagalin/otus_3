#include <stdexcept>
#include "changevelocitycommand.h"

 ChangeVelocityCommand::ChangeVelocityCommand(std::shared_ptr<IVelocityChangeable> obj, Vector2D newVelocity) 
{
    m_obj = obj;
    m_newVelocity = newVelocity; 
}

void ChangeVelocityCommand::execute()
{
    if(m_obj != nullptr)
        m_obj->setVelocity(m_newVelocity);
    else
        throw std::runtime_error("ChangeVelocityCommand: nullptr exception");
}
