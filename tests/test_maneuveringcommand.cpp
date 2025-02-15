#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>
#include <math.h>

#include "maneuveringcommand.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;


class ManeuveringMock: public IManeuvering
{
public:
    MOCK_METHOD(Angle, getAngle, ());
    MOCK_METHOD(Angle, getAngleSpeed, ());
    MOCK_METHOD(void, setAngle, (Angle));
    MOCK_METHOD(double, getVelocity, ());
    MOCK_METHOD(void, setInstantVelocity, (Vector2D));
};

TEST(Maneuvering, setAngle)
{
    auto ro = std::make_shared<ManeuveringMock>();
    ManeuveringCommand r(ro);

    ON_CALL(*ro, getAngle()).WillByDefault(Return(Angle(45.0)));
    ON_CALL(*ro, getAngleSpeed()).WillByDefault(Return(Angle(35.0)));
    ON_CALL(*ro, getVelocity()).WillByDefault(Return(10.0));

    EXPECT_CALL(*ro, setAngle(Angle(80.0))).Times(1);
    EXPECT_CALL(*ro, setInstantVelocity(Vector2D(7.071068, 7.071068))).Times(1);

    r.execute();
}

TEST(Maneuvering, ObjIsNull)
{
    ManeuveringCommand r(nullptr);

    EXPECT_ANY_THROW(r.execute());
}

TEST(Maneuvering, SetAngleException)
{
    std::shared_ptr<ManeuveringMock> ro = std::make_shared<ManeuveringMock>();
    ManeuveringCommand r(ro);

    ON_CALL(*ro, getAngle()).WillByDefault(Return(Angle(45)));
    ON_CALL(*ro, getAngleSpeed()).WillByDefault(Return(Angle(35)));
    ON_CALL(*ro, getVelocity()).WillByDefault(Return(10.0));

    EXPECT_CALL(*ro, setAngle(_)).WillOnce(Throw(std::runtime_error("setAngle() failed")));

    EXPECT_ANY_THROW(r.execute());
}

TEST(Maneuvering, SetInstantVelocityException)
{
    std::shared_ptr<ManeuveringMock> ro = std::make_shared<ManeuveringMock>();
    ManeuveringCommand r(ro);

    ON_CALL(*ro, getAngle()).WillByDefault(Return(Angle(45)));
    ON_CALL(*ro, getAngleSpeed()).WillByDefault(Return(Angle(35)));
    ON_CALL(*ro, getVelocity()).WillByDefault(Return(10.0));

    EXPECT_CALL(*ro, setAngle(Angle(80.0))).Times(1);

    EXPECT_CALL(*ro, setInstantVelocity(_)).WillOnce(Throw(std::runtime_error("setAngle() failed")));

    EXPECT_ANY_THROW(r.execute());
}
