for a in range(1, 500):
	for b in range(1, 500):
		for c in range(1, 500):
			if ( pow(a, 2) + pow(b, 2) == pow(c, 2) ) and ( ( a + b + c ) == 1000 ):
				print a * b * c
	if a % 50 == 0:
		print "a reached", a