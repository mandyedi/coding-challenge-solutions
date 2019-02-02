#! /usr/bin/env python

# # www.cstutoringcenter.com
  #
  # Programming 28 solution
  # Problem: What is the square root of the sum of the first 10^5 square roots?
  #          sqrt( sqrt(0) + sqrt(1) + sqrt(2) + ... + sqrt(99999) + sqrt(100000) )
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #
  
from math import sqrt
  
sum = 0
for i in range(0, 100001):
	sum = sum + sqrt(i)

print "Solution is: ", sqrt(sum)