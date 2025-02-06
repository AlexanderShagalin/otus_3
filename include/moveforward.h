#ifndef MOVEFORWARD_H
#define MOVEFORWARD_H

#include <memory>
#include "icommand.h"
#include "imovable.h"

class MoveForward : public ICommand
{
    std::shared_ptr<IMovable> m_obj;


public:
    MoveForward(std::shared_ptr<IMovable> obj);
    void execute() override;
};

#endif // MOVEFORWARD_H
