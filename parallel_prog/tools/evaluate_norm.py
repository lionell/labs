#!/usr/bin/env python3

import argparse
import math

parser = argparse.ArgumentParser()
parser.add_argument("file1", help="First file", type=str)
parser.add_argument("file2", help="Second file", type=str)
args = parser.parse_args()

def norm(a, b):
    res = 0
    for i in range(len(a)):
        res += abs(a[i] - b[i])
    return res

with open(args.file1, "r") as f:
    list1 = list(map(float, f.readline().split(" ")))

with open(args.file2, "r") as f:
    list2 = list(map(float, f.readline().split(" ")))

print(norm(list1, list2))
