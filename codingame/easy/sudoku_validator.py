'''
Title: Sudoku Validator
Tags: easy, conditions, 2d arrays
'''

import sys
import math

board = []
for i in range(9):
    row = input()
    board.append(list(map(int, row.split())))

def checkRow(board):
    for row in board:
        if len(row) != len(set(row)):
            return False
    return True

def transpose(board):
    t = [[None]*9 for _ in range(9)]
    for i in range(9):
        for j in range(9):
            t[i][j] = board[j][i]
    return t

def getSubGrid(board, startX, startY):
    s = []
    for i in range(3):
        for j in range(3):
            s.append(board[i+startX][j+startY])
    return s

correct = checkRow(board)
board = transpose(board)
correct = correct and checkRow(board)

boardSubGrids = []
for i in range(0, 9, 3):
    for j in range(0, 9, 3):
        s = getSubGrid(board, i, j)
        boardSubGrids.append(s)

correct = correct and checkRow(boardSubGrids)

if correct == True:
    print("true")
else:
    print("false")
