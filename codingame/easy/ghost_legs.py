'''
Title: Ghost Legs
Tags: easy, conditions, loops, ascii art
'''

import sys
import math

board = []
w, h = [int(i) for i in input().split()]
for i in range(h):
    line = input()
    board.append(line)

RIGHT = 0
LEFT = 1
NEUTRAL = 2
realX = 0
x = 0
y = 0
results = []

def checkConnection(x, y):
    if x > 0 and board[y][x-1] == '-':
        return LEFT
    elif x + 1 < w and board[y][x+1] == '-':
        return RIGHT
    else:
        return NEUTRAL

while realX < w:
    result = [board[0][realX]]
    x = realX
    y = 0
    while y < h:
        direction = checkConnection(x, y)
        if direction == RIGHT:
            x = x + 3
        elif direction == LEFT:
            x = x - 3
        y = y + 1
    result.append(board[h-1][x])
    results.append(result)
    realX = realX + 3

for result in results:
    print("{}{}".format(result[0], result[1]))

'''
w, h
current col
current row
direction (right, left, neutral)
1.  check neighbours
2.  if connect move right/left
3.    update current col
4.    set next direction
5.  if last row
6.    save result
7.    if last col
8.      end
9.    else
10.     move up, move right
11. else
12.   move down
'''
