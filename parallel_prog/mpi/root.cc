#include "root.h"

#include <cstring>

#include <gflags/gflags.h>

#include "page.h"
#include "decls.h"
#include "io.h"
#include "math.h"

DECLARE_double(damping_factor);

void InitMetadata() {
	ReadPageCount(&world::page_cnt);
	world::out_link_cnts = new int[world::page_cnt];
	ReadOutLinkCounts(world::page_cnt, world::out_link_cnts);
	ExploreDanglingPages();
}

void ExploreDanglingPages() {
	root::dangling_page_cnt = 0;
	for (int i = 0; i < world::page_cnt; i++) {
		root::dangling_page_cnt += world::out_link_cnts[i] == 0;
	}
	root::dangling_pages = new int[root::dangling_page_cnt];
	int j = 0;
	for (int i = 0; i < world::page_cnt; i++) {
		if (world::out_link_cnts[i] == 0) {
			root::dangling_pages[j++] = i;
		}
	}
}

void InitWorldPr() {
	for (int i = 0; i < world::page_cnt; i++) {
		world::pr[i] = 1.0 / world::page_cnt;
	}
}

void ReadReminderPages() {
	int remainder = world::page_cnt % world::size;
	if (remainder == 0) return;
	// Let the root handle 'remainder' pages from the end
	// of the root::pages list. Thus we need to extend
	// root's proc::pages.
	Page *temp = new Page[proc::page_cnt + remainder];
	memcpy(temp, proc::pages, proc::page_cnt * sizeof(Page));
	int end = world::page_cnt - 1;
	int begin = end - remainder + 1;
	ReadPages(begin, end, temp + proc::page_cnt);
	std::swap(proc::pages, temp);
	delete[] temp;
	proc::page_cnt += remainder;
}

void AddRemainderPr() {
	int remainder = world::page_cnt % world::size;
	int shift = world::page_cnt - remainder;
	memcpy(world::pr + shift, proc::pr + world::pages_per_proc,
		remainder * sizeof(double));
}

void AddDanglingPagesPr() {
	double sum = 0;
	for (int i = 0; i < root::dangling_page_cnt; i++) {
		sum += root::old_pr[root::dangling_pages[i]];
	}
	for (int i = 0; i < world::page_cnt; i++) {
		world::pr[i] += sum / world::page_cnt;
		world::pr[i] *= FLAGS_damping_factor;
	}
}

void AddRandomJumpsPr() {
	for (int i = 0; i < world::page_cnt; i++) {
		world::pr[i] += (1 - FLAGS_damping_factor) / world::page_cnt;
	}
}

double EvaluateError() {
	return L2Norm(world::pr, root::old_pr, world::page_cnt);
}
