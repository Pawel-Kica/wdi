import unittest
from solution import checkRec


class TestCheck(unittest.TestCase):
    def test_first_element_one(self):
        numbers = [1, 2,  3, 4]
        lenOfNumbers = len(numbers)
        result = False
        self.assertEqual(checkRec(numbers, lenOfNumbers),
                         result, f'Should return {result}')

    def test_simple_valid_list(self):
        numbers = [2, 1,  3]
        lenOfNumbers = len(numbers)
        result = True
        self.assertEqual(checkRec(numbers, lenOfNumbers),
                         result, f'Should return {result}')

    def test_prime_first_list(self):
        prime = 503
        numbers = [1 for x in range(prime)]
        numbers.insert(0, prime)
        lenOfNumbers = len(numbers)
        result = True
        self.assertEqual(checkRec(numbers, lenOfNumbers),
                         result, f'Should return {result}')

    def test_not_that_simple_valid_list(self):
        numbers = [2, 1, 4, 1, 5, 3, 1, 1, 3, 5]
        lenOfNumbers = len(numbers)
        result = True
        self.assertEqual(checkRec(numbers, lenOfNumbers),
                         result, f'Should return {result}')

    def test_invalid_list(self):
        numbers = [3, 2, 1, 4, 1, 4, 3, 7, 1, 3, 5]
        lenOfNumbers = len(numbers)
        result = False
        self.assertEqual(checkRec(numbers, lenOfNumbers),
                         result, f'Should return {result}')

    def test_big_numbers_valid_list(self):
        numbers = [15, 1, 1, 5, 1, 25, 1, 1, 1]
        lenOfNumbers = len(numbers)
        result = True
        self.assertEqual(checkRec(numbers, lenOfNumbers),
                         result, f'Should return {result}')


if __name__ == '__main__':
    unittest.main()
