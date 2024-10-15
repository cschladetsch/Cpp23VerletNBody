#!/bin/bash
# Build script using CMake

# Define the build directory
BUILD_DIR="build"

# Step 1: Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Step 2: Navigate into the build directory
cd "$BUILD_DIR"

# Step 3: Set environment variables to use gcc and g++
export CC=gcc
export CXX=g++

# Step 4: Run CMake to configure and generate the build system
cmake ..

# Step 5: Build the project
make
