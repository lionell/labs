#!/usr/bin/env python3

import argparse
from fp import similarity, fingerprint, score, read_file

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Rank pairs of files by similarity.')
    parser.add_argument('files', nargs='+', type=str, help='files to rank')
    parser.add_argument('--k', type=int, default=2, help='n-gram length (default: 2)')
    parser.add_argument('--t', type=int, default=5, help='min length of the guaranteed match (default: 5)')
    args = parser.parse_args()
    k, t = args.k, args.t
    fps = dict()
    for filename in args.files:
        text = read_file(filename)
        fp, _ = fingerprint(text, k=k, t=t)
        fps[filename] = fp
    res = []
    for i in range(len(args.files)):
        for j in range(i + 1, len(args.files)):
            file1, file2 = args.files[i], args.files[j]
            res.append((score(fps[file1], fps[file2]), file1, file2))

    res = sorted(res, key=lambda t: t[0], reverse=True)
    for s, file1, file2 in res[:50]:
        print(s, '\t', file1, '\t', file2)
