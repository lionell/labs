#ifndef DECLS_H_
#define DECLS_H_

#include <string>

#include "page.h"

namespace world {
extern int size;
extern int page_cnt;
extern int pages_per_proc;
extern double *pr;
extern int *out_link_cnts;
extern bool go_on;
}  // namespace world

namespace proc {
extern int rank;
extern int page_cnt;
extern Page *pages;
extern double *pr;
}  // namespace proc

namespace root {
extern Page *pages;
extern int dangling_page_cnt;
extern int *dangling_pages;
extern double *old_pr;
}  // namespace root

#endif  // DECLS_H_
