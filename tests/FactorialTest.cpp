#include <cassert>

#include "gtest/gtest.h"
#include "functions.hpp"

TEST(Factorial, BaseCaseFactorialOfZeroIsOne)
{
    ASSERT_EQ(1, factorial(0));
}

TEST(Factorial, BunchOfCasesReturnCorrectValue)
{
    ASSERT_EQ(1, factorial(1));
    ASSERT_EQ(2, factorial(2));
    ASSERT_EQ(6, factorial(3));
    ASSERT_EQ(24, factorial(4));
    ASSERT_EQ(120, factorial(5));
}
