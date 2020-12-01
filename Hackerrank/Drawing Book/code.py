#!/bin/python3

import os
import sys

def pageCount(n, p):
    a = (n // 2 - p // 2)
    b = p // 2
    if (a > b):
        return b
    else:
        return a
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = int(input())

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()
