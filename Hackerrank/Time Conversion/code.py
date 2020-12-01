#!/bin/python3

import os
import sys

def timeConversion(s):
    # add and take mod to hour part and remove PM
    temp_str = ""
    if (s[8:] == "PM" and int(s[:2]) < 12):
        temp_str += str((int(s[0:2]) + int(12)) % int(24))
        temp_str += s[2:8]
        return temp_str
    elif (s[8:] == "AM" and int(s[:2]) == 12):
        temp_str += "00"
        temp_str += s[2:8]
        return temp_str
    else:
        return s[0:8]

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
