
def fib(n):
    l = []

    if (n > 0):
        l = [0]

    if (n > 1):
        l = [0, 1]

    for i in range(2, n):
        l.append(l[i-1] + l[i-2])

    return l


print(list(map(lambda a : a**3, fib(int(input())))))
