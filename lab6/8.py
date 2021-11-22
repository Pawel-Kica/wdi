def podzbior(n, x):
    i = 1
    s = ""
    while x > 0:
        if x & 1:
            s = n[-i] + s
        print(' s ', s, ' x ', bin(x)[2:])
        i += 1
        x >>= 1
    print('end')
    return int(s)


def z5(n):
    d = len(n)
    d = 2 ** d
    w = 0
    for i in range(1, d):
        a = podzbior(n, i)
        if a % 7 == 0:
            print(a)
            w += 1
    print('result', w)


z5('2315')
