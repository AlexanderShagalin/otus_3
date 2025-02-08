#ifndef RETRYCOMMAND_H
#define RETRYCOMMAND_H

#include <memory>
#include "icommand.h"
#include "icommandqueue.h"

class RetryCommand : public ICommand
{
    ICommandQueuePtr m_commandQueue;
    ICommandPtr m_command;

public:
    RetryCommand(ICommandQueuePtr commandQueue, ICommandPtr command);
    void execute() override;
};

#endif // RETRYCOMMAND_H