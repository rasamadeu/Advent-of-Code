#!/bin/python3

UP = '^'
DOWN = 'v'
LEFT = '<'
RIGHT = '>'
VISITED = 'X'
OBSTACLE = '#'

DIRECTIONS = {
    UP: (-1, 0, RIGHT),
    RIGHT: (0, 1, DOWN),
    DOWN: (1, 0, LEFT),
    LEFT: (0, -1, UP),
}


def check_boundaries(i, j, width, height):
    return i < width and i >= 0 and j >= 0 and j < height


def set_next_direction(i, j, m, cur_direction, width, height):
    row_inc = DIRECTIONS[cur_direction][0]
    col_inc = DIRECTIONS[cur_direction][1]
    found_obstacle = False
    while (check_boundaries(i + row_inc, j + col_inc, width, height)
           and m[i + row_inc][j + col_inc] == OBSTACLE):
        cur_direction = DIRECTIONS[cur_direction][2]
        row_inc = DIRECTIONS[cur_direction][0]
        col_inc = DIRECTIONS[cur_direction][1]
        if not found_obstacle:
            found_obstacle = True
    return cur_direction, row_inc, col_inc, found_obstacle


def solution_1(m):

    i = 0
    while UP not in m[i]:
        i += 1

    j = m[i].index(UP)

    visited_set = set()
    height, width = len(m[0]), len(m)
    cur_direction = m[i][j]
    while check_boundaries(i, j, width, height):
        cur_direction, row_inc, col_inc, _ = set_next_direction(
            i, j, m, cur_direction, width, height)
        visited_set.add((i, j))
        i += row_inc
        j += col_inc
    return visited_set


def loop_exists(i, j, m, cur_direction, width, height):

    visited_set = set()
    height, width = len(m[0]), len(m)
    cur_direction = m[i][j]
    while check_boundaries(i, j, width, height):
        cur_direction, row_inc, col_inc, _ = set_next_direction(
            i, j, m, cur_direction, width, height)
        if (i, j, cur_direction) in visited_set:
            return True
        visited_set.add((i, j, cur_direction))
        i += row_inc
        j += col_inc
    return False


def solution_2(m, visited_set):

    i = 0
    while UP not in m[i]:
        i += 1
    j = m[i].index(UP)

    visited_set.remove((i, j))
    height, width = len(m[0]), len(m)
    cur_direction = m[i][j]
    count_loops = 0
    for x, y in visited_set:
        m[x][y] = OBSTACLE
        if loop_exists(i, j, m, cur_direction, width, height):
            count_loops += 1
        m[x][y] = '.'
    return count_loops


def main():
    with open('../day_6.dat', 'r') as f:
        m = list(map(lambda line: list(line[:-1]), f.readlines()))
    visited_set = solution_1(m)
    print(len(visited_set))
    print(solution_2(m, visited_set))


if __name__ == "__main__":
    main()
