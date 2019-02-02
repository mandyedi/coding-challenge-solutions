a, b = 0, 1

for i in range(0, 999):
	a, b = b, a+b

print b
k = 0
for i in str(b):
	if int(i) % 2 == 1:
		k += 1

print k