import unittest
from task5 import mFibo

class TestCheck(unittest.TestCase):
    def test_valid_number(self):
        number=15
        result = True
        self.assertEqual(mFibo(number),
                         result, f'Should return {result}')
        self.assertEqual(mFibo(16),
                         result, f'Should return {result}')
    def test_unvalid_number(self):
        number=3
        result = False
        self.assertEqual(mFibo(number),
                         result, f'Should return {result}')
    def test_negative_number(self):
        number=-2
        result = False
        self.assertEqual(mFibo(number),
                         result, f'Should return {result}')
    def test_float_number(self):
        # rounded to 15
        number=15.7
        result = True
        self.assertEqual(mFibo(number),
                         result, f'Should return {result}')


if __name__ == '__main__':
    unittest.main()
