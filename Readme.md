# N-Body Simulation (C++23)

This is an N-body simulation using SDL2 and C++23 that simulates the gravitational interactions between multiple bodies. The simulation also includes wall bouncing and visible traces for each body's movement.

## Features
- **Verlet Integration** for smooth position updates.
- **Body-to-wall collisions** with bouncing.
- **Customizable simulation** with command-line arguments.
- **Persistent trails** showing the movement of the bodies.
- Written in **C++23**.

## Requirements

You need the following to build and run this project:
- **SDL2** development libraries
- **CMake**
- A compiler supporting **C++23** (such as **GCC 13+** or **Clang 16+**)

### Installing SDL2

- **Ubuntu/Debian**:
  ```bash
  sudo apt-get install libsdl2-dev
  ```

- **Mac** (using Homebrew):
  ```bash
  brew install sdl2
  ```

### Installing GCC/Clang with C++23 Support

- **Ubuntu/Debian**:
  You can add the required repository for GCC 13 or Clang 16 to get C++23 support.

  For GCC 13:
  ```bash
  sudo apt install g++-13
  ```

  For Clang 16:
  ```bash
  sudo apt install clang-16
  ```

## Build Instructions

2. **Build the project** using the `b` script:
   ```bash
   ./b
   ```

   This script:
   - Creates a `build/` directory.
   - Configures the project using CMake.
   - Compiles the project with **C++23**.

## Running the Simulation

After building the project, you can run the simulation using the `r` script. This script takes two optional command-line arguments:

- **Number of bodies** (default: 4)
- **Speed multiplier** (default: 1.0)

### Example Usage:

1. **Run with default settings** (4 bodies, speed multiplier of 1.0):
   ```bash
   ./r
   ```

2. **Run with custom settings** (6 bodies, speed multiplier of 15.0):
   ```bash
   ./r 6 15.0
   ```

## Project Structure

- **`main.cpp`**: The main entry point, initializes SDL2, and runs the simulation loop.
- **`body.hpp`, `body.cpp`**: Manages the body properties (position, mass, velocity) and initialization.
- **`physics.hpp`, `physics.cpp`**: Contains the physics calculations, including gravity and Verlet integration.
- **`graphics.hpp`, `graphics.cpp`**: Handles rendering the bodies and fading the trails.
- **`CMakeLists.txt`**: CMake configuration file for building the project.

## Troubleshooting

- If you encounter errors with the compiler, ensure that you are using **GCC 13+** or **Clang 16+** and set them explicitly in the `b` script:
  ```bash
  export CC=gcc-13
  export CXX=g++-13
  ```

## License

This project is open-source and available under the MIT License.
