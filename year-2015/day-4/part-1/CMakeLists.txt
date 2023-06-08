cmake_minimum_required(VERSION 3.2)

project(day-4 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(out main.cpp md5.cpp)
