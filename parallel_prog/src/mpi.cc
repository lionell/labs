#include <cstring> // memset

#include <mpi.h>
#include <gflags/gflags.h>

#include "lib/page.h"
#include "lib/io.h"
#include "lib/logging.h"
#include "lib/pagerank.h"
#include "lib/math.h"
#include "lib/utils.h"

DEFINE_string(dataset, "data/generated/ten_thousand", "Input dataset");
DEFINE_double(damping_factor, 0.85, "Param for PageRank");
DEFINE_double(eps, 1e-7, "Computation precision");
DEFINE_bool(verbose, false, "Print additional information");

// Contains variables shared across processes. We need to sync them all the time.
// That's why size of data here should be as minimal as possible.
namespace world {
int size;
int page_cnt;
int chunk_size;
int pages_per_proc;
double *pr;
int *out_link_cnts;
bool go_on;
}  // namespace world

// Variables that are specific for each processor.
namespace proc {
int rank;
int page_cnt;
Page *pages;
double *pr;
}  // namespace proc

// These data are only relevant to root processor. So there should not be general
// code that tries to access root data. Use if (rank == 0) {...} guard everywhere.
namespace root {
int dangling_page_cnt;
int *dangling_pages;
double *old_pr;
}  // namespace root

std::string Decorator(std::string s) {
	return "[" + std::to_string(proc::rank) + "]:" + s;
}

int main(int argc, char *argv[]) {
	using proc::rank;
	gflags::ParseCommandLineFlags(&argc, &argv, true /* remove_flags */);
	RegisterDecorator(Decorator);

	MPI_Init(nullptr, nullptr);
	MPI_Comm_size(MPI_COMM_WORLD, &world::size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0) {
		VLOG(world::size);
	}

	if (rank == 0) {
		ReadPageCount(FLAGS_dataset, &world::page_cnt);
		ReadChunkSize(FLAGS_dataset, &world::chunk_size);
		world::out_link_cnts = new int[world::page_cnt];
		ReadOutLinkCounts(FLAGS_dataset, world::page_cnt, world::out_link_cnts);
		ExploreDanglingPages(world::out_link_cnts, world::page_cnt,
				&root::dangling_page_cnt, &root::dangling_pages);
	}
	MPI_Bcast(&world::page_cnt, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&world::chunk_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank > 0) { // Already initialized on root.
		world::out_link_cnts = new int[world::page_cnt];
	}
	MPI_Bcast(world::out_link_cnts, world::page_cnt, MPI_INT, 0, MPI_COMM_WORLD);

	// Calculate data range to process on specific processor.
	world::pages_per_proc = world::page_cnt / world::size;
	proc::page_cnt = world::pages_per_proc;
	proc::pages = new Page[world::pages_per_proc];
	int begin = world::pages_per_proc * rank;
	int end = begin + world::pages_per_proc - 1;
	VLOG(begin);
	VLOG(end);
	ReadPages(FLAGS_dataset, world::chunk_size, begin, end, proc::pages);

	// If world::page_cnt % world::size != 0 then there are some pages remaining.
	// We are going to process them at root processor.
	int reminder_cnt = world::page_cnt % world::size;
	int reminder_begin = world::page_cnt - reminder_cnt;
	int reminder_end = world::page_cnt - 1;
	if (rank == 0) {
		if (reminder_cnt > 0) {
			proc::page_cnt += reminder_cnt;
			proc::pages = ExtendAndCopyArray(proc::pages, world::pages_per_proc, proc::page_cnt);
			ReadPages(FLAGS_dataset, world::chunk_size, reminder_begin, reminder_end,
					proc::pages + world::pages_per_proc);
			VLOG(reminder_begin);
			VLOG(reminder_end);
		}
	}

	world::pr = new double[world::page_cnt];
	if (rank == 0) {
		InitPr(world::pr, world::page_cnt);
	}
	proc::pr = new double[proc::page_cnt];
	if (rank == 0) {
		root::old_pr = new double[world::page_cnt];
	}
	world::go_on = true;
	int step = 0;
	while (world::go_on) {
		MPI_Bcast(world::pr, world::page_cnt, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		if (rank == 0) {
			memcpy(root::old_pr, world::pr, world::page_cnt * sizeof(double));
		}

		EvaluatePr(proc::pages, proc::page_cnt, world::pr, world::out_link_cnts, proc::pr);
		// NOTE! We use world::pages_per_proc instead of proc::page_cnt
		// to gather PRs. It's because size should remaind the same for
		// all the processes. Some part of PRs evaluated at root are not
		// going to be visible for MPI_Gather. But, it's OK until they
		// remain on host. We will account them later.
		MPI_Gather(proc::pr, world::pages_per_proc, MPI_DOUBLE,
				world::pr, world::pages_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

		if (rank == 0) {
			// Copy PR from reminder to world::pr.
			memcpy(world::pr + reminder_begin, proc::pr + world::pages_per_proc,
					reminder_cnt * sizeof(double));
			AddDanglingPagesPr(root::old_pr, world::page_cnt,
					root::dangling_pages, root::dangling_page_cnt, world::pr);
			AddRandomJumpsPr(world::pr, world::page_cnt);

			double err = L1Norm(world::pr, root::old_pr, world::page_cnt);
			world::go_on = err > FLAGS_eps;
		}

		MPI_Bcast(&world::go_on, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
		step++;
	}
	if (rank == 0) {
		VLOG(step);
		Print(world::pr, world::page_cnt);
	}

	delete[] proc::pr;
	delete[] proc::pages;
	delete[] world::pr;
	delete[] world::out_link_cnts;
	if (rank == 0) {
		delete[] root::old_pr;
		delete[] root::dangling_pages;
	}
	MPI_Finalize();
	gflags::ShutDownCommandLineFlags();
	return 0;
}
