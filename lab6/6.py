try:
    num = int(input())
    if num < 0:
        raise(ValueError)
except ValueError:
    print('value error')
    exit(0)
# num = 20
counter = 0

num_2 = 1
while num_2 <= num:
    num_3 = num_2
    while num_3 <= num:
        num_5 = num_3
        while num_5 <= num:
            print('num5 WWWW ', num_5)
            counter += 1
            num_5 *= 5
            print('num5 EEEE ', num_5)
        num_3 *= 3
        # print('num3', num_3)
    num_2 *= 2
    # print('num2', num_2)

print(counter)
