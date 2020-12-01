#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    arr.sort()
    mi = 0
    ma = 0
    n = len(arr)
    for i in range(4):
        mi += arr[i]
        ma += arr[n-i-1]
    print(str(mi) + " " + str(ma))
if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
