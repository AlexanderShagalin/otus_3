#include "stdio.h"

#include "commandqueue.h"
#include "logger.h"
#include "strategy_2.h"
#include "moveforward.h"
#include "retrycommand.h"
#include "retryhandler.h"
#include "retryexception.h"
#include "secondretrycommand.h"
#include "secondretryhandler.h"
#include "secondretryexception.h"
#include "loghandler.h"
#include "commandexception.h"

Strategy_2::Strategy_2(ICommandPtr command)
{
    m_exManager = std::make_shared<ExceptionManager>();
    m_commandQueue = std::make_shared<CommandQueue>(m_exManager);
    auto logger = std::make_shared<Logger>();
    m_command = command;

    ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(std::make_shared<RetryHandler>(m_commandQueue)));
    ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(std::make_shared<SecondRetryHandler>(m_commandQueue)));
    ExceptionManager::registerHandler(std::make_shared<SecondRetryCommand>(nullptr), SecondRetryException(), std::dynamic_pointer_cast<IHandler>(std::make_shared<LogHandler>(m_commandQueue, logger)));

    m_commandQueue->push_back(command);
}

void Strategy_2::run()
{
    while(m_commandQueue->size() > 0)
    {
        // printf("execute \n");
        m_commandQueue->next();
    }
}