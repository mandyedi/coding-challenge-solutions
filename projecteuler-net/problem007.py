def prime(max):
    k = 0
    primes = []
    for i in range(2, max):
        prime = 1
        for j in primes:
            if i % j == 0:
                prime = 0
        if prime:
            k += 1
            primes.append(i)
    return primes
	
print len(prime(50000))

#i = 1
#while True:
#	if len(prime(i)) == 10001:
#		print prime[len(prime)-1]
#		break
