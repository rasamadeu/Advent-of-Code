#!/bin/python3

from collections import defaultdict

hashmap = defaultdict(list)


def is_valid(sequence, length, hashmap):
    valid = True
    for i in range(length - 1):
        if sequence[i + 1] not in hashmap[sequence[i]]:
            valid = False
            break
    return valid


def reorder(sequence, length, hashmap):
    ordered_sequence = [0] * length
    for num in sequence:
        new_pos = -1
        for num_cmp in sequence:
            if num_cmp not in hashmap[num]:
                new_pos += 1
        ordered_sequence[new_pos] = num
    return ordered_sequence


def main():
    with open('../day_5.dat', 'r') as f:
        line = f.readline()
        while line != '\n':
            left, right = line[:-1].split('|')
            hashmap[int(left)].append(int(right))
            line = f.readline()

        middle_sum = 0
        line = f.readline()
        while line != '':
            sequence = list(map(lambda x: int(x), line[:-1].split(',')))
            length = len(sequence)
            if not is_valid(sequence, length, hashmap):
                sequence = reorder(sequence, length, hashmap)
                middle_sum += sequence[length // 2]
            line = f.readline()
        print(middle_sum)


if __name__ == "__main__":
    main()
