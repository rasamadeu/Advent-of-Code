#!/bin/python3

XMAS = 'XMAS'
LIMIT_INDEX = 3


def check_word(m, i, j, row, column):
    for n in range(1, 4):
        if XMAS[n] != m[row(i, n)][column(j, n)]:
            return 0
    return 1


def xmas(m, i, j, height, width):
    down, up, right, left = False, False, False, False
    if i + LIMIT_INDEX < height:
        down = True
    if i - LIMIT_INDEX >= 0:
        up = True
    if j + LIMIT_INDEX < width:
        right = True
    if j - LIMIT_INDEX >= 0:
        left = True

    def add(x, y):
        return x + y

    def diff(x, y):
        return x - y

    def id(x, y):
        return x
    n = 0
    if up:
        n += check_word(m, i, j, diff, id)
        if left:
            n += check_word(m, i, j, diff, diff)
        if right:
            n += check_word(m, i, j, diff, add)

    if down:
        n += check_word(m, i, j, add, id)
        if left:
            n += check_word(m, i, j, add, diff)
        if right:
            n += check_word(m, i, j, add, add)

    if left:
        n += check_word(m, i, j, id, diff)
    if right:
        n += check_word(m, i, j, id, add)

    return n


def x_mas(m, i, j):
    diag_1 = m[i-1][j-1] + m[i][j] + m[i+1][j+1]
    diag_2 = m[i-1][j+1] + m[i][j] + m[i+1][j-1]
    matches = {'MAS', 'SAM'}
    if diag_1 in matches and diag_2 in matches:
        return 1
    return 0


def solution(m, part_two=False):
    height = len(m)
    width = len(m[0])
    n_xmas = 0
    if not part_two:
        for i in range(height):
            for j in range(width):
                if m[i][j] == 'X' and not part_two:
                    n_xmas += xmas(m, i, j, height, width)
    else:
        for i in range(1, height - 1):
            for j in range(1, width - 1):
                if m[i][j] == 'A':
                    n_xmas += x_mas(m, i, j)
    return n_xmas


def main():
    with open('../day_4.dat', 'r') as f:
        m = list(f)
    print(solution(m))
    print(solution(m, part_two=True))


if __name__ == "__main__":
    main()
