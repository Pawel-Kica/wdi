x = int(input('Wprowadz pierwsza liczbe: '))
y = int(input("wprowadz druga liczbe: "))

if x < 0 and y < 0:
    print('koniec programu')
else:
    if x < 0 and y >= 0:
        x = -x
        print(x, y)
    elif x >= 0 and y < 0:
        y = -y
        print(x, y)


