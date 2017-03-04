#ifndef PAGERANK_H_
#define PAGERANK_H_

#include <string>
#include "page.h"

void ExploreDanglingPages(int out_link_cnts[], int page_cnt,
		int *dangling_page_cnt_ptr, int *dangling_pages_ptr[]);
void InitPr(double pr[], int page_cnt);
void EvaluatePr(Page pages[], int page_cnt, double world_pr[],
		int out_link_cnts[], double new_pr[]);
void AddDanglingPagesPr(double old_pr[], int page_cnt, int dangling_pages[],
		int dangling_page_cnt, double pr[]);
void AddRandomJumpsPr(double pr[], int page_cnt);

#endif  // PAGERANK_H_
