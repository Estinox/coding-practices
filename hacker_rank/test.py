
def test():
  for i in range(5):
    yield i;

for x in test():
  print(x);
  
