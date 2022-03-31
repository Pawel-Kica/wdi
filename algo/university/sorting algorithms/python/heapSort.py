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
 
