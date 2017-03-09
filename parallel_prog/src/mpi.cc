#include <cstring> // memset

#include <mpi.h>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include "lib/page.h"
#include "lib/io.h"
#include "lib/pagerank.h"
#include "lib/math.h"
#include "lib/utils.h"
#include "lib/benchmark.h"

DEFINE_string(dataset, "data/generated/test", "Input dataset");
DEFINE_double(damping_factor, 0.85, "PageRank main parameter");
DEFINE_double(eps, 1e-7, "Computation precision");
DEFINE_string(output, "/home/lionell/dev/labs/parallel_prog/out/mpi",
		"Path to file where to store calculated PageRank");

int world_rank;

std::string GetProc() {
	return "[" + std::to_string(world_rank) + "]: ";
}

int main(int argc, char *argv[]) {
	FLAGS_logtostderr = 1;
	google::ParseCommandLineFlags(&argc, &argv, true /* remove_flags */);
	google::InitGoogleLogging(argv[0]);
	Timer timer;

	MPI_Init(nullptr, nullptr);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	if (world_rank == 0) {
		LOG(INFO) << "World size: " << world_size;
	}

	int global_page_cnt, chunk_size, *out_link_cnts, dangling_page_cnt,
			*dangling_pages;
	if (world_rank == 0) {
		ReadPageCount(FLAGS_dataset, &global_page_cnt);
		ReadChunkSize(FLAGS_dataset, &chunk_size);
		out_link_cnts = new int[global_page_cnt];
		ReadOutLinkCounts(FLAGS_dataset, global_page_cnt, out_link_cnts);

		ExploreDanglingPages(out_link_cnts, global_page_cnt,
				&dangling_page_cnt, &dangling_pages);
	}
	MPI_Bcast(&global_page_cnt, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&chunk_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (world_rank > 0) { // Already initialized on root.
		out_link_cnts = new int[global_page_cnt];
	}
	MPI_Bcast(out_link_cnts, global_page_cnt, MPI_INT, 0, MPI_COMM_WORLD);

	// Calculate data range to process on specific processor.
	int pages_per_proc = global_page_cnt / world_size;
	int page_cnt = pages_per_proc;
	int begin = pages_per_proc * world_rank;
	int end = begin + pages_per_proc - 1;
	LOG(INFO) << GetProc() << "Handling pages " << begin << "..." << end << ".";

	Page *pages = new Page[pages_per_proc];
	timer.Start();
	ReadPages(FLAGS_dataset, chunk_size, begin, end, pages);
	timer.StopAndReport(GetProc() + "Reading pages");

	// If global_page_cnt % world::size != 0 then there are some pages remaining.
	// We are going to process them at root processor.
	int reminder_cnt = global_page_cnt % world_size;
	int reminder_begin = global_page_cnt - reminder_cnt;
	int reminder_end = global_page_cnt - 1;
	if (world_rank == 0) {
		if (reminder_cnt > 0) {
			LOG(INFO) << "Reminder " << reminder_begin << "..." << reminder_end
				<< ".";

			page_cnt += reminder_cnt;
			pages = ExtendAndCopyArray(pages, pages_per_proc, page_cnt);

			timer.Start();
			ReadPages(FLAGS_dataset, chunk_size, reminder_begin, reminder_end,
					pages + pages_per_proc);
			timer.StopAndReport("Reading reminder pages");
		}
	}

	double *global_pr = new double[global_page_cnt];
	double *pr = new double[page_cnt];
	double *old_pr;
	if (world_rank == 0) {
		InitPr(global_pr, global_page_cnt);
		old_pr = new double[global_page_cnt];
	}

	MPI_Barrier(MPI_COMM_WORLD);
	timer.Start();
	bool go_on = true;
	int step = 0;
	while (go_on) {
		MPI_Bcast(global_pr, global_page_cnt, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		if (world_rank == 0) {
			memcpy(old_pr, global_pr, global_page_cnt * sizeof(double));
		}

		EvaluatePr(pages, page_cnt, global_pr, out_link_cnts, pr);
		// NOTE! We use world::pages_per_proc instead of page_cnt
		// to gather PRs. It's because size should remaind the same for
		// all the processes. Some part of PRs evaluated at root are not
		// going to be visible for MPI_Gather. But, it's OK until they
		// remain on host. We will account them later.
		MPI_Gather(pr, pages_per_proc, MPI_DOUBLE,
				global_pr, pages_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

		if (world_rank == 0) {
			memcpy(global_pr + reminder_begin, pr + pages_per_proc,
					reminder_cnt * sizeof(double));
			AddDanglingPagesPr(old_pr, global_page_cnt,
					dangling_pages, dangling_page_cnt, global_pr);
			AddRandomJumpsPr(global_pr, global_page_cnt);

			double err = L1Norm(global_pr, old_pr, global_page_cnt);
			LOG(INFO) << "Error " << err << " at step " << step + 1;
			go_on = err > FLAGS_eps;
		}

		MPI_Bcast(&go_on, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
		step++;
	}
	MPI_Barrier(MPI_COMM_WORLD);
	timer.StopAndReport("PageRank");

	if (world_rank == 0) {
		LOG(INFO) << "Number of steps: " << step;
		WritePrToFile(FLAGS_output, global_pr, global_page_cnt);
	}

	delete[] pr;
	delete[] global_pr;
	delete[] pages;
	delete[] out_link_cnts;
	if (world_rank == 0) {
		delete[] old_pr;
		delete[] dangling_pages;
	}

	MPI_Finalize();
	google::ShutDownCommandLineFlags();
	return 0;
}
