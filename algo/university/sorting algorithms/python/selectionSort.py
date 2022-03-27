from helpers.swap import swap

def selectionSort(arr:list[float]):
    length = len(arr)

    for i in range(length-1):
        smallest = i

        for j in range(i+1,length):
            if(arr[smallest] > arr[j]):
                smallest = j

        swap(arr,i,smallest)

        
            


