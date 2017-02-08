#include <cassert>

#include "gtest/gtest.h"
#include "functions.hpp"
#include "TestXComplex.h"
#include "dcomplex.h"

TEST(Xcomplex, Base)
{
	dcomplex x=dcomplex();
    ASSERT_EQ(0, x.getRealP());
}

/*TEST(Square, SquareBaseCase)
{
    ASSERT_EQ(0, square(0));
}

TEST(Square, SquareTest1)
{
    ASSERT_EQ(1, square(1));
}
TEST(Square, SquareTest2)
{
    ASSERT_EQ(4, square(2));
}
TEST(Square, SquareTest3)
{
    ASSERT_EQ(9, square(3));
}
TEST(Square, SquareTest4)
{
    ASSERT_EQ(16, square(4));
}
TEST(Square, SquareTest5)
{
    ASSERT_EQ(25, square(5));
}
TEST(Square, SquareTest6)
{
    ASSERT_EQ(36, square(6));
}*/
