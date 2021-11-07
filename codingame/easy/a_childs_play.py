'''
Title: A Child's Play
Tags: easy
'''

import sys
import math

w, h = [int(i) for i in input().split()]
n = int(input())

board = []
posX, posY = 0, 0
direction = [0, -1]

for i in range(h):
    line = input()
    board.append(line)
    for j in range(w):
        if line[j] == 'O':
            posX, posY = j, i

startX, startY = posX, posY

# print(w, h)
# print(n)
# print(board)
# print(posX, posY)

def turn(direction):
    if direction[0] == 0 and direction[1] == -1:
        direction[0] = 1
        direction[1] = 0
    elif direction[0] == 1 and direction[1] == 0:
        direction[0] = 0
        direction[1] = 1
    elif direction[0] == 0 and direction[1] == 1:
        direction[0] = -1
        direction[1] = 0
    elif direction[0] == -1 and direction[1] == 0:
        direction[0] = 0
        direction[1] = -1

i = 0
while i < n:
    if board[posY + direction[1]][posX + direction[0]] == '#':
        turn(direction)
    posX += direction[0]
    posY += direction[1]
    i += 1
    if posX == startX and posY == startY:
        rem = n - i
        rounds = math.floor(rem / i)
        i += rounds * i

print(posX, posY)
