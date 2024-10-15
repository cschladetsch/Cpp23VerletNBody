#!/bin/bash

# Default values
NUM_BODIES=4          # Default number of bodies
SPEED_MULTIPLIER=1.0  # Default speed multiplier

# If arguments are provided, override the defaults
if [ ! -z "$1" ]; then
    NUM_BODIES=$1
fi

if [ ! -z "$2" ]; then
    SPEED_MULTIPLIER=$2
fi

# Step 1: Build the project using 'b' script
./b

# Step 2: Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Build failed, aborting."
    exit 1
fi

# Step 3: Run the resulting executable
echo "Running the simulation with $NUM_BODIES bodies and speed multiplier $SPEED_MULTIPLIER..."
./build/nbody_simulation $NUM_BODIES $SPEED_MULTIPLIER

