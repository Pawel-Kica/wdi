from random import uniform
from bubbleSort import bubbleSort
from insertionSort import insertionSort
from selectionSort import selectionSort
from helpers.printDecorator import beforeAfterComparison

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

    arr = beforeAfterComparison(bubbleSort,arr)

    arr = beforeAfterComparison(insertionSort,arr)

    arr = beforeAfterComparison(selectionSort,arr)
    
    print()