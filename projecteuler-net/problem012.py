def triangle(n):
	if n <= 1:
		return 1
	else:
		return n + triangle(n-1)

i = 1
k = 0
while True:
	n = triangle(i)
	for j in range(1, n):
		if n % j == 0:
			k += 1
	if k > 100:
		print i
		break
	else:
		k  = 0
		i += 1