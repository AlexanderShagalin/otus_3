#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "changevelocitycommand.h"
#include "ivelocitychangeable.h"

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class VelocityChangeableMock: public IVelocityChangeable
{
public:
    MOCK_METHOD(void, setVelocity, (Vector2D));
};

TEST(ChangeVelocityCommand, moving)
{
    auto fo = std::make_shared<VelocityChangeableMock>();
    Vector2D newVelocity(4.0, 8.0);
    ChangeVelocityCommand f(fo, newVelocity);

    EXPECT_CALL(*fo, setVelocity(newVelocity));

    EXPECT_NO_THROW(f.execute());
}

TEST(ChangeVelocityCommand, exception_nullptr_object)
{
    ChangeVelocityCommand f(nullptr, 0.0);

    EXPECT_ANY_THROW(f.execute());
}
