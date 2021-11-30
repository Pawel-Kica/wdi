import time

def timeit(f):

    def timed(*args, **kw):

        startTime:float = time.time()

        result = f(*args, **kw)

        endTime:float = time.time()

        print (f'Function: {f.__name__} with args: {args} took: {endTime-startTime} sec')
        
        return result
        
    return timed
