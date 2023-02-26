file_name = "008.txt"

# part 1
with open(file_name, "r") as file:
    sum = 0
    for line in file.readlines():
        num_characters = len(line.strip())
        num_memory = len(eval(line))
        sum += num_characters - num_memory
    print(sum)

# part 2
with open(file_name, "r") as file:
    sum = 0
    for line in file.readlines():
        num_slash = line.strip().count("\\")
        num_quote = line.strip().count('"')
        sum += num_slash + num_quote + 2
    print(sum)