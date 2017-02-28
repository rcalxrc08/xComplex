#include "gtest/gtest.h"

#include <string>

TEST(GoogleTestTest, BasicAssertion)
{
    ASSERT_TRUE(true);
    ASSERT_FALSE(false);
}

TEST(GoogleTestTest, BinaryComparison)
{
    ASSERT_EQ(1, 1);
    ASSERT_NE(1, 2);
    ASSERT_LT(1, 2);
    ASSERT_LE(1, 2);
    ASSERT_GT(3, 2);
    ASSERT_GE(3, 2);
}

TEST(GoogleTestTest, CStringComparison)
{
    ASSERT_STREQ("alice", "alice");
    ASSERT_STRNE("alice", "Alice");
    ASSERT_STRCASEEQ("alice", "Alice");
    ASSERT_STRCASENE("alice", "bob");
}

TEST(GoogleTestTest, StringComparison)
{
    ASSERT_EQ(std::string("alice"), std::string("alice"));
    ASSERT_EQ(std::string("alice"), "alice");
    ASSERT_EQ("alice", std::string("alice"));
}

TEST(GoogleTestTest, Exceptions)
{
    ASSERT_THROW(throw std::exception(), std::exception);
    ASSERT_NO_THROW(true);
}

TEST(GoogleTestTest, FloatingPointsComparison)
{
    ASSERT_FLOAT_EQ(1.5f, 1.500000000000000000000000001f);
    ASSERT_DOUBLE_EQ(1.5, 1.500000000000000000000000001);
    ASSERT_NEAR(1.5, 1.51, 0.02);
}
