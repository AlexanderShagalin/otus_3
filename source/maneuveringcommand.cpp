
#include <math.h>
#include <stdexcept>

#include "maneuveringcommand.h"
#include "commandexception.h"

 
ManeuveringCommand::ManeuveringCommand(std::shared_ptr<IManeuvering> obj)
{
    m_obj = obj;
}

void ManeuveringCommand::execute() 
{
    if(m_obj == nullptr)
    {
        throw std::runtime_error("ManeuveringCommand: m_obj is null");
        return;
    }

    try
    {
        m_obj->setAngle(m_obj->getAngle() + m_obj->getAngleSpeed());
        m_obj->setInstantVelocity(
            Vector2D(
                cos(m_obj->getAngle().angle() * M_PI / 180.0) * m_obj->getVelocity(), 
                sin(m_obj->getAngle().angle() * M_PI / 180.0) * m_obj->getVelocity()
            )
        );
    }
    catch(const std::exception& e)
    {
        throw CommandException(e);
        return;
    }
}
