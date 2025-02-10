#ifndef SECONDRETRYHANDLER_H
#define SECONDRETRYHANDLER_H

#include "ihandler.h"
#include "icommandqueue.h"

class SecondRetryHandler : public IHandler
{
    ICommandQueuePtr m_commandQueue;

public:
    SecondRetryHandler(ICommandQueuePtr commandQueue);
    void handle(ICommandPtr command) override;
};

typedef std::shared_ptr<SecondRetryHandler> SecondRetryHandlerPtr;
#endif // SECONDRETRYHANDLER_H
