def merge(arr:list[float], arr1:list[float], arr2:list[float])->None:

    arr1_idx = arr2_idx = arr_idx = 0
    
    while arr1_idx < len(arr1) and arr2_idx < len(arr2):
        if arr1[arr1_idx] < arr2[arr2_idx]:
            arr[arr_idx] = arr1[arr1_idx]
            arr1_idx += 1
        else:
            arr[arr_idx] = arr2[arr2_idx]
            arr2_idx += 1

        arr_idx += 1

    while arr1_idx < len(arr1):
        arr[arr_idx] = arr1[arr1_idx]
        arr1_idx += 1
        arr_idx += 1
  
    while arr2_idx < len(arr2):
        arr[arr_idx] = arr2[arr2_idx]
        arr2_idx += 1
        arr_idx += 1
    


def mergeSort(arr:list[float])->None:

    length = len(arr)

    if length > 1:
        mid = length // 2
        arr1 = arr[:mid]
        arr2 = arr[mid:]

        mergeSort(arr1)
        mergeSort(arr2) 

        merge(arr, arr1, arr2)