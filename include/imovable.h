#ifndef IMOVABLE_H
#define IMOVABLE_H

#include "vector2d.h"

class IMovable
{
public:
    virtual ~IMovable(){}

    virtual Vector2D getPosition() = 0;
    virtual Vector2D getVelocity() = 0;
    virtual void setPosition(Vector2D newPosition) = 0;
};

#endif // IMOVABLE_H
