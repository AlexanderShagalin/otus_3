#ifndef IMANEUVERING_H
#define IMANEUVERING_H

#include "vector2d.h"
#include "angle.h"

class IManeuvering
{
public:
    virtual ~IManeuvering(){}

    virtual Angle getAngle() = 0;
    virtual Angle getAngleSpeed() = 0;
    virtual void setAngle(Angle newAngle) = 0;
    virtual double getVelocity() = 0;
    virtual void setInstantVelocity(Vector2D newVelocity) = 0;
};

#endif // IMANEUVERING_H
