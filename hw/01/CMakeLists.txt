cmake_minimum_required(VERSION 3.27)
project(hw01 VERSION 0.1)
set(PROJECT_LIB "hw01lib")


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_BUILD_TYPE Debug)


file(GLOB SOURCES
    src/*.cpp
)


include_directories(include)


add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)
