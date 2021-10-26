# n = int(input())
# string1 = str(input())
# string2 = str(input())

n = 2

string1 = [x for x in 'rafal']

string2 = [x for x in 'nowak']

string1obj = {}
string2obj = {}

for x in string1:
    if x in string1obj:
        string1obj[x] += 1
    else:
        string1obj[x] = 1

for x in string2:
    if x in string2obj:
        string2obj[x] += 1
    else:
        string2obj[x] = 1


common = 0
commonArr = []
print(string1)
print(string2, "\n")
for x in string1:
    if x in string2:
        string2.remove(x)
        commonArr.append(x)
        print(string2, commonArr)
        common += 1
print(common)
print(commonArr)

print(string1obj)
print(string2obj)

# for x in string2obj:
#     if
