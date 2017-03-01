#include <bits/stdc++.h>
#include <mpi.h>
#include "methods.h"

#define LOG(x) Log(#x " = " + to_string(x))

using namespace std;

const Float kEps = 1e-8;
int world_size, world_rank;

void Log(string s) {
	cout << "[" + to_string(world_rank) + "]: " + s + "\n";
}

Float Sin(Float x) {
	return 10000*sinl(sqrtl(x));
}

int main() {
	MPI_Init(nullptr, nullptr);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	if (world_rank == 0) {
		LOG(world_size);
	}

	Float a, b, max;
	if (world_rank == 0) {
		a = 50;
		b = 200;
		max = 50;
	}
	MPI_Bcast(&a, 1, kMpiFloat, 0, MPI_COMM_WORLD);
	MPI_Bcast(&b, 1, kMpiFloat, 0, MPI_COMM_WORLD);
	MPI_Bcast(&max, 1, kMpiFloat, 0, MPI_COMM_WORLD);

	cout.precision(25);
	Float c = a + (b - a) / world_size * world_rank;
	Float d = c + (b - a) / world_size;
	LOG(c);
	LOG(d);
	int n = TrapezoidMinN(c, d, max, kEps);
	LOG(n);
	Float res = Calc(c, d, n, Sin, Trapezoid);
	LOG(res);

	Float *results;
	if (world_rank == 0) {
		results = new Float[world_size];
	}
	MPI_Gather(&res, 1, kMpiFloat, results, 1, kMpiFloat, 0, MPI_COMM_WORLD);
	if (world_rank == 0) {
		Float ans = 0;
		for (int i = 0; i < world_size; i++) {
			ans += results[i];
		}
		LOG(ans);
	}

	MPI_Finalize();
	return 0;
}
