#!/bin/bash

echo "Cleaning build folder"
rm -rf build

echo "Creating build folder"
mkdir -p build

echo "Moving in build folder"
cd build

echo "Running cmake"
cmake ..

echo "Running make"
make

echo "Running test"
make test

