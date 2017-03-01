MPICC = mpic++

all: run

clean:
	rm -f *.o mpi main

run: mpi
	mpirun -n 4 ./mpi

mpi: mpi.cc methods.o
	$(MPICC) -o mpi mpi.cc methods.o

main: main.cc methods.o
	$(CXX) -o main main.cc methods.o

methods.o: methods.cc methods.h
	$(CXX) -c methods.cc
