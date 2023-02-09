#!/bin/sh

# Compilacion
cmake -S ./cache/ -B debug -DCMAKE_BUILD_TYPE=Debug
cmake --build debug

# Configuracion lab15 --> Conf 3
# tam. linea = 64B
# Caches asociativas de 4 vias

# Tarea 1
# loop_merge.cpp
valgrind --tool=cachegrind --cachegrind-out-file=loop-merge-16 --D1=16384,4,64 --LL=131072,4,64  ./debug/loop_merge > vg-loop-merge-16.txt
cg_annotate loop-merge-16 /home/alumnos/a0405846/lab3/cache/loop_merge.cpp > cg-loop-merge-16.txt

valgrind --tool=cachegrind --cachegrind-out-file=loop-merge-32 --D1=32768,4,64 --LL=131072,4,64 ./debug/loop_merge > vg-loop-merge-32.txt
cg_annotate loop-merge-32 /home/alumnos/a0405846/lab3/cache/loop_merge.cpp > cg-loop-merge-32.txt

valgrind --tool=cachegrind --cachegrind-out-file=loop-merge-64 --D1=65536,4,64 --LL=131072,4,64 ./debug/loop_merge > vg-loop-merge-64.txt
cg_annotate loop-merge-64 /home/alumnos/a0405846/lab3/cache/loop_merge.cpp > cg-loop-merge-64.txt

# loop_merge_opt.cpp
valgrind --tool=cachegrind --cachegrind-out-file=loop-merge-opt-16 --D1=16384,4,64 --LL=131072,4,64 ./debug/loop_merge_opt > vg-loop-merge-opt-16.txt
cg_annotate loop-merge-opt-16 /home/alumnos/a0405846/lab3/cache/loop_merge_opt.cpp > cg-loop-merge-opt-16.txt

valgrind --tool=cachegrind --cachegrind-out-file=loop-merge-opt-32 --D1=32768,4,64 --LL=131072,4,64 ./debug/loop_merge_opt > vg-loop-merge-opt-32.txt
cg_annotate loop-merge-opt-32 /home/alumnos/a0405846/lab3/cache/loop_merge_opt.cpp > cg-loop-merge-opt-32.txt

valgrind --tool=cachegrind --cachegrind-out-file=loop-merge-opt-64 --D1=65536,4,64 --LL=131072,4,64 ./debug/loop_merge_opt > vg-loop-merge-opt-64.txt
cg_annotate loop-merge-opt-64 /home/alumnos/a0405846/lab3/cache/loop_merge_opt.cpp > cg-loop-merge-opt-64.txt

# Tarea 2
# soa.cpp
valgrind --tool=cachegrind --cachegrind-out-file=soa-8 --D1=8192,4,64 --LL=262144,4,64 ./debug/soa > vg-soa-8.txt
cg_annotate soa-8 /home/alumnos/a0405846/lab3/cache/soa.cpp > cg-soa-8.txt

valgrind --tool=cachegrind --cachegrind-out-file=soa-16 --D1=16384,4,64 --LL=262144,4,64 ./debug/soa > vg-soa-16.txt
cg_annotate soa-16 /home/alumnos/a0405846/lab3/cache/soa.cpp > cg-soa-16.txt

valgrind --tool=cachegrind --cachegrind-out-file=soa-32 --D1=32768,4,64 --LL=262144,4,64 ./debug/soa > vg-soa-32.txt
cg_annotate soa-32 /home/alumnos/a0405846/lab3/cache/soa.cpp > cg-soa-32.txt

# aos.cpp
valgrind --tool=cachegrind --cachegrind-out-file=aos-8 --D1=8192,4,64 --LL=262144,4,64 ./debug/aos > vg-aos-8.txt
cg_annotate aos-8 /home/alumnos/a0405846/lab3/cache/aos.cpp > cg-aos-8.txt

valgrind --tool=cachegrind --cachegrind-out-file=aos-16 --D1=16384,4,64 --LL=262144,4,64 ./debug/aos > vg-aos-16.txt
cg_annotate aos-16 /home/alumnos/a0405846/lab3/cache/aos.cpp > cg-aos-16.txt

valgrind --tool=cachegrind --cachegrind-out-file=aos-32 --D1=32768,4,64 --LL=262144,4,64 ./debug/aos > vg-aos-32.txt
cg_annotate aos-32 /home/alumnos/a0405846/lab3/cache/aos.cpp > cg-aos-32.txt
