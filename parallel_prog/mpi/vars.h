#ifndef VARS_H_
#define VARS_H_

#include <string>
#include "page.h"

namespace world {
int size;
int page_cnt;
int pages_per_proc;
double *pr;
int *out_link_cnts;
bool go_on;
}  // namespace world

namespace proc {
int rank;
int page_cnt;
Page *pages;
double *pr;
}  // namespace proc

namespace root {
Page *pages;
int dangling_page_cnt;
int *dangling_pages;
}  // namespace root

#endif
