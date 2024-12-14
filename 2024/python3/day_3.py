#!/bin/python3

import re

with open('../day_3.dat', 'r') as f:
    input = f.read()

mul_args = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', input)

# First part
result = 0
for x, y in mul_args:
    result += int(x) * int(y)
print(result)

# Second part
instructions = {
    True: 'do()',
    False: "don't()"
}
split_text = input.split(instructions[False], 1)
do = True
result = 0
while len(split_text) == 2:
    if do:
        mul_args = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', split_text[0])
        for x, y in mul_args:
            result += int(x) * int(y)
    split_text = split_text[1].split(instructions[do], 1)
    do = not do
print(result)
