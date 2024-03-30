cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Project Definition
project(
    "FirstProjectInCMake"
    VERSION 1.0.0
    DESCRIPTION "CMake C Project Template for OS II"
    LANGUAGES C
)

# Enable testing and add the tests
include(CTest)

# Define the C standard to use
set(CMAKE_C_STANDARD 17)

# Include the 'include' directory, where the headers are located
include_directories(include)

# To automatically dowlonad external deps
include(FetchContent)

set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

# Enable Debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

# To wait until dependencies previously defined have been downloaded
FetchContent_MakeAvailable(Unity)

# Include the 'src' directory, where the source files are located
file(GLOB_RECURSE SOURCES "src/*.c")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Compile libraries
add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

# Include headers in lib
target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

# Link libraries
target_link_libraries(${PROJECT_NAME} StatiCLib DynamiCLib)

# Add subdirectory of tests. Passed when executing CMAKE
if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()
