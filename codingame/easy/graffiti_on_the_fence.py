'''
Title: Grffiti on the Fence
Tags: easy, intervals
'''

import sys
import math

l = int(input())
n = int(input())
painted = []
for i in range(n):
    st, ed = [int(j) for j in input().split()]
    painted.append([st, ed])

painted.sort()

paintedMerged = []

# merge overlaps v2
i = 0
while i < len(painted) - 1:
    j = i + 1
    b = 0
    current = painted[i]
    new = current.copy()
    # print(current)
    while j < len(painted):
        nextt = painted[j]
        # print(" {}".format(nextt))
        if nextt[0] <= new[1] and nextt[1] < new[1]:
            j += 1
        elif nextt[0] <= new[1]:
            new[1] = nextt[1]
            j += 1
        else:
            break
    paintedMerged.append(new)
    if j > 0:
        i = j
    else:
        i += 1

# check last and merge if needed
if painted[-1][0] > paintedMerged[-1][1]:
    paintedMerged.append(painted[-1])

# print(paintedMerged)

unpainted = []

# first
if paintedMerged[0][0] > 0:
    unpainted.append([0, paintedMerged[0][0]])

# between
if len(paintedMerged) >= 2:
    for i in range(0, len(paintedMerged)-1):
        a = paintedMerged[i][1]
        b = paintedMerged[i+1][0]
        if a < b:
            unpainted.append([a, b])

# last
m = 0
maxSection = []
for section in paintedMerged:
    if section[1] > m:
        m = section[1]
        maxSection = section
if maxSection[1] < l:
    unpainted.append([maxSection[1], l])

if len(unpainted) == 0:
    print("All painted")
else:
    for u in unpainted:
        print("{} {}".format(u[0], u[1]))
