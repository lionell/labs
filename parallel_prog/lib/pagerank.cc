#include "pagerank.h"

#include <cstring>

#include <gflags/gflags.h>

#include "math.h"

DECLARE_double(damping_factor);

void ExploreDanglingPages(int out_link_cnts[], int page_cnt,
		int *dangling_page_cnt_ptr, int *dangling_pages_ptr[]) {
	int dangling_page_cnt = 0;
	for (int i = 0; i < page_cnt; i++) {
		dangling_page_cnt += out_link_cnts[i] == 0;
	}
	int *dangling_pages = new int[dangling_page_cnt];
	int j = 0;
	for (int i = 0; i < page_cnt; i++) {
		if (out_link_cnts[i] == 0) {
			dangling_pages[j++] = i;
		}
	}
	*dangling_page_cnt_ptr = dangling_page_cnt;
	*dangling_pages_ptr = dangling_pages;
}

void InitPr(double pr[], int page_cnt) {
	for (int i = 0; i < page_cnt; i++) {
		pr[i] = 1.0 / page_cnt;
	}
}

void EvaluatePr(Page pages[], int page_cnt, double world_pr[],
		int out_link_cnts[], double new_pr[]) {
	for (int i = 0; i < page_cnt; i++) {
		Page &page = pages[i];
		double pr = 0;
		for (int j = 0; j < page.in_link_cnt; j++) {
			int from_page = page.in_links[j];
			pr += world_pr[from_page] / out_link_cnts[from_page];
		}
		new_pr[i] = pr;
	}
}

void AddDanglingPagesPr(double old_pr[], int page_cnt, int dangling_pages[],
		int dangling_page_cnt, double pr[]) {
	double sum = 0;
	for (int i = 0; i < dangling_page_cnt; i++) {
		sum += old_pr[dangling_pages[i]];
	}
	for (int i = 0; i < page_cnt; i++) {
		pr[i] += sum / page_cnt;
		pr[i] *= FLAGS_damping_factor;
	}
}

void AddRandomJumpsPr(double pr[], int page_cnt) {
	for (int i = 0; i < page_cnt; i++) {
		pr[i] += (1 - FLAGS_damping_factor) / page_cnt;
	}
}
