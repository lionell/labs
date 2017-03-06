#ifndef IO_H_
#define IO_H_

#include <fstream>

#include "page.h"

void ReadPagesFromStream(std::ifstream &in, int cnt, Page pages[]);
int ReadPagesFromChunk(int chunk, int begin, int end, Page pages[]);
void ReadPages(int begin, int end, Page pages[]);
void ReadPageCount(int *page_cnt_ptr);
void ReadOutLinkCounts(int page_cnt, int out_link_cnts[]);
void WritePrToFile(double pr[], int page_cnt);

#endif  // IO_H_
