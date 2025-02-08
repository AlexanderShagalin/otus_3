#include "loghandler.h"

LogHandler::LogHandler(ILoggerPtr logger)
{
    m_logger = logger;
}

void LogHandler::handle(ICommandPtr command)
{
    m_logger->log("exception logged");
}
