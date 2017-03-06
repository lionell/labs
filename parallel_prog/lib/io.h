#ifndef IO_H_
#define IO_H_

#include <fstream>

#include "page.h"

void ReadPagesFromStream(std::ifstream &in, int cnt, Page pages[]);
int ReadPagesFromChunk(std::string dataset, int chunk_size, int chunk,
		int begin, int end, Page pages[]);
void ReadPages(std::string dataset, int chunk_size, int begin, int end,
		Page pages[]);
void ReadPageCount(std::string dataset, int *page_cnt_ptr);
void ReadChunkSize(std::string dataset, int *chunk_size_ptr);
void ReadOutLinkCounts(std::string dataset, int page_cnt,
		int out_link_cnts[]);

#endif  // IO_H_
