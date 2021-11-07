'''
Title: Lumen
Tags: easy, loops, 2d array
'''

import sys
import math

n = int(input())
l = int(input())
board = []
for i in range(n):
    line = input().split()
    board.append(line)

def dist(p1, p2):
    return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]))

lights = []
for i in range(n):
    for j in range(n):
        if board[i][j] == 'C':
            lights.append([i, j])

for light in lights:
    for i in range(n):
        for j in range(n):
            d = dist([i, j], light)
            d = l - d
            if d < 0:
                d = 0
            if isinstance(board[i][j], int) == True:
                d = max(board[i][j], d)
            board[i][j] = d

c = 0
for row in board:
    c += row.count(0)
    c += row.count('X')

print(c)
