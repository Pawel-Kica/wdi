import unittest
from solution import solution

class TestCheck(unittest.TestCase):
    def test_valid_list(self):
        number=[[2, 2, 8],
         [8, 8, 1],
         [4, 8, 4]
         ]
        n=3
        result = {2: 1, 16: 1, 8: 2, 64: 2, 32: 1, 4: 1}
        self.assertEqual(solution(number,n),
                         result, f'Should return {result}')
    def test_another_list(self):
        number=[[2, 2, 8],
         [3, 1, 1],
         [4, 10, 4]
         ]
        n=3
        result = {2: 1, 20: 1, 8: 2, 24: 1, 80: 1, 12: 1, 4: 1}
        self.assertEqual(solution(number,n),
                         result, f'Should return {result}')


if __name__ == '__main__':
    unittest.main()
