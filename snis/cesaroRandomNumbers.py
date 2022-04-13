from math import sqrt
from random import randint

def nwd(a:int,b:int)->bool:
    return b if a==0 else nwd(b%a,a)

if __name__ == '__main__':
    qnt = 100000
    ctn = 0

    for x in range(qnt):
        a = randint(2,100000)
        b = randint(2,100000)
        if nwd(a,b)==1:
            ctn+=1

    pi = sqrt(6/(ctn/qnt))

    print(pi)

