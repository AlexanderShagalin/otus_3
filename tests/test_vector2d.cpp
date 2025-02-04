#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "vector2d.h"


using namespace testing;

TEST(Vector2D, 1)
{
    Vector2D v1(95, 12);
    Vector2D v2(95, 12);

    ASSERT_EQ(v1 == v2, true);
}

TEST(Vector2D, 2)
{
    Vector2D v1(95, -12);
    Vector2D v2(-95, 12);

    ASSERT_EQ(v1 == v2, false);
}

TEST(Vector2D, 3)
{
    Vector2D v1(95, -12);
    Vector2D v2(-95, 12);

    ASSERT_EQ(v1 + v2, Vector2D(0.0, 0.0));
}
