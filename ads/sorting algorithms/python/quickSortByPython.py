def quickSortByPython(arr):
    if(len(arr) < 2):
        return arr
    piv,*rest = arr
    lower = [x for x in rest if x<= piv]
    higher = [x for x in rest if x > piv]
    
    return quickSortByPython(lower)+[piv]+quickSortByPython(higher)
    
