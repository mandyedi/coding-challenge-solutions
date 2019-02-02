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

s = ""
for i in range(1, 10001):
	string = str(i)
	for j in string:
		s += lojban[j]

k = 0
for i in s:
	if i == 'o':
		k += 1

string = str(k)
for i in string:
	print lojban[i],