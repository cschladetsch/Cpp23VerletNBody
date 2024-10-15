
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(NBodySimulation VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable for the project
add_executable(nbody_simulation 
    main.cpp 
    body.cpp 
    physics.cpp 
    graphics.cpp
)

# Find the SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Link SDL2 with the executable
target_link_libraries(nbody_simulation ${SDL2_LIBRARIES})
