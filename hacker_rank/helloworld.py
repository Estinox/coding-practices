#!/Library/Frameworks/Python.framework/Versions/3.4/bin/python3

print("hi world")

a = [0,1,2,3,4]

split = 0

for i in range(len(a)):
    print(i, a.index(i), a[:i], a[i:])
