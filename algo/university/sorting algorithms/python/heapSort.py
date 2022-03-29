from helpers.swap import swap
from helpers.printDecorator import beforeAfterComparison

def heapArr(arr, n, i):
    largest = i 
    l = 2 * i + 1     
    r = 2 * i + 2     

    if l < n and arr[largest] < arr[l]:
        largest = l
 
    if r < n and arr[largest] < arr[r]:
        largest = r
 
    if largest != i:
        swap(arr,i,largest)
 
        heapArr(arr, n, largest)


def heapSort(arr):
    length = len(arr)
 
    for i in range(length//2 - 1, -1, -1):
        heapArr(arr, length, i)

    for i in range(length-1, 0, -1):
        swap(arr,i,0)
        heapArr(arr, i, 0)
 
if __name__ == '__main__':

    # arraysToTest = [[1,3,1,2,7,9,1,6,1,0,4,2],[15,3,99,1,25,7,9,9,1,100,6,1,0,12,4,2,9,0,87,122,54],[0,12,4,2,9,0,87,122,54,1,2,11,55,99]]
    arraysToTest = [[3,4,8,9,7,10,9,15,20,13]]

    for arr in arraysToTest:
        beforeAfterComparison(heapSort,arr)

    print()

    # arr = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    # heapSort(arr)