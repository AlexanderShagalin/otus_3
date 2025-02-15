#ifndef BURNFUELCOMMAND_H
#define BURNFUELCOMMAND_H

#include <memory>
#include "icommand.h"
#include "ifueled.h"

class BurnFuelCommand : public ICommand
{
    std::shared_ptr<IFueled> m_obj;

public:
    BurnFuelCommand(std::shared_ptr<IFueled> obj);
    void execute() override;
};

#endif // BURNFUELCOMMAND_H
