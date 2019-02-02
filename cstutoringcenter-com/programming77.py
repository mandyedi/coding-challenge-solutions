#! /usr/bin/env python

# # www.cstutoringcenter.com
  #
  # Programming 77 solution
  # Problem: What number in the range 1 <= N <= 100,000 will produce
  #          the largest cycle length using the above algorithm?
  #			 
  #			 1. Print N;
  #			 2. If N = 1 Then EXIT;
  #			 3.      IF N is odd Then N = 3*N+1;
  #			 4.      Else N=N/2;
  #			 5. Goto step 1;
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #

from time import time

t1 = time()
 
def alg(n):
	l = [n]
	while n != 1:
		if n % 2 == 1:
			n = 3 * n + 1
			l.append(n)
		else:
			n = n/2
			l.append(n)
	return l
		
l = 0
for i in range(1, 100000):
	if l < len(alg(i)):
		l      = len(alg(i))
		x      = i
		length = l

t2 = time()

print "Solution is :", x
print "Length is   :", length
print "Elapsed time:", t2 - t1