i = 1
def gen(d):
    global i
    if d == 1:
        i += 1
        print("1000 0")
        return i - 1
    l = gen(d - 1)
    r = gen(d - 1)
    print("1000 2 {} {}".format(l, r))
    i += 1
    return i - 1

n = 10
k = (2**n) - 1
print(k)
print(k)
gen(n)
