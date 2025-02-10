#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "logexception.h"
#include "loghandler.h"
#include "logcommand.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class LoggerMock: public ILogger
{
public:
    MOCK_METHOD(void, log, (std::string));
};

class CommandMock: public ICommand
{
public:
    MOCK_METHOD(void, execute, ());
};

class CommandQueueMock: public ICommandQueue
{
public:
    MOCK_METHOD(void, push_back,(ICommandPtr command));
    MOCK_METHOD(void, push_front,(ICommandPtr command));
    MOCK_METHOD(void, next,());
    MOCK_METHOD(size_t, size,());
};

TEST(LogHandler, push_back)
{
    std::shared_ptr<LoggerMock> lmo = std::make_shared<LoggerMock>();
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();

    EXPECT_CALL(*cqmo, push_back(_));

    LogHandler h(cqmo, lmo);

    h.handle(cmo);
}

TEST(LogHandler, command_is_null)
{
    std::shared_ptr<LoggerMock> lmo = std::make_shared<LoggerMock>();
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();

    EXPECT_CALL(*cqmo, push_back(_)).Times(0);

    LogHandler h(cqmo, lmo);

    h.handle(nullptr);
}

TEST(LogHandler, logger_is_null)
{
    std::shared_ptr<LoggerMock> lmo = nullptr;
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();

    EXPECT_CALL(*cqmo, push_back(_)).Times(0);

    LogHandler h(cqmo, lmo);

    h.handle(nullptr);
}
