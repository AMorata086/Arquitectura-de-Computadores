#!/bin/sh

cmake -S . -B release -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=/opt/gcc-12.1.0/bin/g++
cmake -S . -B debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=/opt/gcc-12.1.0/bin/g++