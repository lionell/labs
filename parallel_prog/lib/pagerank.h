#ifndef PAGERANK_H_
#define PAGERANK_H_

#include <string>
#include <vector>

#include "proto/page.pb.h"

std::vector<int> ExploreDanglingPages(const std::vector<int> &out_link_cnts);
std::vector<double> InitPr(int page_cnt);
void AddPagesPr(
		const std::vector<pr::Page> &pages,
		const std::vector<int> &out_link_cnts,
		const std::vector<double> &old_pr,
		std::vector<double> &new_pr);
void AddDanglingPagesPr(
		double damping_factor,
		const std::vector<int> &dangling_pages, 
		const std::vector<double> &old_pr,
		std::vector<double> &new_pr);
void AddRandomJumpsPr(double damping_factor, std::vector<double> &new_pr);

#endif  // PAGERANK_H_
