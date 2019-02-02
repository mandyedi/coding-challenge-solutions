n = 0
for i in reversed( range(100, 1000) ):
	for j in reversed ( range(100, 1000) ):
		s = str( i*j )
		if s == s[::-1] and int( s ) > n:
			n = int( s )
			break

print n
