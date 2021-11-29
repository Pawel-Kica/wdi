import unittest
from solution import check


class TestCheck(unittest.TestCase):
    def test_first_element_one(self):
        numbers = [ 1 , 2,  3 , 4 ]
        lenOfNumbers = len(numbers)
        self.assertEqual(check(numbers ,lenOfNumbers), False, 'Should return False')

    def test_simple_valid_list(self):
        numbers = [ 2 , 1,  3 ]
        lenOfNumbers = len(numbers)
        result = True
        self.assertEqual(check(numbers ,lenOfNumbers), result, f'Should return {result}')

    def test_prime_first_list(self):
        prime = 13
        numbers = [ 1 for x in range(prime) ]
        numbers.insert(0,prime)
        lenOfNumbers = len(numbers)
        print(numbers,lenOfNumbers)
        result = True
        self.assertEqual(check(numbers ,lenOfNumbers), result, f'Should return {result}')

if __name__ == '__main__':
    unittest.main()
