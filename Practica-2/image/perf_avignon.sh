#!/bin/sh

# exportamos las bibliotecas de gcc 12
export LD_LIBRARY_PATH=/opt/gcc-12.1.0/lib64

#-----------------------------#
#                             #
# SCHEDULE = STATIC EXECUTION #
#                             #
#-----------------------------#
echo "==================================="
echo "<<STATIC>> SCHEDULING, <<1>> THREAD"
echo "==================================="

export OMP_NUM_THREADS=1
export OMP_SCHEDULE="static"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_1_static.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_1_static.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_1_static.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_1_static.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_1_static.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_1_static.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_1_static.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_1_static.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_1_static.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_1_static.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_1_static.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_1_static.pbm

echo "===================================="
echo "<<STATIC>> SCHEDULING, <<2>> THREADS"
echo "===================================="

export OMP_NUM_THREADS=2
export OMP_SCHEDULE="static"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_2_static.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_2_static.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_2_static.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_2_static.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_2_static.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_2_static.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_2_static.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_2_static.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_2_static.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_2_static.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_2_static.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_2_static.pbm

echo "===================================="
echo "<<STATIC>> SCHEDULING, <<4>> THREADS"
echo "===================================="

export OMP_NUM_THREADS=4
export OMP_SCHEDULE="static"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_4_static.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_4_static.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_4_static.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_4_static.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_4_static.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_4_static.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_4_static.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_4_static.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_4_static.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_4_static.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_4_static.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_4_static.pbm

echo "===================================="
echo "<<STATIC>> SCHEDULING, <<8>> THREADS"
echo "===================================="

export OMP_NUM_THREADS=8
export OMP_SCHEDULE="static"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_8_static.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_8_static.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_8_static.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_8_static.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_8_static.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_8_static.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_8_static.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_8_static.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_8_static.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_8_static.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_8_static.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_8_static.pbm

echo "====================================="
echo "<<STATIC>> SCHEDULING, <<16>> THREADS"
echo "====================================="

export OMP_NUM_THREADS=16
export OMP_SCHEDULE="static"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_16_static.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_16_static.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_16_static.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_16_static.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_16_static.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_16_static.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_16_static.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_16_static.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_16_static.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_16_static.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_16_static.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_16_static.pbm

#------------------------------#
#                              #
# SCHEDULE = DYNAMIC EXECUTION #
#                              #
#------------------------------#
echo "===================================="
echo "<<DYNAMIC>> SCHEDULING, <<1>> THREAD"
echo "===================================="

export OMP_NUM_THREADS=1
export OMP_SCHEDULE="dynamic"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_1_dynamic.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_1_dynamic.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_1_dynamic.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_1_dynamic.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_1_dynamic.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_1_dynamic.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_1_dynamic.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_1_dynamic.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_1_dynamic.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_1_dynamic.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_1_dynamic.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_1_dynamic.pbm

echo "====================================="
echo "<<DYNAMIC>> SCHEDULING, <<2>> THREADS"
echo "====================================="

export OMP_NUM_THREADS=2
export OMP_SCHEDULE="dynamic"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_2_dynamic.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_2_dynamic.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_2_dynamic.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_2_dynamic.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_2_dynamic.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_2_dynamic.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_2_dynamic.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_2_dynamic.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_2_dynamic.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_2_dynamic.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_2_dynamic.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_2_dynamic.pbm

echo "====================================="
echo "<<DYNAMIC>> SCHEDULING, <<4>> THREADS"
echo "====================================="

export OMP_NUM_THREADS=4
export OMP_SCHEDULE="dynamic"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_4_dynamic.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_4_dynamic.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_4_dynamic.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_4_dynamic.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_4_dynamic.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_4_dynamic.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_4_dynamic.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_4_dynamic.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_4_dynamic.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_4_dynamic.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_4_dynamic.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_4_dynamic.pbm

echo "====================================="
echo "<<DYNAMIC>> SCHEDULING, <<8>> THREADS"
echo "====================================="

