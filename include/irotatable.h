#ifndef IROTATABLE_H
#define IROTATABLE_H

class IRotatable
{
public:
    virtual ~IRotatable() {};

    virtual double getAngle() = 0;
    virtual double getAngleSpeed() = 0;
    virtual void setAngle(double newAngle) = 0;
};

#endif // IROTATABLE_H
