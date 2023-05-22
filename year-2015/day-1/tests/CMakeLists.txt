cmake_minimum_required(VERSION 3.24)

    project(day-1 VERSION 1.0
                LANGUAGES CXX)

    cmake_policy(SET CMP0135 NEW)

    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "../src/*.cpp")
    list(FILTER sources EXCLUDE REGEX "main.cpp")
    add_executable(test_runner ${sources})

    set_target_properties(test_runner PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
    )

    target_include_directories(test_runner PRIVATE "../src")
    target_link_libraries(
    test_runner
    GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(test_runner)
    