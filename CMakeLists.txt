cmake_minimum_required(VERSION 3.21)
project("$PROJECTNAME")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)
include(CMakeOutput)

# Set to OFF to disable Steam
set(USE_STEAMWORKS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})

find_package(Leadwerks REQUIRED)

include(Leadwerks)
include(Steamworks)

add_subdirectory(Source)
