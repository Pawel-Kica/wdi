def quickSort (A , p , r ):
    if p < r:
        q = partition (A , p , r )
        quickSort (A , p , q -1)
        quickSort (A , q +1 , r )

def partition (A , p ,r):
    