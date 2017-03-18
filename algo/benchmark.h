#include <chrono>

#include <glog/logging.h>

using namespace std::chrono;
using namespace std;

class Timer {
	high_resolution_clock::time_point wall_start;
	high_resolution_clock::time_point wall_finish;
	clock_t cpu_start;
	clock_t cpu_finish;

public:
	Timer() {}

	void Start() {
		wall_start = high_resolution_clock::now();
		cpu_start = clock();
	}

	void Stop() {
		wall_finish = high_resolution_clock::now();
		cpu_finish = clock();
	}

	double GetWallDuration() {
		return duration_cast<milliseconds>(wall_finish - wall_start).count()
			/ 1000.0;
	}

	double GetCpuDuration() {
		return (cpu_finish - cpu_start) / double(CLOCKS_PER_SEC);
	}

	void Report(string event) {
		LOG(INFO) << event + " took " + to_string(GetCpuDuration())
			+ "s cpu, " + to_string(GetWallDuration()) + "s wall.";
	}

	void StopAndReport(string event) {
		Stop();
		Report(event);
	}
};
