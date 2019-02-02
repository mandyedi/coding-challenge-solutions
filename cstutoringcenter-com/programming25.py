a, b = 0, 1

for i in range(0, 1000):
	a, b = b, a+b

print len( str(b) )