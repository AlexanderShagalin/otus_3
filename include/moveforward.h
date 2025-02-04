#ifndef MOVEFORWARD_H
#define MOVEFORWARD_H

#include <memory>
#include "imovable.h"

class MoveForward
{
    std::shared_ptr<IMovable> m_obj;


public:
    MoveForward(std::shared_ptr<IMovable> obj);
    void execute();
};

#endif // MOVEFORWARD_H
