#! /usr/bin/env python

# # www.cstutoringcenter.com
  #
  # Problem 15 solution
  # Problem: Given an input file of 3000 random dice throws,
  # (here: programming15.txt) calculate how many doubles were rolled.
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #
  
f = open("programming15.txt", 'r')

n = 0
for line in f:
	dices = line.split()
	if dices[0] == dices[1]:
		n = n + 1
print "Number of doubles: %d" % n