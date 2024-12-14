#!/bin/python3

import unittest
from day_4 import solution


class Tests(unittest.TestCase):
    def test(self):
        case_1 = '''MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX'''
        self.assertEqual(18, solution(case_1.split('\n')))


if __name__ == "__main__":
    unittest.main()
