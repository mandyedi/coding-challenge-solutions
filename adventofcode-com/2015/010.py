input = "1113122113"

def look_and_say(s):
    next = ""
    i = 0
    while i < len(s):
        count = 1
        while i + 1 < len(s) and s[i] == s[i+1]:
            count += 1
            i += 1
        next += str(count) + s[i]
        i += 1
    return next

for i in range(40):
    input = look_and_say(input)

print(len(input))