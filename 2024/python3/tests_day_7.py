#!/bin/python3

import unittest
from day_7 import possible_equation_1, possible_equation_2


class Tests(unittest.TestCase):
    def test_1(self):

        case_1 = [190, [10, 19]]
        case_2 = [3267, [81, 40, 27]]
        case_3 = [83, [17, 5]]
        case_4 = [156, [15, 6]]
        case_5 = [7290, [6, 8, 6, 15]]
        case_6 = [161011, [16, 10, 13]]
        case_7 = [192, [17, 8, 14]]
        case_8 = [21037, [9, 7, 18, 13]]
        case_9 = [292, [11, 6, 16, 20]]

        self.assertEqual(True, possible_equation_1(case_1[0], case_1[1]))
        self.assertEqual(True, possible_equation_1(case_2[0], case_2[1]))
        self.assertEqual(False, possible_equation_1(case_3[0], case_3[1]))
        self.assertEqual(False, possible_equation_1(case_4[0], case_4[1]))
        self.assertEqual(False, possible_equation_1(case_5[0], case_5[1]))
        self.assertEqual(False, possible_equation_1(case_6[0], case_6[1]))
        self.assertEqual(False, possible_equation_1(case_7[0], case_7[1]))
        self.assertEqual(False, possible_equation_1(case_8[0], case_8[1]))
        self.assertEqual(True, possible_equation_1(case_9[0], case_9[1]))

    def test_2(self):

        case_1 = [190, [10, 19]]
        case_2 = [3267, [81, 40, 27]]
        case_3 = [83, [17, 5]]
        case_4 = [156, [15, 6]]
        case_5 = [7290, [6, 8, 6, 15]]
        case_6 = [161011, [16, 10, 13]]
        case_7 = [192, [17, 8, 14]]
        case_8 = [21037, [9, 7, 18, 13]]
        case_9 = [292, [11, 6, 16, 20]]

        self.assertEqual(True, possible_equation_2(case_5[0], case_5[1]))
        self.assertEqual(True, possible_equation_2(case_1[0], case_1[1]))
        self.assertEqual(True, possible_equation_2(case_2[0], case_2[1]))
        self.assertEqual(True, possible_equation_2(case_9[0], case_9[1]))
        self.assertEqual(True, possible_equation_2(case_4[0], case_4[1]))
        self.assertEqual(True, possible_equation_2(case_7[0], case_7[1]))
        self.assertEqual(False, possible_equation_2(case_3[0], case_3[1]))
        self.assertEqual(False, possible_equation_2(case_6[0], case_6[1]))
        self.assertEqual(False, possible_equation_2(case_8[0], case_8[1]))


if __name__ == "__main__":
    unittest.main()
