cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    "FirstProjectInCMake"
    VERSION 1.0.0
    DESCRIPTION "CMake C Project Template for OS II"
    LANGUAGES C
)
set(CMAKE_C_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})