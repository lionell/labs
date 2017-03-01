#include <cstring>
#include <cassert>

#include <mpi.h>

#include "page.h"
#include "mpi_types.h"
#include "io.h"
#include "math.h"
#include "vars.h"
#include "logging.h"

const double kEps = 1e-7;
const double kS = 0.85;

namespace root {
void InitWorldPr() {
	for (int i = 0; i < world::page_cnt; i++) {
		world::pr[i] = 1.0 / world::page_cnt;
	}
}

void FindDanglingPages() {
	dangling_page_cnt = 0;
	for (int i = 0; i < world::page_cnt; i++) {
		dangling_page_cnt += world::out_link_cnts[i] == 0;
	}
	dangling_pages = new int[dangling_page_cnt];
	int j = 0;
	for (int i = 0; i < world::page_cnt; i++) {
		if (world::out_link_cnts[i] == 0) {
			dangling_pages[j++] = i;
		}
	}
}

void InitData(std::string db) {
	ReadMetadata(db, &world::page_cnt, &world::out_link_cnts);
	ReadPages(db, 0, world::page_cnt - 1, &pages);
	FindDanglingPages();
}

void HandlePagesFromRemainder() {
	int remainder = world::page_cnt % world::size;
	if (remainder == 0) return;
	// Let the root handle 'remainder' pages from the end
	// of the root::pages list. Thus we need to extend
	// root's proc::pages.
	Page *temp = new Page[proc::page_cnt + remainder];
	memcpy(temp, proc::pages, proc::page_cnt * sizeof(Page));
	int shift = world::page_cnt - remainder;
	memcpy(temp + proc::page_cnt, root::pages + shift,
		remainder * sizeof(Page));
	std::swap(proc::pages, temp);
	delete[] temp;
	proc::page_cnt += remainder;
}

void UpdatePrFromRemainder() {
	int remainder = world::page_cnt % world::size;
	int shift = world::page_cnt - remainder;
	memcpy(world::pr + shift, proc::pr + world::pages_per_proc,
		remainder * sizeof(double));
}

void UpdatePrWithDanglingPages(double *old_pr) {
	double sum = 0;
	for (int i = 0; i < root::dangling_page_cnt; i++) {
		sum += old_pr[root::dangling_pages[i]];
	}
	for (int i = 0; i < world::page_cnt; i++) {
		world::pr[i] += kS * sum / world::page_cnt;
	}
}

void UpdatePrWithRandomJumps() {
	for (int i = 0; i < world::page_cnt; i++) {
		world::pr[i] += (1 - kS) / world::page_cnt;
	}
}
}  // namespace root

namespace world {
void EvalPr() {
	for (int i = 0; i < proc::page_cnt; i++) {
		Page &page = proc::pages[i];
		double pr = 0;
		for (int j = 0; j < page.in_link_cnt; j++) {
			int from_page = page.in_links[j];
			pr += world::pr[from_page] / world::out_link_cnts[from_page];
		}
		proc::pr[i] = kS * pr;
	}
}
}  // namespace world

int main(int argc, char *argv[]) {
	using proc::rank;

	assert(argc >= 2);
	std::string db = argv[1];

	MPI_Init(nullptr, nullptr);
	RegisterMpiDatatypes();

	MPI_Comm_size(MPI_COMM_WORLD, &world::size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0) {
		VLOG(world::size);
	}

	if (rank == 0) {
		root::InitData(db);
	}
	MPI_Bcast(&world::page_cnt, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank > 0) {
		world::out_link_cnts = new int[world::page_cnt];
	}
	MPI_Bcast(world::out_link_cnts, world::page_cnt, MPI_INT, 0, MPI_COMM_WORLD);

	world::pages_per_proc = world::page_cnt / world::size;
	proc::pages = new Page[world::pages_per_proc];
	MPI_Scatter(root::pages, world::pages_per_proc, MPI_Page,
		proc::pages, world::pages_per_proc, MPI_Page,
		0, MPI_COMM_WORLD);

	// There can be some pages remainded.
	proc::page_cnt = world::pages_per_proc;
	if (rank == 0) {
		root::HandlePagesFromRemainder();
	}

	for (int i = 0; i < proc::page_cnt; i++) {
		VLog("id", proc::pages[i].id);
	}

	world::pr = new double[world::page_cnt];
	if (rank == 0) {
		root::InitWorldPr();
	}
	proc::pr = new double[proc::page_cnt];
	double *old_pr;
	if (rank == 0) {
		old_pr = new double[world::page_cnt];
	}
	world::go_on = true;
	int step = 0;
	while (world::go_on) {
		MPI_Bcast(world::pr, world::page_cnt, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		if (rank == 0) {
			memcpy(old_pr, world::pr, world::page_cnt * sizeof(double));
		}

		world::EvalPr();
		// NOTE! We use world::pages_per_proc instead of proc::page_cnt
		// to gather PRs. It's because size should remaind the same for
		// all the processes. Some part of PRs evaluated at root are not
		// going to be visible for MPI_Gather. But, it's OK until they
		// remain on host. We are going to account them later.
		MPI_Gather(proc::pr, world::pages_per_proc, MPI_DOUBLE,
				world::pr, world::pages_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

		if (rank == 0) {
			root::UpdatePrFromRemainder();
			root::UpdatePrWithDanglingPages(old_pr);
			root::UpdatePrWithRandomJumps();
			VLog("world::PR", Join(world::pr, world::page_cnt));

			double err = L2Norm(world::pr, old_pr, world::page_cnt);
			VLOG(err);
			world::go_on = err > kEps;
		}

		MPI_Bcast(&world::go_on, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
		step++;
	}
	if (rank == 0) {
		VLOG(step);
	}

	delete[] proc::pr;
	delete[] proc::pages;
	delete[] world::pr;
	delete[] world::out_link_cnts;
	if (rank == 0) {
		delete[] root::pages;
		delete[] root::dangling_pages;
	}

	FreeMpiDatatypes();
	MPI_Finalize();
	return 0;
}
