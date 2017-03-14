# Parallel PageRank

Implementation of PageRank algorithm, using different parallelization approaches.
For now there are three of them available: Serial(no parallelization),
OpenMP(shared memory), MPI(communication via network). We are going to benchmark
them on different datasets.

## PageRank

PageRank is an algorithm used by Google Search to rank websites in their search engine results.
PageRank was named after Larry Page, one of the founders of Google.
PageRank is a way of measuring the importance of website pages. According to Google:

> PageRank works by counting the number and quality of links to a page to determine
> a rough estimate of how important the website is. The underlying assumption is that
> more important websites are likely to receive more links from other websites.

It is not the only algorithm used by Google to order search engine results,
but it is the first algorithm that was used by the company, and it is the best-known.

## Algorithm

There are different approaches of PageRank evaluation. They mostly differ in underlying
data structure(there is also MapReduce version). Method we used is great for distributed
computing, because we can minimize data transfered via network, and gain benefit from
shared memory.

For now we are going to call graph vertecies - pages. For each page we store list of
in-links. Eg. [3, 0, 1] means that our page has in-links from pages 0, 1 and 3.
Also we need to store amount of out-links for every page. Having these let's take a
look how we can compute PageRank efficiently.

Basically all approaches to computed PageRank are **iterative**. Let's divide one iteration
into three parts: PR from pages, PR from dangling pages and PR from random jumps.

To compute PR from pages, we need to spread old PR(from previous iteration) across all the
pages linked with current. For example, if there are links from page 1 to pages 0, 2, 4, then
each of these pages will receive additional `PR[0] / 3` PageRank.

As you can see, we can use our data representation to compute this part. To compute PR of
some particular page, we can sum PRs of all in-pages divided by out link count for each page.

```
PR1[i] = PR[in_links[0]] / out_link_cnts[in_links[0]] + ... + PR[in_links[k]] / out_link_cnts[in_links[k]]
```
