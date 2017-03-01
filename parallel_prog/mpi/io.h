#ifndef IO_H_
#define IO_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>

#include "page.h"
#include "logging.h"

const int kChunkSize = 2;
const std::string kDataFilepath =
	"/home/lionell/dev/labs/parallel_prog/mpi/data/";

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
int ReadPagesFromChunk(std::string db, int chunk, int begin, int end,
		Page pages[]) {
	std::ifstream in(kDataFilepath + db + std::to_string(chunk) + ".chnk");
	int chunk_begin = chunk * kChunkSize;
	int chunk_end = chunk_begin + kChunkSize;
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

void ReadPages(std::string db, int begin, int end, Page *pages_ptr[]) {
	Page *pages = new Page[end - begin + 1];
	int begin_chunk = begin / kChunkSize;
	int end_chunk = end / kChunkSize;
	VLOG(begin_chunk);
	VLOG(end_chunk);
	int index = 0;
	for (int chunk = begin_chunk; chunk <= end_chunk; chunk++) {
		index += ReadPagesFromChunk(db, chunk, begin, end, pages + index);
	}
	*pages_ptr = pages;
}

void ReadMetadata(std::string db, int *page_cnt_ptr, int *out_link_cnts_ptr[]) {
	std::ifstream in(kDataFilepath + db + ".meta");
	int page_cnt;
	in >> page_cnt;
	int *out_link_cnts = new int[page_cnt];
	for (int i = 0; i < page_cnt; i++) {
		in >> out_link_cnts[i];
	}
	*page_cnt_ptr = page_cnt;
	*out_link_cnts_ptr = out_link_cnts;
}

#endif // IO_H_
