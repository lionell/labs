#include "io.h"

#include <limits>
#include <sstream>

#include <gflags/gflags.h>

DECLARE_string(dataset);
DECLARE_int32(chunk_size);

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
 * NOTE! It's not necessary that begin >= chunk_begin, or end < chunk_end.
 * Bounds are going to be truncated anyway.
 */
int ReadPagesFromChunk(int chunk, int begin, int end, Page pages[]) {
	std::ifstream in(FLAGS_dataset + std::to_string(chunk) + ".chnk");
	int chunk_begin = chunk * FLAGS_chunk_size;
	int chunk_end = chunk_begin + FLAGS_chunk_size;
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

void ReadPages(int begin, int end, Page pages[]) {
	int begin_chunk = begin / FLAGS_chunk_size;
	int end_chunk = end / FLAGS_chunk_size;
	int index = 0;
	for (int chunk = begin_chunk; chunk <= end_chunk; chunk++) {
		index += ReadPagesFromChunk(chunk, begin, end, pages + index);
	}
}

void ReadPageCount(int *page_cnt_ptr) {
	std::ifstream in(FLAGS_dataset + ".meta");
	int page_cnt;
	in >> page_cnt;
	*page_cnt_ptr = page_cnt;
}

void ReadOutLinkCounts(int page_cnt, int out_link_cnts[]) {
	std::ifstream in(FLAGS_dataset + ".meta");
	int ignore;
	in >> ignore;
	for (int i = 0; i < page_cnt; i++) {
		in >> out_link_cnts[i];
	}
}
