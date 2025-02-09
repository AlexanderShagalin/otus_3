#ifndef REPEATCOMMAND_H
#define REPEATCOMMAND_H

#include <memory>
#include "icommand.h"
#include "icommandqueue.h"

class RepeatCommand : public ICommand
{
    ICommandQueuePtr m_commandQueue;
    ICommandPtr m_command;

public:
    RepeatCommand(ICommandQueuePtr commandQueue, ICommandPtr command);
    void execute() override;
};

#endif // RETRYCOMMAND_H
