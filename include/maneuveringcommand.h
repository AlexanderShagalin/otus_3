#ifndef MANEUVERINGCOMMAND_H
#define MANEUVERINGCOMMAND_H

#include <memory>
#include "icommand.h"
#include "imaneuvering.h"

class ManeuveringCommand : public ICommand
{
    std::shared_ptr<IManeuvering> m_obj;

public:
    ManeuveringCommand(std::shared_ptr<IManeuvering> obj);
    void execute() override;
};

#endif // MANEUVERINGCOMMAND_H
