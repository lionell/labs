#ifndef PAGE_H_
#define PAGE_H_

const int kPageMaxLinkCnt = 100;

struct Page {
	int id;
	int in_link_cnt;
	int in_links[kPageMaxLinkCnt];
};

#endif  // PAGE_H_
