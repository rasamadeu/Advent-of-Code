#!/bin/python3


def concatenate(total, num, num_list):
    # We must concatenate two distinct numbers, meaning
    # total can't be equal to num
    if total == num:
        return 0
    # If we just str(total) and total is a float, it will
    # have .0 even if it's an int
    total_str = str(int(total))
    num_str = str(num)
    t, n = len(total_str), len(num_str)
    concat = (total_str[t - n:] == num_str)
    if concat:
        return int(total_str[:t - n])
    return 0


def possible_equation_1(total, num_list):

    if total - int(total) != 0:
        return False

    if len(num_list) == 1:
        return (total - num_list[0] == 0
                or total / num_list[0] == 1)

    return (possible_equation_1(total - num_list[-1], num_list[:-1])
            or possible_equation_1(total / num_list[-1], num_list[:-1]))


def possible_equation_2(total, num_list):

    # If the total number is rational, this means we performed
    # an invalid division
    if total - int(total) != 0:
        return False

    concat = concatenate(total, num_list[-1], num_list)
    if len(num_list) == 2:
        return (total - num_list[1] == num_list[0]
                or total / num_list[1] == num_list[0]
                or concat == num_list[0]
                )

    if not concat:
        return (possible_equation_2(total - num_list[-1], num_list[:-1])
                or possible_equation_2(total / num_list[-1], num_list[:-1]))

    return (possible_equation_2(total - num_list[-1], num_list[:-1])
            or possible_equation_2(total / num_list[-1], num_list[:-1])
            or possible_equation_2(concat, num_list[:-1]))


def solution(input, part_one=True):
    possible_equation = possible_equation_1
    if not part_one:
        possible_equation = possible_equation_2
    total = 0
    for row in input:
        if possible_equation(row[0], row[1]):
            total += row[0]
    return total


def main():

    with open('../day_7.dat', 'r') as f:
        input = []
        for line in f.readlines():
            line = line[:-1].split(': ')
            result = int(line[0])
            factors = list(map(lambda x: int(x), line[1].split(' ')))
            input.append([result, factors])

    print(solution(input))
    print(solution(input, False))


if __name__ == "__main__":
    main()
