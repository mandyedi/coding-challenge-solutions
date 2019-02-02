a, b = 0, 1
sum  = 0

for i in range(0, 75):
	sum += b
	a, b = b, a+b

print sum