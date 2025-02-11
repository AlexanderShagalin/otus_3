#ifndef IVELOCITYCHANGEABLE_H
#define IVELOCITYCHANGEABLE_H

#include "vector2d.h"

class IVelocityChangeable
{
public:
    virtual ~IVelocityChangeable(){}

    virtual void setVelocity(Vector2D newVelocity) = 0;
};

#endif // IVELOCITYCHANGEABLE_H
