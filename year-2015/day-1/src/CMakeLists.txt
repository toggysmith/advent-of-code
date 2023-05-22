cmake_minimum_required(VERSION 3.24)

project(day-1 VERSION 1.0
             LANGUAGES CXX)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")

add_executable(out ${sources})

set_target_properties(out PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)