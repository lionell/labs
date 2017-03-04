MPICXX = mpic++
GFLAGS = -L/usr/lib -lgflags
FLAGS = $(GFLAGS)

all: pr
	mpirun -np 3 ./pr --dataset 'data/test' --chunk_size 2 --damping_factor 0.85 --eps 1e-7

clean:
	rm -f *.o pr

pr: main.o pagerank.o io.o math.o
	$(MPICXX) $(FLAGS) -o pr main.o pagerank.o io.o math.o

main.o: main.cc page.h io.h logging.h pagerank.h math.h utils.h
	$(MPICXX) $(FLAGS) -c main.cc

pagerank.o: pagerank.cc pagerank.h page.h math.h
	$(MPICXX) $(FLAGS) -c pagerank.cc

io.o: io.cc io.h page.h
	$(MPICXX) $(FLAGS) -c io.cc

math.o: math.cc math.h
	$(MPICXX) $(FLAGS) -c math.cc
