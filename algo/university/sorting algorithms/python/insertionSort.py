def insertionSort(arr:list[float])->None:
    length = len(arr)

    for i in range(1, length):
        key = arr[i]
        j = i-1

        while j >= 0 and key < arr[j]:
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
            
