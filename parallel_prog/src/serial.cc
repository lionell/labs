#include <bits/stdc++.h>

#include <gflags/gflags.h>

#include "lib/page.h"
#include "lib/io.h"
#include "lib/math.h"
#include "lib/pagerank.h"
#include "lib/utils.h"
#include "lib/logging.h"

DEFINE_string(dataset, "data/test", "Input dataset");
DEFINE_int32(chunk_size, 2, "Number of pages per chunk");
DEFINE_double(damping_factor, 0.85, "Param for PageRank");
DEFINE_double(eps, 1e-7, "Computation precision");
DEFINE_string(output, "/home/lionell/dev/labs/parallel_prog/out/serial.out",
		"Where to put results");

int main(int argc, char *argv[]) {
	gflags::ParseCommandLineFlags(&argc, &argv, true /* remove_flags */);

	int page_cnt;
	ReadPageCount(&page_cnt);
	int *out_link_cnts = new int[page_cnt];
	ReadOutLinkCounts(page_cnt, out_link_cnts);
	Page *pages = new Page[page_cnt];
	ReadPages(0, page_cnt, pages);
	int dangling_page_cnt, *dangling_pages;
	ExploreDanglingPages(out_link_cnts, page_cnt,
			&dangling_page_cnt, &dangling_pages);

	double *pr = new double[page_cnt];
	InitPr(pr, page_cnt);
	double *old_pr = new double[page_cnt];
	bool go_on = true;
	int step = 0;
	while (go_on) {
		memcpy(old_pr, pr, page_cnt * sizeof(double));
		EvaluatePr(pages, page_cnt, old_pr, out_link_cnts, pr);
		AddDanglingPagesPr(old_pr, page_cnt, dangling_pages, dangling_page_cnt, pr);
		AddRandomJumpsPr(pr, page_cnt);

		double err = L2Norm(pr, old_pr, page_cnt);
		go_on = err > FLAGS_eps;
		step++;
	}
	VLOG(step);
	VLog("PageRank", pr, page_cnt);
	WritePrToFile(pr, page_cnt);

	delete[] old_pr;
	delete[] pr;
	delete[] out_link_cnts;
	delete[] pages;
	gflags::ShutDownCommandLineFlags();
	return 0;
}
