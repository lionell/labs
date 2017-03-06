#!/usr/bin/env python3
import argparse
import random
import math

parser = argparse.ArgumentParser()
parser.add_argument("name", help="Name of generated dataset", type=str)
parser.add_argument("--page_cnt", help="Number of pages", type=int, default=10)
parser.add_argument("--max_in_link_cnt",
        help="Hard limit of in-links per page", type=int, default=100)
parser.add_argument("--sort_links", help="If it's true than in-links are \
        going to appear in a sorted order", action="store_true")
parser.add_argument("--output_path", help="Path to store generated dataset",
        type=str, default="/home/lionell/dev/labs/parallel_prog/data/generated/"
        )
parser.add_argument("--chunk_size", help="Maximum of links per chunk",
        type=int, default=2)
args = parser.parse_args()

if args.max_in_link_cnt > args.page_cnt - 1:
    args.max_in_link_cnt = args.page_cnt - 1
    print("Warning! Using {} as max_in_link_cnt.".format(args.max_in_link_cnt))

def generate_graph(page_cnt, max_in_link_cnt):
    links_per_page = []
    for i in range(page_cnt):
        links_cnt = random.randint(0, max_in_link_cnt)
        links = random.sample(range(page_cnt), links_cnt)
        if (args.sort_links):
            links.sort()
        links_per_page.append(links);
        print(links_cnt, links)
    return links_per_page

def calculate_out_link_cnts(links):
    page_cnt = len(links)
    out_link_cnts = [0] * page_cnt
    for page in links:
        for link in page:
            out_link_cnts[link] += 1
    return out_link_cnts

def write_metadata(path, out_link_cnts):
    with open(path + ".meta", "w") as f:
        f.write(str(len(out_link_cnts)) + "\n")
        f.write(" ".join(map(str, out_link_cnts)))

def write_links(path, links, chunk_size):
    page_cnt = len(links)
    chunk_cnt = math.ceil(page_cnt / chunk_size)
    i = 0
    for chunk in range(chunk_cnt):
        with open(path + str(chunk) + ".chnk", "w") as f:
            for page in range(chunk_size):
                f.write(str(i) + " ")
                f.write(str(len(links[i])) + " ")
                f.write(" ".join(map(str, links[i])) + "\n")
                i += 1
                if i == page_cnt:
                    break

links = generate_graph(args.page_cnt, args.max_in_link_cnt)
out_link_cnts = calculate_out_link_cnts(links)

full_path = args.output_path + args.name
write_metadata(full_path, out_link_cnts)
write_links(full_path, links, args.chunk_size)
