import operator

n = int(input())
fan = {}

for i in range(1,n+1):
    fan[i] = sum(map(int, input().split(" ")))

sorted_fan = sorted(fan.items(), key=operator.itemgetter(1))

for x,y in sorted_fan:
    print(x, end=' ')
