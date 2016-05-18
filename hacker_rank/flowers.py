
flowers, friends = list(map(int, input().split()))
costs = sorted(list(map(int, input().split())), reverse=True)
bought = {f : 0 for f in range(friends)}

total = 0
for i in range(flowers):
    total += costs[i]*(int(i / friends) + 1)

print(total)
