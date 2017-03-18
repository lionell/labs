import argparse

parser = argparse.ArgumentParser('Concatenate out files')
parser.add_argument('file', type=str)
parser.add_argument('k', type=int)
args = parser.parse_args()

files = []
for i in range(args.k):
    with open(args.file + '.' + str(i), 'r') as file:
        lines = file.readline().split()
        n = len(lines)
        files.append(lines)

with open(args.file, 'w') as file:
    for i in range(n):
        for j in range(args.k):
            file.write(files[j][i])
            file.write(' ')
