#!/bin/sh

# Compilar image-aos
g++ -std=c++20 -Wall image-aos/imgaos.cpp -o image-aos
# Compilar image-soa
g++ -std=c++20 -Wall image-soa/imgsoa.cpp -o image-soa

# Compilar con CMake
#cmake .