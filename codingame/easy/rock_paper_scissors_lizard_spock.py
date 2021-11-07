'''
Title: Rock Paper Scissors Lizard Spock
Tags: easy, conditions, arrays
'''

import sys
import math

n = int(input())
rounds = []
players = []
for i in range(n):
    numplayer, signplayer = input().split()
    players.append([numplayer, signplayer])
rounds.append(players)

def fight(a, b):
    if a[1] == b[1]:
        if int(a[0]) < int(b[0]):
            return a
        else:
            return b
    elif a[1] == 'C' and b[1] == 'P':
        return a
    elif a[1] == 'P' and b[1] == 'C':
        return b
    elif a[1] == 'P' and b[1] == 'R':
        return a
    elif a[1] == 'R' and b[1] == 'P':
        return b
    elif a[1] == 'R' and b[1] == 'L':
        return a
    elif a[1] == 'L' and b[1] == 'R':
        return b
    elif a[1] == 'L' and b[1] == 'S':
        return a
    elif a[1] == 'S' and b[1] == 'L':
        return b
    elif a[1] == 'S' and b[1] == 'C':
        return a
    elif a[1] == 'C' and b[1] == 'S':
        return b
    elif a[1] == 'C' and b[1] == 'L':
        return a
    elif a[1] == 'L' and b[1] == 'C':
        return b
    elif a[1] == 'L' and b[1] == 'P':
        return a
    elif a[1] == 'P' and b[1] == 'L':
        return b
    elif a[1] == 'P' and b[1] == 'S':
        return a
    elif a[1] == 'S' and b[1] == 'P':
        return b
    elif a[1] == 'S' and b[1] == 'R':
        return a
    elif a[1] == 'R' and b[1] == 'S':
        return b
    elif a[1] == 'R' and b[1] == 'C':
        return a
    elif a[1] == 'C' and b[1] == 'R':
        return b
    else:
        assert(False), "Missing case in fight"

k = len(rounds[0])
while k > 1:
    players = []
    # print(k)
    for i in range(0, len(rounds[-1]), 2):
        winner = fight(rounds[-1][i], rounds[-1][i+1])
        players.append(winner)
    rounds.append(players)
    k = len(rounds[-1])

winner = rounds[-1][0]
print(winner[0])

def getOpponentNumber(player, round):
    i = round.index(player)
    if i % 2 == 0:
        return round[i+1][0]
    else:
        return round[i-1][0]

opponents = []
for round in rounds:
    if len(round) > 1:
        opponents.append(getOpponentNumber(winner, round))

for i in range(len(opponents)):
    if i < len(opponents) - 1:
        print(opponents[i], end=" ")
    else:
        print(opponents[i], end="")
