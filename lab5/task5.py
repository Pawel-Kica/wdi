def mFibo(n: int) -> bool:
    try:
        n=int(n)
        f1 = f2 = 1
        
        if n == 0 or n == 1:
            return True
        for _ in range(n):
            tmp = f2
            f2 = f1+f2
            f1 = tmp
            result = f2*f1
            if result == n:
                return True
            elif result > n:
                return False
        return False
    except:
        return False


print('name',__name__)

if __name__ == "__main__":
    n: int = int(input())
    print(mFibo(n))
