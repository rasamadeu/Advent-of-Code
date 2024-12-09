#!/bin/python3


def is_safe(nums, tolerance=True):

    last_dif = nums[1] - nums[0]
    for i in range(0, len(nums) - 1):
        dif = nums[i + 1] - nums[i]
        if (
            dif * last_dif < 0
            or abs(dif) == 0
            or abs(dif) > 3
        ):
            if tolerance:
                usual_check = (is_safe(nums[:i] + nums[i+1:], False)
                               or is_safe(nums[:i+1] + nums[i+2:], False))
                '''
                There is a special edge case: when order changes in the first
                3 entries. In this case, we must check if the problem comes
                from position 0, 1 or 2.
                '''
                if i == 1:
                    return usual_check or is_safe(nums[1:], False)
                return usual_check
            else:
                return False
    return True


def main():
    safe = 0
    with open('../day_2.dat', 'r') as f:
        line = f.readline()
        while line != '':
            nums = list(map(lambda x: int(x), line.split()))
            if is_safe(nums, False):
                safe += 1
            line = f.readline()
    print(safe)


if __name__ == "__main__":
    main()
