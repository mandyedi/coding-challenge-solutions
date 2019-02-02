def factorial(n):
	if n <= 1:
		return 1
	else:
		return n * factorial(n-1)

def binomial(n, k):
	return factorial(n) / (factorial(k) * factorial(n - k))

print binomial(17, 10) - binomial(30, 12) + binomial(50, 3)