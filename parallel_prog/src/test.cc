#include <bits/stdc++.h>
#include <gflags/gflags.h>
#include "lib/io.h"

using namespace std;

int main(int argc, char *argv[]) {
	FLAGS_dataset = "/home/lionell/dev/labs/parallel_prog/data/generated/test";
	google::ParseCommandLineFlags(&argc, &argv, true /* remove_flags */);

	int page_cnt, chunk_size;
	vector<int> out_link_cnts;
	ReadMetadata(&page_cnt, &chunk_size, out_link_cnts);
	cout << page_cnt << " " << chunk_size << endl;
	for (int x : out_link_cnts) {
		cout << x << " ";
	}
	cout << endl;

	vector<pr::Page> pages;
	ReadPages(chunk_size, 0, page_cnt - 1, pages);
	for (int i = 0; i < page_cnt; i++) {
		pr::Page &page = pages[i];
		cout << page.id() << " " << page.in_links_size() << " ";
		for (int j = 0; j < page.in_links_size(); j++) {
			cout << page.in_links(j) << " ";
		}
		cout << endl;
	}

	google::ShutDownCommandLineFlags();
	return 0;
}
