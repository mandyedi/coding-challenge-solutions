'''
Title: Credit Card Verifier (Luhn's Algorithm)
Tags: easy, check-digit
'''

import sys
import math

n = int(input())
cards = []
for i in range(n):
    cards.append( list( map(int, input().replace(' ', '')) ) )

for card in cards:
    sum1 = 0
    for i in range(len(card)-2, -1, -2):
        x = card[i] * 2
        if x > 9:
            x -= 9
        sum1 += x
    sum2 = 0
    for i in range(len(card)-1, -1, -2):
        sum2 += card[i]
    if (sum1+sum2) % 10 == 0:
        print("YES")
    else:
        print("NO")
