#!/bin/sh

# Compilar image-aos
g++ -std=c++20 -Wall -Wextra -Werror -pedantic -pedantic-errors image-aos/imgaos.cpp -o image-aos.o
echo "image-aos compiled!"
# Compilar image-soa
g++ -std=c++20 -Wall -Wextra -Werror -pedantic -pedantic-errors image-soa/imgsoa.cpp -o image-soa.o
echo "image-soa compiled!"

# Compilar con CMake
# cmake . -DCMAKE_BUILD_TYPE=Release