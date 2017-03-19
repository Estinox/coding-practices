def mod_fib_iter(x0, x1, n):
    curr = x1
    prev = x0
    new = 0
    for i in range(n-2):
        new = prev + curr**2
        prev = curr
        curr = new
    return new

args = list(map(int, str(input()).split(' ')))

print (mod_fib_iter(args[0], args[1], args[2]))
