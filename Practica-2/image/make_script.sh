#!/bin/sh

# exportamos las bibliotecas de gcc 12
export LD_LIBRARY_PATH=/opt/gcc-12.1.0/lib64

echo "Entering Make execution..."
make
echo "Make execution finished..."