#ifndef ILOGGER_H
#define ILOGGER_H

#include <memory>
#include <string>

class ILogger
{
public:
    virtual ~ILogger(){}
    virtual void log(std::string text) = 0;
};

typedef std::shared_ptr<ILogger> ILoggerPtr;
#endif // ILOGGER_H