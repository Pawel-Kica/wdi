def sum(arg1, arg2):
    try:
        arg1 = float(arg1)
        arg2 = float(arg2)
        return arg1 + arg2
    except ValueError:
        return 'ValueError'
    except TypeError:
        return 'TypeError'


if __name__ == '__main__':
    sum_result = sum("12aaasda", 37)
    print(f"suma = {sum_result}")
    print(f"__name__ = {__name__}")
