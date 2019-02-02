def factorial(n):
	if n <= 1:
		return 1
	else:
		return n * factorial(n-1)

s = str( factorial(100) )

k = 0
for i in s:
	if i == '0':
		k += 1

print k