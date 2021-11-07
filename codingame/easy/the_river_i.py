'''
Title: The River I.
Tags: easy, conditions
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
r_2 = int(input())

while True:
    if r_1 < r_2:
        r_1 = r_1 + getSum(r_1)
        if r_1 == r_2:
            print(r_1)
            break
    else:
        r_2 = r_2 + getSum(r_2)
        if r_1 == r_2:
            print(r_2)
            break
