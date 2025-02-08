#ifndef LOGCOMMAND_H
#define LOGCOMMAND_H

#include <memory>
#include "icommand.h"
#include "ilogger.h"

class LogCommand : public ICommand
{
    ILoggerPtr m_logger;
    std::string m_text;
public:
    LogCommand(ILoggerPtr logger, std::string text);
    void execute() override;
};

#endif // LOGCOMMAND_H
