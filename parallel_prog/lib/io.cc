#include "io.h"

#include <limits>
#include <sstream>

void ReadPagesFromStream(std::ifstream &in, int cnt, Page pages[]) {
	for (int i = 0; i < cnt; i++) {
		Page &page = pages[i];
		in >> page.id >> page.in_link_cnt;
		for (int j = 0; j < page.in_link_cnt; j++) {
			in >> page.in_links[j];
		}
	}
}

/*
 * NOTE! It's possible that begin >= chunk_begin, or end < chunk_end.
 * Bounds are going to be truncated.
 */
int ReadPagesFromChunk(std::string dataset, int chunk_size, int chunk,
		int begin, int end, Page pages[]) {
	std::ifstream in(dataset + "_" + std::to_string(chunk) + ".chnk");
	int chunk_begin = chunk * chunk_size;
	int chunk_end = chunk_begin + chunk_size;
	if (begin < chunk_begin) begin = chunk_begin;
	if (end >= chunk_end) end = chunk_end - 1;
	int shift = begin - chunk_begin;
	while (shift--) {
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	int cnt = end - begin + 1;
	ReadPagesFromStream(in, cnt, pages);
	return cnt;
}

void ReadPages(std::string dataset, int chunk_size, int begin, int end,
		Page pages[]) {
	int begin_chunk = begin / chunk_size;
	int end_chunk = end / chunk_size;
	int index = 0;
	for (int chunk = begin_chunk; chunk <= end_chunk; chunk++) {
		index += ReadPagesFromChunk(dataset, chunk_size, chunk, begin, end,
				pages + index);
	}
}

void ReadPageCount(std::string dataset, int *page_cnt_ptr) {
	std::ifstream in(dataset + ".meta");
	in >> *page_cnt_ptr;
}

void ReadChunkSize(std::string dataset, int *chunk_size_ptr) {
	std::ifstream in(dataset + ".meta");
	int ignore;
	in >> ignore >> *chunk_size_ptr;
}

void ReadOutLinkCounts(std::string dataset, int page_cnt,
		int out_link_cnts[]) {
	std::ifstream in(dataset + ".meta");
	int ignore;
	in >> ignore >> ignore;
	for (int i = 0; i < page_cnt; i++) {
		in >> out_link_cnts[i];
	}
}
