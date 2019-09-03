#!/usr/bin/env python3

import argparse
import re

def read_file(filename):
    with open(filename) as f:
        lines = f.readlines()
    text = ''.join(map(lambda l: re.sub('//.*', '', l), lines))
    return process(text)

def process(text):
    text = remove_whitespaces(text)
    text = re.sub('/\*.*\*/', '', text)
    text = rename_variables_php(text)
    return text

def remove_whitespaces(text):
    res = ''
    for i in range(1, len(text) - 1):
        if text[i].isspace():
            if not text[i - 1].isalnum() or not text[i + 1].isalnum():
                continue
        res += text[i]
    return res

def rename_variables_php(text):
    return re.sub('\$\w+', '$V', text)

def hash(text, b, mod):
    h = 0
    for c in text:
        h = (h + ord(c))*b % mod
    return h

def ngrams(text, n, b=224737, mod=104729):
    h = hash(text[:n], b, mod)
    hashes = [h]
    for i in range(1, len(text) - n + 1):
        h = (h - ord(text[i - 1]) * b**n + ord(text[i + n - 1])) * b % mod
        hashes.append(h)
    return hashes

def find_min(a):
    m = min(a)
    for j in range(len(a) - 1, -1, -1):
        if a[j] == m:
            return m, j

def winnowing(hashes, w):
    m, i = find_min(hashes[:w])
    fp = [m]
    idx = [i]
    for j in range(1, len(hashes) - w + 1):
        if i < j:
            m, i = find_min(hashes[j:(j + w)])
            i += j
            fp.append(m)
            idx.append(i)
        elif hashes[j + w - 1] <= m:
            m, i = hashes[j + w - 1], j + w - 1
            fp.append(m)
            idx.append(i)
    return fp, idx

def fingerprint(text, k, t):
    return winnowing(ngrams(text, k), t - k + 1)

def similarity(text1, text2, k, t):
    fp1, _ = fingerprint(text1, k, t)
    fp2, _ = fingerprint(text2, k, t)
    return score(fp1, fp2)

def score(X, Y):
    m = len(X)
    n = len(Y)
    L = [[None]*(n + 1) for i in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0 :
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i - 1][j], L[i][j - 1])
    return L[m][n]

# def score(fp1, fp2):
#     cnt = 0
#     for h in fp1:
#         cnt += fp2.count(h)
#     return cnt

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Compute a fingerprint of the file.')
    parser.add_argument('file', type=str, help='input file')
    parser.add_argument('--k', type=int, default=2, help='n-gram length (default: 2)')
    parser.add_argument('--t', type=int, default=5, help='min length of the guaranteed match (default: 5)')
    args = parser.parse_args()
    k, t = args.k, args.t
    text = read_file(args.file)
    print(text)
    # TODO(xlionell): Do some source code transformations
    # fp, _ = fingerprint(text, k, t)
    # print(fp)
    # print('Fingerprint: ', fp)
    # print('Indexes: ', idx)
