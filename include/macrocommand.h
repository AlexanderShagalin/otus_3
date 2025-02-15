#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include <memory>
#include <list>
#include "icommand.h"
#include "icommandqueue.h"

class MacroCommand : public ICommand
{
    std::list<ICommandPtr> m_commands;

public:
    MacroCommand(std::list<ICommandPtr> commands);
    void execute() override;
};

#endif // MACROCOMMAND_H
