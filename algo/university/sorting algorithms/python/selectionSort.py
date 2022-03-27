from helpers.swap import swap

def selectionSort(arr:list[float]):
    length = len(arr)

    for i in range(length-1):
        idx_of_min = i

        for j in range(i+1,length):
            if(arr[idx_of_min] > arr[j]):
                idx_of_min = j

        swap(arr,i,idx_of_min)

        
            


