#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "retrycommand.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

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

TEST(RetryCommand, retry_command)
{
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();
    RetryCommand r(cqmo, cmo);

    EXPECT_CALL(*cqmo, push_back(_));

    r.execute();
}

TEST(RetryCommand, CommandQueue_is_null)
{
    std::shared_ptr<CommandQueueMock> cqmo = nullptr;
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();

    RetryCommand r(cqmo, cmo);

    EXPECT_ANY_THROW(r.execute());
}

TEST(RetryCommand, Command_is_null)
{
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = nullptr;

    RetryCommand r(cqmo, cmo);

    EXPECT_ANY_THROW(r.execute());
}
