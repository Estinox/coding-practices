
junk = input()

L = list(map(int, input().split()))
happy = {key : 1 for key in map(int, input().split())}
happiness = 0

for i in map(int, input().split()):
    happy[i] = -1

for l in L:
    happiness += happy[l]


print(happiness)
