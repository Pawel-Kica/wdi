from helpers.swap import swap

def bubbleSort(arr:list[float])->None:
    length = len(arr)
    for i in range(length - 1):
        isSorted = True
        for j in range(0, length - i - 1):
            if arr[j] > arr[j + 1]:
                swap(arr, j + 1 ,j)
                isSorted = False
        if isSorted:
            break