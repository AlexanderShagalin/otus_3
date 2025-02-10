
#include <stdexcept>

#include "checkfuelcommand.h"
#include "checkfuelexception.h"
 
CheckFuelCommand::CheckFuelCommand(std::shared_ptr<IFueled> obj)
{
    m_obj = obj;
}

void CheckFuelCommand::execute() 
{
    if(m_obj == nullptr)
    {
        throw std::runtime_error("CheckFuelCommand: nullptr exception");
        return;
    }

    if((m_obj->getFuelCount() - m_obj->getConsumption()) < 0)
    {
        throw CheckFuelException("Fuel is low! Can not move!");
    }
}
