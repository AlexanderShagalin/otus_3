#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "burnfuelcommand.h"
#include "ifueled.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class FueledMock: public IFueled
{
public:
    MOCK_METHOD(int, getFuelCount, ());
    MOCK_METHOD(int, getConsumption, ());
    MOCK_METHOD(void, setFuelCount, (int count));
};

TEST(BurnFuelCommand, moving)
{
    auto fo = std::make_shared<FueledMock>();
    BurnFuelCommand f(fo);

    EXPECT_CALL(*fo, getFuelCount()).WillOnce(Return(11));
    EXPECT_CALL(*fo, getConsumption()).WillOnce(Return(7));
    EXPECT_CALL(*fo, setFuelCount(4));

    EXPECT_NO_THROW(f.execute());
}

TEST(BurnFuelCommand, exception_nullptr_object)
{
    BurnFuelCommand f(nullptr);

    EXPECT_ANY_THROW(f.execute());
}
