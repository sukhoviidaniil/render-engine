cmake_minimum_required(VERSION 3.20)
# Specify the name of the project
project(Render_Engine LANGUAGES CXX)

# We specify the c++ standard
set(CMAKE_CXX_STANDARD 20)
# If the compiler can't support it, it's an error
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# We force the compiler to disable all extensions and strictly follow the standard
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D_DEBUG)
    message("-- Debugmod on")
endif()

set(JSON_DIR "${CMAKE_SOURCE_DIR}/external/json")
message(${JSON_DIR})

option(BUILD_STANDALONE "Build standalone executable" OFF)

add_subdirectory(sif)

if(BUILD_STANDALONE)
    add_subdirectory(app)
endif()

add_subdirectory(app)