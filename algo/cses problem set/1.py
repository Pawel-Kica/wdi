n = int(input())
answer = [n]
while n != 1:
    if n % 2 == 0:
        n /= 2
    else:
        n = n*3+1
    answer.append(int(n))

for x in answer:
    print(x, end=" ")
