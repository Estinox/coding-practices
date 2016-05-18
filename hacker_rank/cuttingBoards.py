
__author__ = "Kevin Yuan"
__status__ = "Development"

DEBUG = True

def cost(m, n, x, y):
    if (m == n and m == 1):
        return 0;

    if DEBUG:
        print(m, n, x, y)

    max_y, max_x = 0, 0
    if (len(x) > 0):
        max_x = max(x)

    if (len(y) > 0):
        max_y = max(y)

    if (max_x > 0 \
            and (max_x > max_y \
            or (max_x == max_y and m >= n))):
        split = x.index(max_x)

        if DEBUG:
            print("x", split)

        return max_x \
                + cost(split + 1, n, x[:split], y) \
                + cost(m - split - 1, n, x[split+1:], y)
    else:
        split = y.index(max_y)

        if DEBUG:
            print("y", split)

        return max_y \
                + cost(m, split + 1, x, y[:split]) \
                + cost(m, n - split - 1, x, y[split+1:])

if __name__ == "__main__":
    T = int(input())

    for i in range(T):
        m, n = list(map(int, input().split()))
        x = list(map(int, input().split()))
        y = list(map(int, input().split()))
        print(cost(m, n, x, y))




