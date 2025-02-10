#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "ilogger.h"
#include "icommand.h"
#include "imovable.h"
#include "commandexception.h"
#include "retryexception.h"
#include "retryhandler.h"
#include "retrycommand.h"
#include "loghandler.h"
#include "moveforward.h"
#include "exceptionmanager.h"
#include "commandqueue.h"


using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class NonMovableObject : public IMovable
{
public:
    Vector2D getPosition() override { return Vector2D(0.0, 0.0); }
    Vector2D getVelocity() override { return Vector2D(0.0, 0.0); }
    void setPosition(Vector2D newPosition) override { throw CommandException("Cannot move non-movable object"); }
};

class MovableObject : public IMovable
{
public:
    Vector2D getPosition() override { return Vector2D(0.0, 0.0); }
    Vector2D getVelocity() override { return Vector2D(0.0, 0.0); }
    void setPosition(Vector2D newPosition) override { }
};

class CommandQueueMock: public ICommandQueue
{
public:
    MOCK_METHOD(void, push_back,(ICommandPtr command));
    MOCK_METHOD(void, push_front,(ICommandPtr command));
    MOCK_METHOD(void, next,());
    MOCK_METHOD(size_t, size,());
};

class CommandMock: public ICommand
{
public:
    MOCK_METHOD(void, execute,());
};

class LoggerMock : public ILogger
{
public:
    MOCK_METHOD(void, log,(std::string text));
};

class LogHandlerMock : public IHandler
{
public:
    MOCK_METHOD(void, handle, (ICommandPtr command));
};

class RetryHandlerMock : public IHandler
{
public:
     MOCK_METHOD(void, handle, (ICommandPtr command));
};

TEST(Strategy_1, retry_handled)
{
    auto commandQueue = std::make_shared<CommandQueue>(std::make_shared<ExceptionManager>());
    auto command = std::make_shared<MoveForward>(std::make_shared<NonMovableObject>());
    auto retryHandler = std::make_shared<RetryHandlerMock>();

    ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(retryHandler));
    // ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(std::make_shared<LogHandlerMock>()));

    commandQueue->push_back(command);

    EXPECT_CALL(*retryHandler, handle(_));

    while(commandQueue->size() > 0)
    {
        commandQueue->next();
    }
    ExceptionManager::clear();
}

TEST(Strategy_1, retry_not_handled)
{
    auto commandQueue = std::make_shared<CommandQueue>(std::make_shared<ExceptionManager>());
    auto command = std::make_shared<MoveForward>(std::make_shared<MovableObject>());
    auto retryHandler = std::make_shared<RetryHandlerMock>();

    ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(retryHandler));
    // ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(std::make_shared<LogHandlerMock>()));

    commandQueue->push_back(command);

    EXPECT_CALL(*retryHandler, handle(_)).Times(0);

    while(commandQueue->size() > 0)
    {
        commandQueue->next();
    }
    ExceptionManager::clear();
}


TEST(Strategy_1, logger_handled)
{
    auto commandQueue = std::make_shared<CommandQueue>(std::make_shared<ExceptionManager>());
    auto logger = std::make_shared<LoggerMock>();
    auto command = std::make_shared<MoveForward>(std::make_shared<NonMovableObject>());
    // auto retryCommand = std::make_shared<RetryCommand>();
    auto retryHandler = std::make_shared<RetryHandler>(commandQueue);
    auto logHandler = std::make_shared<LogHandlerMock>();

    ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(retryHandler));
    ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(logHandler));

    commandQueue->push_back(command);

    EXPECT_CALL(*logHandler, handle(_));

    while(commandQueue->size() > 0)
    {
        commandQueue->next();
    }
    ExceptionManager::clear();
}

TEST(Strategy_1, logger_not_handled)
{
    auto commandQueue = std::make_shared<CommandQueue>(std::make_shared<ExceptionManager>());
    auto logger = std::make_shared<LoggerMock>();
    auto command = std::make_shared<MoveForward>(std::make_shared<MovableObject>());
    // auto retryCommand = std::make_shared<RetryCommand>();
    auto retryHandler = std::make_shared<RetryHandler>(commandQueue);
    auto logHandler = std::make_shared<LogHandlerMock>();

    ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(retryHandler));
    ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(logHandler));

    commandQueue->push_back(command);

    EXPECT_CALL(*logHandler, handle(_)).Times(0);

    while(commandQueue->size() > 0)
    {
        commandQueue->next();
    }
    ExceptionManager::clear();
}

TEST(Strategy_1, logger_write_log)
{
    auto commandQueue = std::make_shared<CommandQueue>(std::make_shared<ExceptionManager>());
    auto logger = std::make_shared<LoggerMock>();
    auto command = std::make_shared<MoveForward>(std::make_shared<NonMovableObject>());
    // auto retryCommand = std::make_shared<RetryCommand>();
    auto retryHandler = std::make_shared<RetryHandler>(commandQueue);
    auto logHandler = std::make_shared<LogHandler>(commandQueue, logger);

    ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(retryHandler));
    ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(logHandler));

    commandQueue->push_back(command);

    EXPECT_CALL(*logger, log(_));

    while(commandQueue->size() > 0)
    {
        commandQueue->next();
    }
    ExceptionManager::clear();
}

// TEST(Strategy_1, logger_command)
// {
//     // auto exmanager= std::make_shared<ExceptionManager>();
//     auto commandQueue = std::make_shared<CommandQueue>(std::make_shared<ExceptionManager>());
//     // auto logger = std::make_shared<LoggerMock>();
//     auto command = std::make_shared<MoveForward>(std::make_shared<NonMovableObject>());
//     // auto retryCommand = std::make_shared<CommandMock>();
//     auto retryHandler = std::make_shared<RetryHandlerMock>();

//     ExceptionManager::registerHandler(command, CommandException(), std::dynamic_pointer_cast<IHandler>(retryHandler));
//     // ExceptionManager::registerHandler(std::make_shared<RetryCommand>(nullptr), RetryException(), std::dynamic_pointer_cast<IHandler>(std::make_shared<LogHandlerMock>()));

//     commandQueue->push_back(command);

//     EXPECT_CALL(*retryHandler, handle(_));

//     while(commandQueue->size() > 0)
//     {
//         commandQueue->next();
//     }
//     ExceptionManager::clear();
// }
