def Collatz(start, length):
	if(start == 1):
		return length
	elif(start % 2 == 0):
		length = length + 1
		return Collatz(start/2, length)
	elif(start % 2 == 1):
		length = length + 1
		return Collatz(start*3 + 1, length)

max = 0
start = 0

for x in range(1, 1000000):
	if(x % 100000 == 0):
		print x
	length = Collatz(x, 1)
	if(max < length):
		max = length
		start = x

print start