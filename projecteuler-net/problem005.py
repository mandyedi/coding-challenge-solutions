from time import time

t1       = time()
n        = 1
divisors = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
divisors2 = [10, 11, 12, 13, 14, 15, 16, 17]
while True:
	divisible = True
	for i in divisors:
		if n % i != 0:
			divisible = False
			break
	if n % 1000000 == 0:
		t2 = time()
		print "n reached", n, " elapsed time is", t2-t1
	if divisible:
		t2 = time()
		print n
		print "total time is", t2-t1
		break
	n += 1