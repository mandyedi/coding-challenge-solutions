import itertools

s        = ""
numbers = []
for i in itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8, 9]):
	for j in i:
		s += str(j)
	numbers.append(s)

#for i in numbers:
	#i[0:

s = "hello"

print s[0:2]