#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <exception>
#include <memory>

class CommandException : public std::exception
{
protected:
    int m_commandID = 0;
    int m_exceptionID = 0;
public:
    virtual ~CommandException(){}
    int getCommandID() { return m_commandID; }
    int getExceptionID() { return m_exceptionID; }
};

typedef std::shared_ptr<CommandException> CommandExceptionPtr;
#endif // COMMANDEXCEPTION_H