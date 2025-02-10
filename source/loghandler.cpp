#include "loghandler.h"
#include "logcommand.h"

LogHandler::LogHandler(ICommandQueuePtr commandQueue, ILoggerPtr logger) : IHandler()
{
    m_logger = logger;
    m_commandQueue = commandQueue;
}

void LogHandler::handle(ICommandPtr command)
{
    if(m_commandQueue && m_logger && command)
        m_commandQueue->push_back(std::make_shared<LogCommand>(m_logger, "exception logged"));
}
