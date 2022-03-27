from helpers.swap import swap

def selectionSort(arr:list[float]):
    length = len(arr)

    for i in range(length-1):
        min_idx = i

        for j in range(i+1,length):
            if(arr[min_idx] > arr[j]):
                min_idx = j

        swap(arr,i,min_idx)

        
            


