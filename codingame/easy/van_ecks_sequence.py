'''
Title: Van Eck's Sequence
Tags: easy, memoization
'''

import sys
import math

a1 = int(input())
n = int(input())

i = 0
seen = dict()
last = dict()
while True:
    if i > n-1:
        break
    last = {a1: i}
    a1 = i - seen.get(a1, i)
    seen.update(last)
    i += 1

print(list(last.keys())[0])
