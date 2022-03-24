def mergeSort(arr):
    if len(arr) < 2: 
        return
  
    mid = len(arr)//2
  
    tab1 = arr[:mid]
  
    tab2 = arr[mid:]
  
    mergeSort(tab1)
  
    mergeSort(tab2)
  
    indexArr1 = indexArr2 = mainArrIndex = 0
  
    while indexArr1 < len(tab1) and indexArr2 < len(tab2):
        if tab1[indexArr1] < tab2[indexArr2]:
            arr[mainArrIndex] = tab1[indexArr1]
            indexArr1 += 1
        else:
            arr[mainArrIndex] = tab2[indexArr2]
            indexArr2 += 1
        mainArrIndex += 1
  
    while indexArr1 < len(tab1):
        arr[mainArrIndex] = tab1[indexArr1]
        indexArr1 += 1
        mainArrIndex += 1
  
    while indexArr2 < len(tab2):
        arr[mainArrIndex] = tab2[indexArr2]
        indexArr2 += 1
        mainArrIndex += 1

arr = [3,6,1,7,3,4,21,8,2,1,4]

print(arr)

mergeSort(arr)

print(arr)