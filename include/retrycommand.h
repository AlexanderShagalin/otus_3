#ifndef RETRYCOMMAND_H
#define RETRYCOMMAND_H

#include <memory>
#include "icommand.h"
#include "icommandqueue.h"

class RetryCommand : public ICommand
{
    ICommandPtr m_command;

public:
    RetryCommand(ICommandPtr command);
    void execute() override;
};

#endif // RETRYCOMMAND_H
