import random
import time
from data import data
from timeDecorator import timeit


def sieve(n: int) -> list[int]:
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
    return primes


def primeFactors(n: int) -> list[int]:
    t = []
    k = 2
    while n != 1:
        if n % k == 0:
            t.append(k)
        while n % k == 0:
            n //= k
        k += 1
    return t


def checkRec(tab: list[int], length: int, n: int = 0):

    global result

    # print(tab[n], n, result)

    if not result:
        pf = primeFactors(tab[n])
        for x in pf:
            if x + n == length - 1:
                # print('prime factor', x, 'index', n,
                #   'max index', length - 1, 'TRUEEEEEEEEE')
                result = True
                break
            elif x + n < length - 1:
                # print('prime factor', x, 'index', n,
                #   'max index', length - 1, 'AGAAAIN')
                checkRec(tab, length, x + n)
            else:
                break


@timeit
def checkIte(tab: list[int], n: int) -> bool:
    pf = primeFactors(0)
    # for x in pf:
    #     flag: bool = True

# print('always')


if __name__ == "__main__":

    length = 30
    rangeOfNumbers = 30

    # length = 503
    # rangeOfNumbers = 100

    numbers = [random.randint(1, rangeOfNumbers) for x in range(0, length)]

    numbers = [15, 1, 1, 390, 1, 25, 1, 1, 1]

    # numbers = [1, 2,  3, 4]

    # numbers = [2, 1,  3]

    prime = 503
    numbers = [1 for x in range(prime)]
    numbers.insert(0, prime)

    # numbers = [2, 1, 4, 1, 5, 3, 1, 1, 3, 5]

    numbers = [3, 2, 1, 4, 1, 4, 3, 7, 1, 3, 5]

    length = len(numbers)

    # numbers.insert(0, 503)
    # length += 1

    # numbers = data
    # length = len(data)

    result = False

    startTime: float = time.time()

    checkRec(numbers, length)

    endTime: float = time.time()

    print(
        f'Function: checkRec with args: {numbers,length} took: {endTime-startTime} sec')
    print(f'Result: {result}')

    # result2 = checkIte(numbers, rangeOfNumbers)


# 15 = 5 * 3
# 28 = 2 * 2 * 7

# numbers = [ 15, 1, 1, 5, 1, 25, 1, 1, 1 ]
