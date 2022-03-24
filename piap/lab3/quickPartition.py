# import os

# def quickSort(arr):
#     equal = []
#     right = []
#     left = []
    
#     pivot = arr[0]
    
#     for x in arr:
#         if x < pivot:
#             left.append(x)
#         elif x > pivot:
#             right.append(x)
#         else:
#             equal.append(x)
            
#     return left + equal + right
        

# if __name__ == '__main__':
#     fptr = open(os.environ['OUTPUT_PATH'], 'w')

#     n = int(input().strip())

#     arr = list(map(int, input().rstrip().split()))

#     result = quickSort(arr)

#     fptr.write(' '.join(map(str, result)))
#     fptr.write('\n')

#     fptr.close()


tab = [[1],[1],[2],[2],[2],[2],[2],[3],[3],[3]]
alreadyUsed = []

for i in range(len(tab)):
    if tab[i][0] in alreadyUsed:
        tab[i][0]=tab[i-1][0]+1
        
    alreadyUsed.append(tab[i][0])

print(tab)