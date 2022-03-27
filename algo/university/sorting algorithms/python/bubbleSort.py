from random import uniform

def bubbleSort(arr:list[float], length:int)->None:
    for i in range(length-1):
        isSorted = True
        for j in range(0,length-i-1):
            if arr[j] > arr[j+1]:
                 arr[j], arr[j + 1] = arr[j + 1], arr[j]
                 isSorted = False
        if isSorted:
            break

if __name__=='__main__':

    # config
    arr:list[float] = []
    lowerRange:float = -10
    upperRange:float = 10
    size:int = 10

    # size = int(input('Length: ').strip())
    # lowerRange = float(input('Lower range: ').strip())
    # upperRange = float(input('Upper range: ').strip())
    # arr = list(map(float, input('Elements (float): ').rstrip().split()))


    arr = [round(uniform(lowerRange,upperRange),1) for _ in range(size)]

    print("Before: ",arr)
    bubbleSort(arr,size)
    print("After: ",arr)