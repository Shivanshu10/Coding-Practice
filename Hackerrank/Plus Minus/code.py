#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    # transverse and check
    p = 0
    n = 0
    z = 0
    num = len(arr)
    for i in range(num):
        if (arr[i] > 0):
            p += 1
        elif (arr[i] == 0):
            z += 1
        elif (arr[i] < 0):
            n += 1
    print(round(p / num, 6))
    print(round(n / num, 6))
    print(round(z / num, 6))
if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
