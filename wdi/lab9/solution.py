import random


def solution(t, n):
    doc = {}
    cords = [[1, -2], [1, 2], [2, -1], [2, 1]]
    for row in range(n):
        for column in range(n):
            for cord in cords:
                if not (row + cord[0] < 0 or row + cord[0] > n-1 or column+cord[1] < 0 or column+cord[1] > n-1):
                    ilo = t[row][column] * t[row+cord[0]][column+cord[1]]
                    if ilo in doc:
                        doc[ilo] += 1
                    else:
                        doc[ilo] = 1
    return doc


if __name__ == '__main__':
    n = 3
    t = [[random.randint(1, 9) for x in range(n)] for x in range(n)]
    t = [[2, 2, 8],
         [8, 8, 1],
         [4, 8, 4]
         ]
    for x in t:
        print(x)
    print(solution(t, n))
