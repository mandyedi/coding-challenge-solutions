from functools import cache

circuit = {}

def solve_operator(operator, x, y):
    match operator:
        case "AND":
            return x & y
        case "OR":
            return x | y
        case "LSHIFT":
            return x << y
        case "RSHIFT":
            return x >> y

@cache
def solve(wire):
    global circuit

    if isinstance(wire, int):
        return int(wire)
    elif wire.isnumeric():
        return int(wire)

    value = circuit[wire]
    
    if value.isnumeric():
        return int(value)

    match circuit[wire].split():
        case [x]:
            return solve(x)
        case ["NOT", x]:
            z = ~solve(x)
            if z < 0:
                return 65536 + z
        case [x, operator, y]:
            return solve_operator(operator, solve(x), solve(y))

def main():
    file_name = "007.txt"

    with open(file_name, "r") as file:
        for line in file.readlines():
            instruction, wire = line.strip().split("->")
            # print(f"wire: {wire}, instruction: {instruction}")
            circuit[wire.strip()] = instruction.strip()

    # part 1
    print(solve("a"))


if __name__ == "__main__":
    main()
