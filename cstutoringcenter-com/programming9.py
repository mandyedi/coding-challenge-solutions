from time import time
from math import sqrt

def prime(max):
	k = 0
	for i in range(2, max):
		prime = 1
		for j in range(2, i-1):
			if i % j == 0:
				prime = 0
		if prime:
			k += 1
	return k

def prime2(max):
	k = 0
	primes = []
	for i in range(2, max):
		prime = 1
		for j in primes:
			if i % j == 0:
				prime = 0
		if prime:
			k += 1
			primes.append(i)
	return k

# Sieve of Eratosthenes algorithm
def prime3(max):
	l = [1] * max
	for i in range( 2, int( sqrt(max) ) ):
		if l[i] == 1:
			k = 1
			for j in range(i*i, max, k*i):
				l[j]  = 0
				k    += 1
	return l	

t1 = time()
#print prime2(100000)
l = prime3(10000000)

k = 0
for i in l:
	if i == 1:
		k += 1
print k - 2

t2 = time()
print "\n", t2 - t1