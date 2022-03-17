'''
 Napisz program, który pozwala na rekurencyjne obliczanie dowolnej potęgi (N) wprowadzonej przez użytkownika liczby (M). Wykorzystując funkcję ​time.sleep() zatrzymaj wykonywanie programu na 
 M sekund, jeśli liczba N jest liczbą pierwszą – sprawdź wykorzystują rekurencję.
'''
import time

def isPrime(number,divisor=2):
    if number <= 2:
        return number==2;
    if number % divisor == 0:
        return False
    if divisor * divisor > number:
        return True
    return isPrime(number, divisor + 1)

def recursivePower(number,power):
    if power==0:
        return 1
    if power==1:
        return number
        
    result=number
    result*=recursivePower(number,power-1)
    return result

a = int(input('number '))
b = int(input('power '))

if(isPrime(b)):
    print(f'waiting {a} seconds...')
    time.sleep(a)
    print('done')

print(f'{a}^{b} = {recursivePower(a,b)}')