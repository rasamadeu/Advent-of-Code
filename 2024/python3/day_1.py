#!/bin/python3


def partition(arr, low, high):
    pivot = arr[high]
    left = low
    for i in range(low, high):
        if arr[i] < pivot:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1
    arr[high], arr[left] = arr[left], arr[high]
    return left


def quicksort(arr, low, high):
    if low < high:
        middle = partition(arr, low, high)
        quicksort(arr, low, middle - 1)
        quicksort(arr, middle + 1, high)


list_1, list_2 = [], []
length = 0
with open('../day_1.dat', 'r') as f:
    line = f.readline()
    while line != '':
        num_1, num_2 = line.split()
        list_1.append(int(num_1))
        list_2.append(int(num_2))
        line = f.readline()
        length += 1

quicksort(list_1, 0, length - 1)
quicksort(list_2, 0, length - 1)

# First problem
dist = 0
for i in range(len(list_1)):
    dist += abs(list_2[i] - list_1[i])
print(dist)

# Second problem
frequency = {}
similarity = 0
for num in list_1:
    if num not in frequency:
        count = 0
        for num_2 in list_2:
            if num_2 == num:
                count += 1
        frequency[num] = count
    similarity += num * frequency[num]
print(similarity)
