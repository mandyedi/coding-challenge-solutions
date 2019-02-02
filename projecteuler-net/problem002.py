a, b = 0, 1
sum = 0
while True:
	if b % 2 == 0:
		sum += b
	a, b = b, a+b
	if b >= 4000000:
		break

print sum