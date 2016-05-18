def resetableCounter(max=None):
    j=0
    while max is None or j <= max:
        x = yield j #"x gets the sent arg j = j+1 if x is None else x
        x = resetableCounter(10)

x = resetableCounter(10)
print(x.send()
