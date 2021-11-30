import random
import time
from data import data
from timeDecorator import timeit

def sieve(n:int)->list[int]:
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

def primeFactors(n:int)->list[int]:
    t = []
    k = 2
    while n != 1:
        if n % k == 0:
            t.append(k)
        while n % k == 0:
            n //= k
        k += 1
    return t

# @timeit
def checkRec(tab:list[int] ,length:int, n:int = 0)->bool:
    if tab[n] + n > length:
        return False

    pf = primeFactors(tab[n])
    if pf == []:
        return False

    for x in pf:
        if x + n == length - 1:
            return True
        elif x + n < length - 1:
            result = checkRec(tab, length, x + n )
        else:
            return False
    return result

@timeit
def checkIte(tab:list[int], n:int)->bool:
    primes = sieve(n)
    return True

if __name__ == "__main__":

    length = 10
    rangeOfNumbers = 5

    numbers = [random.randint(1,rangeOfNumbers) for x in range(0,length)]

    # numbers = data
    # length = len(data)

    print(numbers)

    startTime:float = time.time()

    result:bool = checkRec(numbers,length)

    endTime:float = time.time()

    print (f'Function: checkRec with args: {numbers,length} took: {endTime-startTime} sec')

    result2 = checkIte(numbers,rangeOfNumbers)