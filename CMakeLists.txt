cmake_minimum_required(VERSION 3.8)

# Project name
project("KoffeeKrew-AutoScape")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/KoffeeKrew-AutoScape.cpp
    src/AutoSplasher.cpp
)

# Add the executable
add_executable(KoffeeKrew-AutoScape ${SOURCES})