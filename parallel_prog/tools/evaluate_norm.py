#!/usr/bin/env python3

import argparse

parser = argparse.ArgumentParser()
parser.add_argument("file1", help="First file", type=str)
parser.add_argument("file2", help="Second file", type=str)
args = parser.parse_args()

with open(args.file1, "r") as f:
    list1 = map(float, f.readlines())
