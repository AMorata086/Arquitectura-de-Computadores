#!/bin/sh


# perf stat <nombre_programa> > <output.pbm>
perf stat ./release/bpred1 > 3_2task.pbm
echo "Finalizada parte 3.2"
# perf stat -a -e 'branch-instructions,branch-misses' <nombre_programa> 8000 > <output.pbm>
perf stat -e 'branch-instructions,branch-misses' ./release/bpred1 > 3_3task.pbm
echo "Finalizada parte 3.3"
perf stat ./release/bpred2 > 3_4task.pbm
echo "Finalizada parte 3.4"
perf stat ./release/bpred3 > 3_5task.pbm
echo "Finalizada parte 3.5"