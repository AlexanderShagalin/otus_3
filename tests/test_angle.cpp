#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <memory>

#include "angle.h"

TEST(Angle, equal)
{
    Angle a1(105.0);
    Angle a2(105.0);

    ASSERT_EQ(a1 == a2, true);
}

TEST(Angle, equal_overflow)
{
    Angle a1(95);
    Angle a2(95 + 360);

    ASSERT_EQ(a1 == a2, true);
}

TEST(Angle, summ)
{
    Angle a1(95);
    Angle a2(37);

    ASSERT_EQ(a1 + a2, Angle(95+37));
}
