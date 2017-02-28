#include "gtest/gtest.h"
#include "gtests/googlemock/include/gmock/gmock.h"
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}