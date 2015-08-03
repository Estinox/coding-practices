
T = int(input())

for i in range(T):
    N = int(input())
    prices = list(map(int, input().split()))

    cost = 0
    shares = 0
    profit = 0

    next_max = max(prices)

    for j in range(N):
        if prices[j] < next_max:
            cost += prices[j]
            shares += 1
        elif prices[j] == next_max:
            profit += shares * next_max - cost
            cost = 0
            shares = 0

            if j+1 < len(prices):
                next_max = max(prices[j+1:])

    print(profit)






