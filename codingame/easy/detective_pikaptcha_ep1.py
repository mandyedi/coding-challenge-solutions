'''
Title: Detective Pikaptcha EP1
Tags: easy, maze
'''

import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

width, height = [int(i) for i in input().split()]
board = []
for i in range(height):
    line = input()
    board.append(line)

def bounds(pos):
    x, y = pos
    return 0 <= x < width and 0 <= y < height

def passable(pos):
    x, y = pos
    return board[y][x] != '#'

def getNeighbors(x, y):
    neighbors = [[x, y-1], [x+1, y], [x, y+1], [x-1, y]]
    neighbors = filter(bounds, neighbors)
    neighbors = filter(passable, neighbors)
    return neighbors

newBoard = []
for y in range(height):
    line = ""
    for x in range(width):
        if board[y][x] == '#':
           line += '#'
        else:
            c = 0
            for neighbor in getNeighbors(x, y):
                if neighbor != '#':
                    c += 1
            line += str(c)
    newBoard.append(line)

for row in newBoard:
    print(row)
print()
