import random

def primeFactors(n:int)->set[int]:
    t = []
    k = 2
    while n != 1:
        while n % k == 0:
            n //= k
            t.append(k)
        k += 1
    return set(t)

def check(tab:list[int] ,length:int, n:int = 0)->bool:
    pf = primeFactors(tab[n])
    if pf == []:
        return False
    for x in pf:
        if x + n == length - 1:
            return True
        elif x + n < length - 1:
            result = check(tab, length, x + n )
        else:
            return False
    return result

if __name__ == "__main__":
    length = 10
    rangeOfNumbers = 10
    numbers = [random.randint(1,rangeOfNumbers) for x in range(0,length)]
    print(numbers)
    print(check(numbers,length))
