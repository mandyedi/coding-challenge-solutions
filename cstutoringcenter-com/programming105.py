lojban = {
	'1': 'pa',
	'2': 're',
	'3': 'ci',
	'4': 'vo',
	'5': 'mu',
	'6': 'xa',
	'7': 'ze',
	'8': 'bi',
	'9': 'so',
	'0': 'no'
}

def numToLojban(x):
	string = str(x)
	s = ""
	for i in string:
		s += lojban[i]
	return s

def getSum(s):
	sum = 0
	for i in s:
		sum += ord(i) - 96
	return sum

products = 1
for i in range(1, 1000000):
	sum = getSum( numToLojban(i) )
	if i == sum:
		products *= i

print products