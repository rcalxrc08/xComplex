cmake_minimum_required(VERSION 3.3)
project(AComplexClass)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_ADEPT -std=gnu++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(gtests)

find_package(Threads REQUIRED)
enable_testing()
include_directories(${GTEST_SOURCE_DIR} ${GMOCK_SOURCE_DIR})

file(GLOB SOURCES "xcomplex/Coder/*.cpp" "xcomplex/Include/*.h" "Adept/*.h" "Adept/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(runAllTests tests.cpp tests/GoogleTestTest.cpp tests/GoogleMockTest.cpp tests/AComplexDerivativeTest.cpp tests/AComplexTest.cpp tests/DComplexTest.cpp ${TEST_SOURCES} ${SOURCES} tests/MixedTest.cpp)
add_executable(AComplexClass main.cpp ${SOURCES})

target_link_libraries(runAllTests gtest gtest_main)
target_link_libraries(runAllTests gmock gmock_main)
add_test(AllTests runAllTests)
