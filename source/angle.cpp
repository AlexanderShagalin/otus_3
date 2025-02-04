#include "angle.h"

Angle::Angle(double angle)
{
    m_angle = angle;
    if(m_angle > 360.0)
        m_angle = m_angle - 360.0;
    if(m_angle < 0.0)
        m_angle = m_angle + 360.0;
}

double Angle::angle() const
{
    return m_angle;
}

int operator == (const Angle &a1, const Angle &a2)
{
    double eps = 0.000001;
    auto v = a1.angle() - a2.angle();
    return v < eps && v > -eps;
}

Angle operator + (const Angle &a1, const Angle &a2)
{
    return Angle(a1.angle() + a2.angle());
}
