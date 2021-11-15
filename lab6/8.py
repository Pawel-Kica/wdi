def podzbior(n, x):
    i = 1
    s = ""
    while x > 0:
        print('x', bin(x)[2:])
        if x & 1:
            s = n[-i] + s
        print('s', s)
        i += 1
        x >>= 1
    print('end')
    return int(s)


def z5(n):
    d = len(n)
    d = 2 ** d
    w = 0
    for i in range(1, d):
        if podzbior(n, i) % 7 == 0:
            w += 1
    print(w)


z5('2315')
