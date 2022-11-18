#!/bin/sh

# Script para la ejecucion de los stats de energia y rendimiento

# TEMPLATE:
# echo "<program_name> performance stats: " 
# perf stat -a ./<program_name> ../in ../extract <operation> > results/<nombre_archivo>.pbm
# echo "<program_name> energy stats: " 
# perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./<program_name> ../in ../extract <operation> > results/<nombre_archivo>.perf

