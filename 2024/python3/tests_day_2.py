import unittest
from day_2 import is_safe


class Tests(unittest.TestCase):
    def test(self):
        case_1 = [7, 6, 4, 2, 1]
        case_2 = [1, 2, 7, 8, 9]
        case_3 = [9, 7, 6, 2, 1]
        case_4 = [1, 3, 2, 4, 5]
        case_5 = [8, 6, 4, 4, 1]
        case_6 = [1, 3, 6, 7, 9]
        case_7 = [59, 58, 55, 53, 52]
        case_8 = [17, 20, 19, 18, 16, 13, 10, 7]
        case_9 = [79, 82, 80, 78, 76]
        self.assertEqual(True, is_safe(case_1, False))
        self.assertEqual(False, is_safe(case_2, False))
        self.assertEqual(False, is_safe(case_3, False))
        self.assertEqual(False, is_safe(case_4, False))
        self.assertEqual(False, is_safe(case_5, False))
        self.assertEqual(True, is_safe(case_6, False))
        self.assertEqual(True, is_safe(case_7, False))

        # Second part
        self.assertEqual(True, is_safe(case_1))
        self.assertEqual(False, is_safe(case_2))
        self.assertEqual(False, is_safe(case_3))
        self.assertEqual(True, is_safe(case_4))
        self.assertEqual(True, is_safe(case_5))
        self.assertEqual(True, is_safe(case_6))
        self.assertEqual(True, is_safe(case_7))
        self.assertEqual(True, is_safe(case_8))
        self.assertEqual(True, is_safe(case_9))


if __name__ == "__main__":
    unittest.main()
