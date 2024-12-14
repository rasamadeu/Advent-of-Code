#!/bin/python3
import unittest
from day_5 import reorder
from collections import defaultdict


class Tests(unittest.TestCase):
    def test(self):
        order = [
            [47, 53],
            [97, 13],
            [97, 61],
            [97, 47],
            [75, 29],
            [61, 13],
            [75, 53],
            [29, 13],
            [97, 29],
            [53, 29],
            [61, 53],
            [97, 53],
            [61, 29],
            [47, 13],
            [75, 47],
            [97, 75],
            [47, 61],
            [75, 61],
            [47, 29],
            [75, 13],
            [53, 13]
        ]
        hashmap = defaultdict(list)
        for left, right in order:
            hashmap[int(left)].append(int(right))
        case_1 = [75, 97, 47, 61, 53]
        case_2 = [61, 13, 29]
        case_3 = [97, 13, 75, 29, 47]
        # Second part
        self.assertEqual([97, 75, 47, 61, 53], reorder(
            case_1, len(case_1), hashmap))
        self.assertEqual([61, 29, 13], reorder(case_2, len(case_2), hashmap))
        self.assertEqual([97, 75, 47, 29, 13], reorder(
            case_3, len(case_3), hashmap))


if __name__ == "__main__":
    unittest.main()
