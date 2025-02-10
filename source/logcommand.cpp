 #include "logexception.h"
 #include "logcommand.h"
 
LogCommand::LogCommand(ILoggerPtr logger, std::string text)
{
    m_logger = logger;
    m_text = text;
}
    
void LogCommand::execute()
{
    if(m_logger != nullptr)
        m_logger->log(m_text);
    else
        throw LogException("m_logger is nullptr");
}
