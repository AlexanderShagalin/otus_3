#ifndef CHECKFUELCOMMAND_H
#define CHECKFUELCOMMAND_H

#include <memory>
#include "icommand.h"
#include "ifueled.h"

class CheckFuelCommand : public ICommand
{
    std::shared_ptr<IFueled> m_obj;

public:
    CheckFuelCommand(std::shared_ptr<IFueled> obj);
    void execute() override;
};

#endif // CHECKFUELCOMMAND_H
