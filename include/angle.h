#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
    double m_angle;
public:
    Angle(double angle = 0.0);
    double angle() const;
    friend int operator == (const Angle &a1, const Angle &a2);
    friend Angle operator + (const Angle &a1, const Angle &a2);
};

#endif // ANGLE_H
