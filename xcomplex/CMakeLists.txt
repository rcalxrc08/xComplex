#xcomplex
project(xcomplex)
file(GLOB xcomplex_SRC "src/*.cpp")
include_directories("include" "../adept")
add_library(xcomplex STATIC ${xcomplex_SRC})
set_property(TARGET xcomplex PROPERTY POSITION_INDEPENDENT_CODE ON)