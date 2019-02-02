def f(x, y):
	return pow(x, y) + pow(y, x)

sum = 0
for i in range(1, 16):
	sum += f(i, i+1)

print sum
	