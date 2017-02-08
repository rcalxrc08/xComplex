#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Adder
{
    public:
        virtual ~Adder() {}
        virtual int add(int a, int b)
        {
            return a + b;
        }
};

class MockAdder : public Adder
{
    public:
        MOCK_METHOD2(add, int(int a, int b));
};

TEST(GoogleMockTest, ExpectCalled)
{
    MockAdder adder;

    EXPECT_CALL(adder, add(1, 2));

    adder.add(1, 2);
}

TEST(GoogleMockTest, DefineReturnedValue)
{
    using ::testing::Return;
    MockAdder adder;

    EXPECT_CALL(adder, add(1, 2))
        .WillOnce(Return(42));

    ASSERT_EQ(42, adder.add(1, 2));
}
