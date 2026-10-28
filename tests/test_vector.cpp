#include <gtest/gtest.h>
#include "../include/vector.hpp"

TEST(VectorTest, InitiallyEmpty)
{
    myVector<int> v;

    EXPECT_TRUE(v.isEmpty());
}