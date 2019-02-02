from time import time

t1       = time()
n        = 1
k        = 1
i        = 0
divisors1 = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
divisors2 = [10, 11, 12, 13, 14, 15, 16, 17]
divisors  = [2, 3, 4, 5, 6, 7, 8, 9, 10]
while True:
	
	if n % divisors[i] == 0:
		k = divisors[i]
		i += 1
			if  
			
	if n % 1000000 == 0:
		t2 = time()
		print "n reached", n, " elapsed time is", t2-t1
		
	if i == len(divisors) - 1:
		t2 = time()
		print n + k
		print "total time is", t2-t1
		break
	n += k