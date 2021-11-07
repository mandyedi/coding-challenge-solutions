'''
Title: Encryption/Decryption of Enigma Machine
Tags: easy, strings, encoding, cryptography, string manipulation
'''

import sys
import math

operation = input()
shift = int(input())
rotors = []
for i in range(3):
    rotor = [c for c in input()]
    rotors.append(rotor)
message = input()

def shiftRight(c, shift):
    d = ord(c)
    s = shift
    while s > 0:
        d += 1
        if d > 90:
            d = 65
        s -= 1
    return chr(d)

def shiftLeft(c, shift):
    d = ord(c)
    s = shift
    while s > 0:
        d -= 1
        if d < 65:
            d = 90
        s -= 1
    return chr(d)

if operation == "ENCODE":
    m = ""
    for i in range(0, len(message)):
        m += shiftRight(message[i], shift)
        shift += 1
    message = m

    for r in range(3):
        m = ""
        for i in range(0, len(message)):
            m += rotors[r][ord(message[i])-65]
        message = m

    print(message)
else:
    for r in range(2, -1, -1):
        m = ""
        for i in range(0, len(message)):
            m += chr(rotors[r].index(message[i]) + 65)
        message = m

    shift = shift + len(message) - 1

    m = ""
    for i in range(len(message)-1, -1, -1):
        m += shiftLeft(message[i], shift)
        shift -= 1
    message = m

    print(message[::-1])