export OMP_NUM_THREADS=8
export OMP_SCHEDULE="dynamic"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_8_dynamic.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_8_dynamic.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_8_dynamic.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_8_dynamic.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_8_dynamic.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_8_dynamic.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_8_dynamic.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_8_dynamic.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_8_dynamic.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_8_dynamic.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_8_dynamic.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_8_dynamic.pbm

echo "======================================"
echo "<<DYNAMIC>> SCHEDULING, <<16>> THREADS"
echo "======================================"

export OMP_NUM_THREADS=16
export OMP_SCHEDULE="dynamic"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_16_dynamic.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_16_dynamic.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_16_dynamic.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_16_dynamic.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_16_dynamic.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_16_dynamic.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_16_dynamic.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_16_dynamic.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_16_dynamic.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_16_dynamic.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_16_dynamic.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_16_dynamic.pbm

#-----------------------------#
#                             #
# SCHEDULE = GUIDED EXECUTION #
#                             #
#-----------------------------#
echo "==================================="
echo "<<GUIDED>> SCHEDULING, <<1>> THREAD"
echo "==================================="

export OMP_NUM_THREADS=1
export OMP_SCHEDULE="guided"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_1_guided.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_1_guided.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_1_guided.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_1_guided.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_1_guided.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_1_guided.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_1_guided.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_1_guided.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_1_guided.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_1_guided.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_1_guided.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_1_guided.pbm

echo "===================================="
echo "<<GUIDED>> SCHEDULING, <<2>> THREADS"
echo "===================================="

export OMP_NUM_THREADS=2
export OMP_SCHEDULE="guided"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_2_guided.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_2_guided.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_2_guided.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_2_guided.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_2_guided.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_2_guided.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_2_guided.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_2_guided.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_2_guided.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_2_guided.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_2_guided.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_2_guided.pbm

echo "===================================="
echo "<<GUIDED>> SCHEDULING, <<4>> THREADS"
echo "===================================="

export OMP_NUM_THREADS=4
export OMP_SCHEDULE="guided"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_4_guided.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_4_guided.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_4_guided.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_4_guided.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_4_guided.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_4_guided.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_4_guided.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_4_guided.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_4_guided.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_4_guided.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_4_guided.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_4_guided.pbm

echo "===================================="
echo "<<GUIDED>> SCHEDULING, <<8>> THREADS"
echo "===================================="

export OMP_NUM_THREADS=8
export OMP_SCHEDULE="guided"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_8_guided.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_8_guided.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_8_guided.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_8_guided.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_8_guided.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_8_guided.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_8_guided.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_8_guided.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_8_guided.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_8_guided.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_8_guided.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_8_guided.pbm

echo "====================================="
echo "<<GUIDED>> SCHEDULING, <<16>> THREADS"
echo "====================================="

export OMP_NUM_THREADS=16
export OMP_SCHEDULE="guided"

# IMG-AOS PROGRAM PERFORMANCE STATS #
echo "img-aos <mono> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_perf_16_guided.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgaos_mono_ener_16_guided.pbm

echo "img-aos <histo> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_perf_16_guided.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract histo > ./results/imgaos_histo_ener_16_guided.pbm

echo "img-aos <gauss> performance stats: " 
perf stat -a ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_perf_16_guided.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract gauss > ./results/imgaos_gauss_ener_16_guided.pbm

# IMG-SOA PROGRAM PERFORMANCE STATS #
echo "img-soa <mono> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract mono > ./results/imgsoa_mono_perf_16_guided.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-aos ./in ./extract mono > ./results/imgsoa_mono_ener_16_guided.pbm

echo "img-soa <histo> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_perf_16_guided.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract histo > ./results/imgsoa_histo_ener_16_guided.pbm

echo "img-soa <gauss> performance stats: " 
perf stat -a ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_perf_16_guided.pbm
echo "img-soa <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./release/img-soa ./in ./extract gauss > ./results/imgsoa_gauss_ener_16_guided.pbm