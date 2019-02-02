go = 1
a, b = 0, 1
while go:
	if len( str( b ) ) == 15:
		print b
		go = 0
	else:
		a, b = b, a+b