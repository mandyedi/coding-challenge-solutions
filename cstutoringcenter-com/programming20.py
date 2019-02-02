f = open("programming20.txt", 'r')

s = ""
for line in f:
	s += str ( "{0:b}".format( int(line) ) )

k = 0
for i in s:
	if i == '1':
		k += 1

print k