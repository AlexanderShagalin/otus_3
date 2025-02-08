#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include "ihandler.h"
#include "ilogger.h"

class LogHandler : IHandler
{
    ILoggerPtr m_logger;
public:
    LogHandler(ILoggerPtr logger);
    void handle(ICommandPtr command) override;
};

typedef std::shared_ptr<LogHandler> LogHandlerPtr;
#endif // LOGHANDLER_H
