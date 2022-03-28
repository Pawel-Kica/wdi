def beforeAfterComparison(function,arr,*args)->None:
    arrCopy = arr[:]

    print(f"\nSorting with {function.__name__}")
    print('Before:',arrCopy)

    function(arrCopy,*args)

    print("After :",arrCopy)
    print(f"Result: sorted") if sorted(arr) == arrCopy else print("Result: unsorted")

