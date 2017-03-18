#include <bits/stdc++.h>

#include <omp.h>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include "benchmark.h"
#include "io.h"

using namespace std;

typedef uint32_t ui32;
typedef uint64_t ui64;

DEFINE_string(output, "", "Output filepath");
DEFINE_int32(M, 5009*2 + 1, "Generator base");
DEFINE_int32(k, 1, "Number of threads");
DEFINE_int32(r, 32, "Exponent of modulo");
DEFINE_int32(u0, 1234, "Random seed");
DEFINE_int64(n, 10, "Amount of numbers per thread");

ui32 Mul(ui32 a, ui32 b, ui32 R) {
	return (ui64(a) * b) % R;
}

string GetThread() {
	return "[" + to_string(omp_get_thread_num()) + "]: ";
}

void Generate(ui64 n, ui32 u0, ui32 M, ui32 R, OutStream &out) {
	LOG(INFO) << GetThread() << "u0=" << u0;
	while (n--) {
		out << u0;
		u0 = Mul(u0, M, R);
	}
}

ui32 pow(ui32 a, ui32 b, ui32 R) {
	ui32 ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans = Mul(ans, a, R);
		}
		a = Mul(a, a, R);
		b >>= 1;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	FLAGS_logtostderr = 1;
	google::ParseCommandLineFlags(&argc, &argv, true /* remove_flags */);
	google::InitGoogleLogging(argv[0]);

	ui32 R = (ui64(1) << FLAGS_r) - 1;
	ui32 M = FLAGS_M % R;
	ui32 Mk = pow(M, FLAGS_k, R);
	LOG(INFO) << "R=" << R << ", M=" << M << ", M^k=" << Mk;

	Timer timer; timer.Start();
	ui32 i;
#pragma omp parallel for num_threads(FLAGS_k)
	for (i = 0; i < FLAGS_k; i++) {
		string file;
		if (!FLAGS_output.empty()) {
			file = FLAGS_output + "." + to_string(i);
		}
		OutFileStream out(file);
		ui32 u0 = Mul(FLAGS_u0, pow(M, i, R), R);
		Generate(FLAGS_n, u0, Mk, R, out);
	}
	timer.StopAndReport("Generation");

	google::ShutDownCommandLineFlags();
	return 0;
}
