#!/usr/bin/env bash
echo "Creating build directory."
mkdir build

echo "Compiling the two objects needed for building the library **ipb_arithmetic**"
c++ -c -I./include/ src/subtract.cpp -o build/subtract.o
c++ -c -I./include/ src/sum.cpp -o build/sum.o

echo "Making an archive of these two objects and creating first library"
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

echo "Task 2: Build the example program"
c++ src/main.cpp -I ./include/ -L ./build/ -lipb_arithmetic -o ./results/yujie_example
echo "Finished!"