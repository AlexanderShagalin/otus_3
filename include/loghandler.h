#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include "ihandler.h"
#include "ilogger.h"
#include "icommandqueue.h"

class LogHandler : IHandler
{
    ILoggerPtr m_logger;
    ICommandQueuePtr m_commandQueue;

public:
    LogHandler(ICommandQueuePtr commandQueue, ILoggerPtr logger);
    void handle(ICommandPtr command) override;
};

typedef std::shared_ptr<LogHandler> LogHandlerPtr;
#endif // LOGHANDLER_H
