#! /usr/bin/env python

# # www.cstutoringcenter.com
  #
  # Programming 50 solution
  # Problem:  what is the sum of the
  #            50th Fibonacci number
  #            50th prime number and the
  #            50th odd number?
  #
  # author:  mandyedi
  # contact: mandyedi@gmail.com
  #
  # Python version: 2.7.2
  # #
  
# # Returns with Fibonacci sequence
  # 
  # param N    is the limit of sequence
  # param a, b are the starting numbers
  # 
  # Note: standard Fibonacci sequence is starting with 1, 1, 2, 3, ...
  # #
def fib(n, a, b):
	l = [a]
	for i in range(0, n-1):
		l.append(b)
		a, b = b, a + b
	return l

# # Prime numbers
  # 
  # Returns a list of prime numbers beginning with 2
  # Max is the number of primes
  # #
def prime(max):
	index = 1
	i = 2
	l = []
	while index <= max:
		prime = 1
		for j in range(2, i-1):
			if i % j == 0:
				prime = 0
			
		if prime:
			#print "%d. %d" % (index, i)
			l.append(i)
			index = index + 1
		i = i + 1
	return l

# # Riturns a list of odd numbers
  # #

def odd(max):
	l     = []
	x     = 0
	index = 0
	while index <= max:
		if x % 2 == 1:
			l.append(x)
			index = index + 1
		x = x + 1
	return l

fibs   = fib(50, 1, 1)
primes = prime(50)
odds   = odd(50)

sum = fibs[49] + primes[49] + odds[49]

print "Solution is:", sum