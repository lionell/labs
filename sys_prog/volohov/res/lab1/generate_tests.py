import random

OUTPUT_FILENAME = "/home/lionell/dev/labs/volohov/res/in.txt"

def gen(n=3):
    res = ""
    for i in range(n):
        res = res + ["a", "b", "c", "d", "e", "f", "j"][random.randint(0, 6)]
    return res

if __name__ == "__main__":
    with open(OUTPUT_FILENAME, "w") as out:
        for i in range(100):
            out.write(gen() + '\n')
