#! /usr/bin/env python

# # www.cstutoringcenter.com
  #
  # Problem 8 solution
  # Problem: What is the sum of the first 250 prime numbers?
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #
  
index = 1
i = 2
max = 250
sum = 0

while index <= max:
	prime = 1
	for j in range(2, i-1):
		if i % j == 0:
			prime = 0
		
	if prime:
		#print "%d. %d" % (index, i)
		sum = sum + i
		index = index + 1
	i = i + 1

print "Sum of the first %d numbers is: %d" % (max, sum)