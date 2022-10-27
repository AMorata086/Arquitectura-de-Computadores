#!/bin/sh

perf stat -a ./image-aos ./input_dir ./output_dir copy > resultados_avignon/perf_aos_copy.pbm
perf stat -a ./image-aos ./input_dir ./output_dir mono > resultados_avignon/perf_aos_mono.pbm
perf stat -a ./image-aos ./input_dir ./output_dir gauss > resultados_avignon/perf_aos_gauss.pbm
perf stat -a ./image-aos ./input_dir ./output_dir histo > resultados_avignon/perf_aos_histo.pbm

perf stat -a ./image-soa ./input_dir ./output_dir copy > resultados_avignon/perf_soa_copy.pbm
perf stat -a ./image-soa ./input_dir ./output_dir mono > resultados_avignon/perf_soa_mono.pbm
perf stat -a ./image-soa ./input_dir ./output_dir gauss > resultados_avignon/perf_soa_gauss.pbm
perf stat -a ./image-soa ./input_dir ./output_dir histo > resultados_avignon/perf_soa_histo.pbm

perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-aos ./input_dir ./output_dir copy > resultados_avignon/ener_aos_copy.pbm
perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-aos ./input_dir ./output_dir mono > resultados_avignon/ener_aos_mono.pbm
perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-aos ./input_dir ./output_dir gauss > resultados_avignon/ener_aos_gauss.pbm
perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-aos ./input_dir ./output_dir histo > resultados_avignon/ener_aos_histo.pbm

perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-soa ./input_dir ./output_dir copy > resultados_avignon/ener_soa_copy.pbm
perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-soa ./input_dir ./output_dir mono > resultados_avignon/ener_soa_mono.pbm
perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-soa ./input_dir ./output_dir gauss > resultados_avignon/ener_soa_gauss.pbm
perf stat -a -e 'power/energy-cores/, power/energy-gpu/, power/energy-pkg/, power/energy-ram/' ./image-soa ./input_dir ./output_dir histo > resultados_avignon/ener_soa_histo.pbm