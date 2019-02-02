# Project Euler Problem 89
# Nem jó, nem mindig vegzodik 1-re vagy 89-re

def squareSum(n):
	list = [int(x)*int(x) for x in str(n).zfill(len(str(n)))]
	return sum(list)

def createChain(x, list):
	if(x in list):
		return x
	else:
		list.append(x)
		return createChain(squareSum(x), list)
	
count = 0
for x in range(1, 10000000):
	if(x % 1000000 == 0):
		print x	
	list = []
	if(createChain(x, list) == 89):
		count = count + 1

print count
