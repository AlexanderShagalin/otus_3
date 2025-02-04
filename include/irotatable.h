#ifndef IROTATABLE_H
#define IROTATABLE_H

#include "angle.h"

class IRotatable
{
public:
    virtual ~IRotatable() {};

    virtual Angle getAngle() = 0;
    virtual Angle getAngleSpeed() = 0;
    virtual void setAngle(Angle newAngle) = 0;
};

#endif // IROTATABLE_H
