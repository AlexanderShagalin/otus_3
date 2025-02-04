#include "angle.h"

Angle::Angle(double angle) :
    m_angle(angle)
{}

double Angle::angle() const
{
    return m_angle;
}

int operator == (const Angle &a1, const Angle &a2)
{
    return a1.angle() == a2.angle();
}

Angle operator + (const Angle &a1, const Angle &a2)
{
    double newAngle = a1.angle() + a2.angle();
    if(newAngle > 360.0)
        newAngle = newAngle - 360.0;
    if(newAngle < 0.0)
        newAngle = newAngle + 360.0;
    return Angle(newAngle);
}
