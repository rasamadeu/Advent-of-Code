#!/bin/python3
import unittest
from day_6 import solution_1, solution_2


class Tests(unittest.TestCase):
    map = list(map(
               lambda x: list(x),
               [
                   '....#.....',
                   '.........#',
                   '..........',
                   '..#.......',
                   '.......#..',
                   '..........',
                   '.#..^.....',
                   '........#.',
                   '#.........',
                   '......#...',
               ]))

    def test_solution_1(self):
        self.assertEqual(41, len(solution_1(self.map)))

    def test_solution_2(self):
        visited_set_map = solution_1(self.map)
        self.assertEqual(6, solution_2(self.map, visited_set_map))


if __name__ == "__main__":
    unittest.main()
