#ifndef SECONDRETRYCOMMAND_H
#define SECONDRETRYCOMMAND_H

#include <memory>
#include "icommand.h"
#include "icommandqueue.h"

class SecondRetryCommand : public ICommand
{
    ICommandPtr m_command;

public:
    SecondRetryCommand(ICommandPtr command);
    void execute() override;
};

#endif // SECONDRETRYCOMMAND_H
