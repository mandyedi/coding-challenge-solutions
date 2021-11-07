'''
Title: 1D Spreadsheet
Tags: easy, memoization, lazy evaluation, dependency graph
'''

import sys
import math

n = int(input())
cells = []
for i in range(n):
    operation, arg_1, arg_2 = input().split()
    cells.append([operation, arg_1, arg_2])

def getValue(item):
    if item[0] == '$':
        return evaluate(cells[int(item[1:])])
    else:
        return item

def evaluate(cell):
    if cell[0] == "VALUE":
        return getValue(cell[1])
    elif cell[0] == "ADD":
        a = getValue(cell[1])
        b = getValue(cell[2])
        result = int(a) + int(b)
        cell[0] = "VALUE"
        cell[1] = str(result)
        cell[2] = '_'
        return result
    elif cell[0] == "SUB":
        a = getValue(cell[1])
        b = getValue(cell[2])
        result = int(a) - int(b)
        cell[0] = "VALUE"
        cell[1] = str(result)
        cell[2] = '_'
        return result
    elif cell[0] == "MULT":
        a = getValue(cell[1])
        b = getValue(cell[2])
        result = int(a) * int(b)
        cell[0] = "VALUE"
        cell[1] = str(result)
        cell[2] = '_'
        return result

for i in range(n):
    print(evaluate(cells[i]))

''' Accounting is easy
[
['MULT', '$5', '$2'],
['ADD', '$5', '$0'],
['VALUE', '12', '_'],
['ADD', '$2', '$2'],
['MULT', '$3', '$2'],
['SUB', '$3', '$2']]
'''
