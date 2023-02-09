#!/bin/sh

export LD_LIBRARY_PATH=/opt/gcc-12.1.0/lib64

echo "Task 3.2"

echo "executing RELEASE version w/ Thread Sanitizer 3 times"
./release-tsan/counter
./release-tsan/counter
./release-tsan/counter

echo "executing DEBUG version w/ Thread Sanitizer 3 times"
./debug-tsan/counter
./debug-tsan/counter
./debug-tsan/counter

echo "Program execution finished"
