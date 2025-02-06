#include <stdexcept>
#include "rotate.h"

Rotate::Rotate(std::shared_ptr<IRotatable> obj)    
    : m_obj(obj)
{
}

void Rotate::execute()
{
    if(m_obj != nullptr)
    {
        m_obj->setAngle(m_obj->getAngle() + m_obj->getAngleSpeed());
    }
    else
        throw std::runtime_error("Rotate: nullptr exception");
}
