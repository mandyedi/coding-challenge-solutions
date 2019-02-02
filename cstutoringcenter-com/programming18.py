from math import sqrt

# Sieve of Eratosthenes algorithm
def prime(max):
	l = [1] * max
	for i in range( 2, int( sqrt(max) ) ):
		if l[i] == 1:
			k = 1
			for j in range(i*i, max, k*i):
				l[j]  = 0
				k    += 1
	return l

list = prime(1000000)

primes = []
k      = 0
for i in range(2, 1000000):
	if list[i] == 1:
		sum = 0
		for j in str(i):
			sum += int(j)
		if sum == 14:
			k += 1
		sum = 0

print k