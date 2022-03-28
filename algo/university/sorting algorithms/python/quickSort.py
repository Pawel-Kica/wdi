from helpers.swap import swap

def lomuto_partition(arr,start, end):
     
    pivot_value = arr[end]
    new_divider_idx = start - 1

    for j in range(start, end):
        if(arr[j] <= pivot_value):
            new_divider_idx += 1
            swap(arr, new_divider_idx, j)

    swap(arr, new_divider_idx + 1, end)
     
    return new_divider_idx + 1
     
def quickSort(arr,start, end):
     
    if (start < end):

        pivot = lomuto_partition(arr, start, end)

        quickSort(arr, start, pivot - 1)
        quickSort(arr, pivot + 1, end)