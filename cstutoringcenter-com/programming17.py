s = "342345820139586830203845861938475676"

sum = 0
for i in range(0, len(s), 2):
	sum += pow( int(s[i]), int(s[i+1]) )

print sum