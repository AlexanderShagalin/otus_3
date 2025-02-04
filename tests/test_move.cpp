#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "moveforward.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class MovableMock: public IMovable
{
public:
    MOCK_METHOD(Vector2D, getPosition, ());
    MOCK_METHOD(Vector2D, getVelocity, ());
    MOCK_METHOD(void, setPosition, (Vector2D));
};

TEST(MoveForward, Moving)
{
    std::shared_ptr<MovableMock> mo = std::make_shared<MovableMock>();
    MoveForward m(mo);

    EXPECT_CALL(*mo, getPosition()).WillOnce(Return(Vector2D(12, 5)));
    EXPECT_CALL(*mo, getVelocity()).WillOnce(Return(Vector2D(-7, 3)));
    EXPECT_CALL(*mo, setPosition(Vector2D(5,8)));

    m.execute();
}

TEST(MoveForward, GetLocationFailException)
{
    std::shared_ptr<MovableMock> mo = std::make_shared<MovableMock>();
    MoveForward m(mo);

    ON_CALL(*mo, getPosition).WillByDefault(Throw(std::runtime_error("getLocation() failed")));
    ON_CALL(*mo, getVelocity).WillByDefault(Return(Vector2D(-7, 3)));

    EXPECT_CALL(*mo, getPosition()).Times(AnyNumber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNumber());
    EXPECT_CALL(*mo, setPosition(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(m.execute());
}

TEST(MoveForward, GetPositionFailException)
{
    std::shared_ptr<MovableMock> mo = std::make_shared<MovableMock>();
    MoveForward m(mo);

    ON_CALL(*mo, getPosition).WillByDefault(Return(Vector2D(12, 5)));
    ON_CALL(*mo, getVelocity).WillByDefault(Throw(std::runtime_error("getVelocity() failed")));

    EXPECT_CALL(*mo, getPosition()).Times(AnyNumber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNumber());
    EXPECT_CALL(*mo, setPosition(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(m.execute());
}

TEST(MoveForward, SetPositionFailException)
{
    std::shared_ptr<MovableMock> mo = std::make_shared<MovableMock>();
    MoveForward m(mo);

    ON_CALL(*mo, getPosition).WillByDefault(Return(Vector2D(12, 5)));
    ON_CALL(*mo, getVelocity).WillByDefault(Return(Vector2D(-7, 3)));
    ON_CALL(*mo, setPosition).WillByDefault(Throw(std::runtime_error("setLocation() failed")));

    EXPECT_CALL(*mo, getPosition()).Times(AnyNumber());
    EXPECT_CALL(*mo, getVelocity()).Times(AnyNumber());
    EXPECT_CALL(*mo, setPosition(_)).Times(AnyNumber());

    EXPECT_ANY_THROW(m.execute());
}
