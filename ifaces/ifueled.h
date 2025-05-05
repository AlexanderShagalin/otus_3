#ifndef IFUELED_H
#define IFUELED_H

class IFueled
{
public:
    virtual ~IFueled(){}

    virtual int getFuelCount() = 0;
    virtual int getConsumption() = 0;
    virtual void setFuelCount(int count) = 0;
};

#endif // IFUELED_H
