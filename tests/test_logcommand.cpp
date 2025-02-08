#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

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

TEST(LogCommand, text_logged)
{
    std::shared_ptr<LoggerMock> mo = std::make_shared<LoggerMock>();
    LogCommand l(mo, "log mock");

    EXPECT_CALL(*mo, log("log mock"));

    l.execute();
}

TEST(LogCommand, logger_is_null)
{
    std::shared_ptr<LoggerMock> mo = nullptr;
    LogCommand l(mo, "log mock");

    EXPECT_ANY_THROW(l.execute());
}
