#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>


#include "rotate.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;


class RotatableMock: public IRotatable
{
public:
    MOCK_METHOD(double, getAngle, ());
    MOCK_METHOD(double, getAngleSpeed, ());
    MOCK_METHOD(void, setAngle, (double));
};

TEST(Rotate, setAngle)
{
    std::shared_ptr<RotatableMock> ro = std::make_shared<RotatableMock>();
    Rotate r(ro);

    EXPECT_CALL(*ro, getAngle()).WillOnce(Return(90));
    EXPECT_CALL(*ro, getAngleSpeed()).WillOnce(Return(45));
    EXPECT_CALL(*ro, setAngle(135));

    r.execute();
}

TEST(Rotate, GetAngleFailException)
{
    std::shared_ptr<RotatableMock> ro = std::make_shared<RotatableMock>();
    Rotate r(ro);

    ON_CALL(*ro, getAngle).WillByDefault(Throw(std::runtime_error("getAngle() failed")));
    ON_CALL(*ro, getAngleSpeed).WillByDefault(Return(45));

    EXPECT_CALL(*ro, getAngle()).Times(AnyNumber());
    EXPECT_CALL(*ro, getAngleSpeed()).Times(AnyNumber());
    EXPECT_CALL(*ro, setAngle(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(r.execute());
}

TEST(Rotate, getRotationSpeedFailException)
{
    std::shared_ptr<RotatableMock> ro = std::make_shared<RotatableMock>();
    Rotate r(ro);

    ON_CALL(*ro, getAngle).WillByDefault(Return(90));
    ON_CALL(*ro, getAngleSpeed).WillByDefault(Throw(std::runtime_error("getAngleSpeed() failed")));

    EXPECT_CALL(*ro, getAngle()).Times(AnyNumber());
    EXPECT_CALL(*ro, getAngleSpeed()).Times(AnyNumber());
    EXPECT_CALL(*ro, setAngle(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(r.execute());
}

TEST(Rotate, SetAngleFailException)
{
    std::shared_ptr<RotatableMock> ro = std::make_shared<RotatableMock>();
    Rotate r(ro);

    ON_CALL(*ro, getAngle).WillByDefault(Return(90));
    ON_CALL(*ro, getAngleSpeed).WillByDefault(Return(45));
    ON_CALL(*ro, setAngle).WillByDefault(Throw(std::runtime_error("setAngle() failed")));

    EXPECT_CALL(*ro, getAngle()).Times(AnyNumber());
    EXPECT_CALL(*ro, getAngleSpeed()).Times(AnyNumber());
    EXPECT_CALL(*ro, setAngle(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(r.execute());
}
