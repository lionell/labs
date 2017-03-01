MPICC = mpic++

all: main
	mpirun -n 3 ./pr test

clean:
	rm -f *.o *.gch pr

main: main.cc mpi_types.h io.h math.h vars.h
	$(MPICC) -o pr main.cc mpi_types.h io.h math.h vars.h
