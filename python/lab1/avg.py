import random
# 7

# a = int(input())
# b = int(input())
a = 1
b = 100

if b-a > 20:
    sum1 = 0
    for x in range(a, b+1):
        sum1 += x
    avg = sum1//(b-a)
    # print(avg)
    for x in range(avg-3, avg+3+1):
        if x != avg:
            print(x)

else:
    for x in range(a, b+1):
        print(x, end="")

# 8

# c=input()
c = 5
print(random.randint(0, c-1))
first = c*" "+"*"
for x in range(1, c+1,):
    print(first)
    first += "**"
    first = first[1:]
    # temp = list(first)
    # temp[random.randint(0, len(temp)-1)] = "o"
    # print(temp)

print(c*" "+"U")
