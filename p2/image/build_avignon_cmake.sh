#!/bin/sh

# exportamos las bibliotecas de gcc 12
export LD_LIBRARY_PATH=/opt/gcc-12.1.0/lib64

# compilamos con cmake y la version 12 de g++
cmake -S . -B release -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=/opt/gcc-12.1.0/bin/g++

cp make_script.sh ./release/make_script.sh