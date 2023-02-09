#!/bin/sh

perf stat -a ./image-aos ./input_dir ./output_dir copy > resultados_avignon/perf_aos_copy.pbm
echo "Ejecución de aos copy finalizada"

perf stat -a ./image-aos ./input_dir ./output_dir mono > resultados_avignon/perf_aos_mono.pbm
echo "Ejecución de aos mono finalizada"

perf stat -a ./image-aos ./input_dir ./output_dir gauss > resultados_avignon/perf_aos_gauss.pbm
echo "Ejecución de aos gauss finalizada"

perf stat -a ./image-aos ./input_dir ./output_dir histo > resultados_avignon/perf_aos_histo.pbm
echo "Ejecución de aos histo finalizada"

perf stat -a ./image-soa ./input_dir ./output_dir copy > resultados_avignon/perf_soa_copy.pbm
echo "Ejecución de soa copy finalizada"

perf stat -a ./image-soa ./input_dir ./output_dir mono > resultados_avignon/perf_soa_mono.pbm
echo "Ejecución de soa mono finalizada"

perf stat -a ./image-soa ./input_dir ./output_dir gauss > resultados_avignon/perf_soa_gauss.pbm
echo "Ejecución de soa gauss finalizada"

perf stat -a ./image-soa ./input_dir ./output_dir histo > resultados_avignon/perf_soa_histo.pbm
echo "Ejecución de soa histo finalizada"