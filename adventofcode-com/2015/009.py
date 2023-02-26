from itertools import permutations

file_name = "009.txt"

cities = set()
distances = {}

with open(file_name, "r") as file:
    for line in file.readlines():
        city0, _, city1, _, distance = line.split()
        distance = int(distance)
        cities.add(city0)
        cities.add(city1)
        distances[city0, city1] = distance
        distances[city1, city0] = distance

routes = list(permutations(cities))

route_distances = []
for route in routes:
    distance = 0
    for i in range(len(route) - 1):
        distance += distances[route[i], route[i+1]]
    route_distances.append(distance)

print(min(route_distances))
print(max(route_distances))