#!/bin/sh

export LD_LIBRARY_PATH=/opt/gcc-12.1.0/lib64

echo "Task 3.1"

echo "executing RELEASE version 3 times"
./release/counter
./release/counter
./release/counter

echo "executing DEBUG version 3 times"
./debug/counter
./debug/counter
./debug/counter

echo "Program execution finished"