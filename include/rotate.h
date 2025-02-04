#ifndef ROTATE_H
#define ROTATE_H

#include <memory>
#include "irotatable.h"

class Rotate
{
    std::shared_ptr<IRotatable> m_obj;

public:
    Rotate(std::shared_ptr<IRotatable> obj);
    void execute();
};

#endif // ROTATE_H
