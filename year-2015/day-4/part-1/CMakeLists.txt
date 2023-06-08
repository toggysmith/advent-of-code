cmake_minimum_required(VERSION 3.2)

project(day-4 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)


# Boost - Multiprecision
FetchContent_Declare(boost_multiprecision
                     GIT_REPOSITORY https://github.com/boostorg/multiprecision
                     GIT_TAG Boost_1_82_0)
FetchContent_MakeAvailable(boost_multiprecision)
# Boost - Config
FetchContent_Declare(boost_config
                     GIT_REPOSITORY https://github.com/boostorg/config
                     GIT_TAG boost-1.79.0)
FetchContent_MakeAvailable(boost_config)
# Boost - Assert
FetchContent_Declare(boost_assert
                     GIT_REPOSITORY https://github.com/boostorg/assert
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_assert)
# Boost - Describe
FetchContent_Declare(boost_describe
                     GIT_REPOSITORY https://github.com/boostorg/describe
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_describe)
# Boost - mp11
FetchContent_Declare(boost_mp11
                     GIT_REPOSITORY https://github.com/boostorg/mp11
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_mp11)
# Boost - Type Traits
FetchContent_Declare(boost_type_traits
                     GIT_REPOSITORY https://github.com/boostorg/type_traits
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_type_traits)
# Boost - Container Hash
FetchContent_Declare(boost_container_hash
                     GIT_REPOSITORY https://github.com/boostorg/container_hash
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_container_hash)
# Boost - Core
FetchContent_Declare(boost_core
                     GIT_REPOSITORY https://github.com/boostorg/core
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_core)
# Boost - Integer
FetchContent_Declare(boost_integer
                     GIT_REPOSITORY https://github.com/boostorg/integer
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_integer)
# Boost - Move
FetchContent_Declare(boost_move
                     GIT_REPOSITORY https://github.com/boostorg/move
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_move)
# Boost - Static Assert
FetchContent_Declare(boost_static_assert
                     GIT_REPOSITORY https://github.com/boostorg/static_assert
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_static_assert)
# Boost - Throw Exception
FetchContent_Declare(boost_throw_exception
                     GIT_REPOSITORY https://github.com/boostorg/throw_exception
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_throw_exception)
# Boost - Dynamic Bitset
FetchContent_Declare(boost_dynamic_bitset
                     GIT_REPOSITORY https://github.com/boostorg/dynamic_bitset
                     GIT_TAG boost-1.82.0)
FetchContent_MakeAvailable(boost_dynamic_bitset)

add_executable(out main.cpp)
target_link_libraries(out boost_multiprecision boost_dynamic_bitset)
