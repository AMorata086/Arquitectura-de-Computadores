#!/bin/sh

# Script para la ejecucion de los stats de energia y rendimiento

# exportamos las bibliotecas de gcc 12
export LD_LIBRARY_PATH=/opt/gcc-12.1.0/lib64

# TEMPLATE:
# echo "<program_name> performance stats: " 
# perf stat -a ./<program_name> ../in ../extract <operation> > ../results/<nombre_archivo>.pbm
# echo "<program_name> energy stats: " 
# perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./<program_name> ../in ../extract <operation> > ../results/<nombre_archivo>.perf

#####################################
# IMG-AOS PROGRAM PERFORMANCE STATS #
#####################################

echo "img-aos <mono> performance stats: " 
perf stat -a ./img-aos ../in ../extract mono > ../results/imgaos_mono_perf_1_dynamic.pbm
echo "img-aos <mono> energy stats: "
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./img-aos ../in ../extract mono > ../results/imgaos_histo_ener_1_dynamic.perf

echo "img-aos <histo> performance stats: " 
perf stat -a ./img-aos ../in ../extract histo > ../results/imgaos_mono_perf_1_dynamic.pbm
echo "img-aos <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./img-aos ../in ../extract histo > ../results/imgaos_histo_ener_1_dynamic.perf

echo "img-aos <gauss> performance stats: " 
perf stat -a ./img-aos ../in ../extract gauss > ../results/imgaos_gauss_perf_1_dynamic.pbm
echo "img-aos <gauss> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./img-aos ../in ../extract gauss > ../results/imgaos_gauss_ener_1_dynamic.perf

#####################################
# IMG-SOA PROGRAM PERFORMANCE STATS #
#####################################

echo "img-soa <mono> performance stats: " 
perf stat -a ./img-soa ../in ../extract mono > ../results/imgsoa_mono_perf_1_dynamic.pbm
echo "img-soa <mono> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./img-aos ../in ../extract mono > ../results/imgsoa_mono_ener_1_dynamic.perf

echo "img-soa <histo> performance stats: " 
perf stat -a ./img-soa ../in ../extract histo > ../results/imgsoa_histo_perf_1_dynamic.pbm
echo "img-soa <histo> energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./img-soa ../in ../extract histo > ../results/imgsoa_histo_ener_1_dynamic.perf

echo "img-soa_gauss performance stats: " 
perf stat -a ./img-soa ../in ../extract gauss > ../results/imgsoa_gauss_perf_1_dynamic.pbm
echo "img-soa_gauss energy stats: " 
perf stat -a -e 'energy-cores,energy-gpu,energy-pkg,energy-ram' ./img-soa ../in ../extract gauss > ../results/imgsoa_gauss_ener_1_dynamic.perf