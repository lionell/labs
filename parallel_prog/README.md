# Parallel PageRank

Implementation of PageRank algorithm, using different parallelization approaches.
For now there are three of them available: serial(no parallelization),
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

> from Wikipedia
