
#include <stdexcept>

#include "burnfuelcommand.h"
 
BurnFuelCommand::BurnFuelCommand(std::shared_ptr<IFueled> obj)
{
    m_obj = obj;
}

void BurnFuelCommand::execute() 
{
    if(m_obj == nullptr)
    {
        throw std::runtime_error("BurnFuelCommand: nullptr exception");
        return;
    }

    m_obj->setFuelCount(m_obj->getFuelCount() - m_obj->getConsumption());
}
