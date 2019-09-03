#!/usr/bin/env python3

import argparse
from fp import similarity, read_file

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Compare two files using fingerprints.')
    parser.add_argument('file1', type=str, help='first input file')
    parser.add_argument('file2', type=str, help='second input file')
    parser.add_argument('--k', type=int, default=2, help='n-gram length (default: 2)')
    parser.add_argument('--t', type=int, default=5, help='min length of the guaranteed match (default: 5)')
    args = parser.parse_args()
    k, t = args.k, args.t
    text1 = read_file(args.file1)
    text2 = read_file(args.file2)
    score = similarity(text1, text2, k=k, t=t)
    print('Similarity score:', score)
