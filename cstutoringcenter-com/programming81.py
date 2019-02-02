def factorial(x):
	if x <= 1:
		return 1
	else:
		return x * factorial(x-1)

morse = {
	'0': '-----',
	'1': '.----',
	'2': '..---',
	'3': '...--',
	'4': '....-',
	'5': '.....',
	'6': '-....',
	'7': '--...',
	'8': '---..',
	'9': '----.'
}

s = str(factorial(100))
m = ""

for i in s:
	m += morse[i]
	
k = 0
for i in m:
	if i == '.':
		k += 1

print k