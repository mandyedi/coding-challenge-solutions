f = open("problem11.txt", 'r')
m = []

for line in f:
	m.append( line.split() )

f.close()

n = 0
# rows
for i in range(0, 20):
	for j in range(0, 17):
		product = int(m[i][j]) * int(m[i][j+1]) * int(m[i][j+2]) * int(m[i][j+3])
		if product > n:
			n = product
# columns
for i in range(0, 17):
	for j in range(0, 20):
		product = int(m[i][j]) * int(m[i+1][j]) * int(m[i+2][j]) * int(m[i+3][j])
		if product > n:
			n = product
# diagonally \
for i in range(0, 17):
	for j in range(0, 17):
		product = int(m[i][j]) * int(m[i+1][j+1]) * int(m[i+2][j+2]) * int(m[i+3][j+3])
		if product > n:
			n = product
# diagonally /
for i in range(0, 17):
	for j in range(0, 17):
		product = int(m[i][j+3]) * int(m[i+1][j+2]) * int(m[i+2][j+1]) * int(m[i+3][j])
		if product > n:
			n = product
			
print n