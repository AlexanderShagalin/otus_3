#ifndef CHANGEVELOCITYCOMMAND_H
#define CHANGEVELOCITYCOMMAND_H

#include <memory>
#include "icommand.h"
#include "ivelocitychangeable.h"

class ChangeVelocityCommand : public ICommand
{
    std::shared_ptr<IVelocityChangeable> m_obj;
    Vector2D m_newVelocity;


public:
    ChangeVelocityCommand(std::shared_ptr<IVelocityChangeable> obj, Vector2D newVelocity);
    void execute() override;
};

#endif // CHANGEVELOCITYCOMMAND_H
