cmake_minimum_required(VERSION 3.27)
project(mhd VERSION 1.0.0)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


file(GLOB SOURCES src/*.cpp)
include_directories(include)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")


add_executable(${PROJECT_NAME} ${SOURCES})
