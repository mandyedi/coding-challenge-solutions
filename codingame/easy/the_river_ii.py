'''
Title: The River II.
Tags: easy, arithmetic
'''

import sys
import math

def getSum(number):
    number_string = str(number)
    next = 0
    for s in number_string:
        next = next + int(s)
    return next

r_1 = int(input())

x = r_1
result = "NO"
while r_1 > 0:
    r_1 = r_1 - 1
    sum = getSum(r_1)
    if r_1 + sum == x:
        result = "YES"
        break

print(result)
