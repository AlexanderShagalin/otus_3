#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <string>
#include "ilogger.h"

class Logger : public ILogger
{
public:
    void log(std::string text) override;
};

typedef std::shared_ptr<Logger> LoggerPtr;
#endif // ILOGGER_H