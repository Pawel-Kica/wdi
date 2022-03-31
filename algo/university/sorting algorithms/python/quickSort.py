from helpers.swap import swap

def lomuto_partition(arr,start, end):
     
    pivot_value = arr[end]
    new_pivot = start - 1

    for j in range(start, end):
        if(arr[j] <= pivot_value):
            new_pivot += 1
            swap(arr, new_pivot, j)

    swap(arr, new_pivot + 1, end)
     
    return new_pivot + 1
     
def quickSort(arr,start, end):
     
    if (start < end):

        pivot = lomuto_partition(arr, start, end)

        quickSort(arr, start, pivot - 1)
        quickSort(arr, pivot + 1, end)