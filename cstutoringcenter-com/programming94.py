f = open("programming94.txt", 'r')

def revers(temp):
	s = ""
	for i in reversed(temp):
		s += i
	
	return int(s)

sum = 0
for line in f:
	numbers = line.split()
	x = str(numbers[0])
	y = str(numbers[1])
	x = revers(x)
	y = revers(y)
	sum += x + y

print sum

	
	
