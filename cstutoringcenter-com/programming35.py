def factorial(n):
	if n <= 1:
		return 1
	else:
		return n * factorial(n-1)

s = str( factorial(100) )

sum = 0
for i in s:
	sum += factorial( int(i) )

print sum