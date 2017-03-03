MPICXX = mpic++
GFLAGS = -L/usr/lib -lgflags
FLAGS = $(GFLAGS)

all: pr
	mpirun -np 3 ./pr --dataset 'data/test'

clean:
	rm -f *.o pr

pr: main.o root.o io.o logging.o math.o
	$(MPICXX) $(FLAGS) -o pr main.o root.o io.o logging.o math.o

main.o: main.cc page.h io.h logging.h root.h
	$(MPICXX) $(FLAGS) -c main.cc

root.o: root.cc root.h page.h decls.h io.h math.h
	$(MPICXX) $(FLAGS) -c root.cc

io.o: io.cc io.h page.h
	$(MPICXX) $(FLAGS) -c io.cc

logging.o: logging.cc logging.h decls.h
	$(MPICXX) $(FLAGS) -c logging.cc

math.o: math.cc math.h
	$(MPICXX) $(FLAGS) -c math.cc
