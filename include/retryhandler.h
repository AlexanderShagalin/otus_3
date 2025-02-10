#ifndef RETRYHANDLER_H
#define RETRYHANDLER_H

#include "ihandler.h"
#include "icommandqueue.h"

class RetryHandler : public IHandler
{
    ICommandQueuePtr m_commandQueue;

public:
    RetryHandler(ICommandQueuePtr commandQueue);
    void handle(ICommandPtr command) override;
};

typedef std::shared_ptr<RetryHandler> RetryHandlerPtr;
#endif // RETRYHANDLER_H
