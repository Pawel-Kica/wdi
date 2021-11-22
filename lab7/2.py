try:
    n = 30
    # n = int(input('enter a natural number: '))
    if(n < 0):
        raise ValueError
except ValueError:
    print('invalid value')
    exit(0)
primes = []
if n > 1:
    t = [True] * (n + 1)
    i = 2
    while i * i <= n:
        if t[i]:
            j = i * i
            while j <= n:
                t[j] = False
                j += i
        i += 1
    for i in range(2, n+1):
        if t[i]:
            primes.append(i)
print(primes)
for x in range(len(primes)-1, 0, -1):
    print(primes[x], primes[x-1], 'mod: ', primes[x] % primes[x-1])
