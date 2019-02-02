from math import sqrt

n = 7
l = []
for i in range(0, n):
	for j in range(0, n):
			l.append([i, j])

l.remove([0, 0])

dir = []			
for i in l:
	d = sqrt( pow( i[0], 2 ) + pow( i[1], 2 ) )
	dir.append( [i[0]/d, i[1]/d] )

for i in dir:
	for j in range(0, len(dir)):
		if i == dir[j+1]:
			dir.remove(dir[j+1])


			