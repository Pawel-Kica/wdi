def beforeAfterComparison(function,arr)->None:
    arrCopy = arr[:]

    print(f"\nRunning {function.__name__}")
    print('Before: ',arr)
    function(arr)
    print("After: ",arr)
    print(f"Result: sorted") if sorted(arrCopy) == arr else print("Result: unsorted")

    return arrCopy
        

