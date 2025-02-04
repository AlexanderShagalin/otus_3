#include <stdexcept>
#include "moveforward.h"

 MoveForward::MoveForward(std::shared_ptr<IMovable> obj)
    : m_obj(obj)
{
}

void MoveForward::execute()
{
    if(m_obj != nullptr)
        m_obj->setPosition(m_obj->getPosition() + m_obj->getVelocity());
    else
        throw std::runtime_error("MoveForward: nullptr exception");
}
