from math import sqrt

# Sieve of Eratosthenes algorithm
#
# bug: if max < 16, 9 will be prime 
def prime(max):
	l = [1] * max
	for i in range( 2, int( sqrt(max) ) ):
		if l[i] == 1:
			k = 1
			for j in range(i*i, max, k*i):
				l[j]  = 0
				k    += 1
	return l	


l = prime(5000)

sum = 0
for i in range(2, len(l)):
	if l[i] == 1:
		sum += i

print sum