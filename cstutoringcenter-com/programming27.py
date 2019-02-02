from math import floor, sqrt

sum = 0
for i in range(2, 10001):
	if i != pow( floor( sqrt(i) ), 2 ):
		sum += sqrt(i)

print sum