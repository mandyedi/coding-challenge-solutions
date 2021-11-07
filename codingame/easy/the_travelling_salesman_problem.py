'''
Title: The Travelling Salesman Poblem
Tags: easy, graphs, greedy algorithms
'''

import sys
import math

def distance(p1, p2):
    d = math.sqrt((p1[0]-p2[0]) ** 2 + (p1[1]-p2[1])**2)
    return d

def findNearest(index, list, visited):
    minDistance = 1000000
    mindIndex = 0
    for i in range(n):
        if i != index and visited[i] == False:
            d = distance(list[index], list[i])
            if d < minDistance:
                minDistance = d
                minIndex = i
    return minIndex, minDistance

points = []

n = int(input())
for i in range(n):
    x, y = [int(j) for j in input().split()]
    points.append([x, y])


visited = [False] * n
index = 0
d = 0
firstPoint = points[0]
r = 0

for i in range(n - 1):
    minIndex, minDistance = findNearest(index, points, visited)

    d = d + minDistance

    visited[index] = True
    index = minIndex

    r = r + 1

d = d + distance(firstPoint, points[index])
print(round(d))

''' Tets case 01
0 i
1      0      0 m    0 i
2      1 m    1 i
3 m    2      2      1 m
4      3 i
'''
