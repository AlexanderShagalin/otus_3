#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "retryexception.h"
#include "retryhandler.h"
#include "retrycommand.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

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

TEST(RetryHandler, push_back)
{
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();

    EXPECT_CALL(*cqmo, push_back(_));

    RetryHandler h(cqmo);

    h.handle(cmo);
}

TEST(RetryHandler, command_is_null)
{
    std::shared_ptr<CommandQueueMock> cqmo = std::make_shared<CommandQueueMock>();
    std::shared_ptr<CommandMock> cmo = std::make_shared<CommandMock>();

    EXPECT_CALL(*cqmo, push_back(_)).Times(0);

    RetryHandler h(cqmo);

    h.handle(nullptr);
}
