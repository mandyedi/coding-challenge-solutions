'''
Title: Rectangle Partition
Tags: easy, loops, arrays
'''
import sys
import math

w, h, count_x, count_y = [int(i) for i in input().split()]
mX = []
mY = []
for i in input().split():
    x = int(i)
    mX.append(x)
for i in input().split():
    y = int(i)
    mY.append(y)
mX = [0] + mX + [w]
mY = [0] + mY + [h]

axisX = dict()
axisY = dict()

def createAxis(list, axis):
    for i in range(len(list)-1, 0, -1):
        for j in range(i-1, -1, -1):
            diff = list[i] - list[j]
            axis[diff] = axis.get(diff, 0) + 1

createAxis(mX, axisX)
createAxis(mY, axisY)

c = 0
for i in axisX:
    c = c + axisX[i] * axisY.get(i, 0)

print(c)

'''
Horizontal: 2 3 5 5 8 10
            | | |/
Vertical:   2 3 5
'''

'''
0 a b c w
w-c w-b w-a
c-b c-a
b-a

0 2 5 10
5 8
3
'''
