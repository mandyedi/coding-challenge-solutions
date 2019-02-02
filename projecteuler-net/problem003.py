factors = []
n       = 600851475143
divisor = 2

while True:
	if n % divisor == 0:
		factors.append(divisor)
		n /= divisor
	else:
		divisor += 1
	if n == 1:
		break

print factors