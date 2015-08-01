
l = [1,2,3,4];

def swap(l, i, j):
  temp = l[i];
  l[i] = l[j];
  l[j] = temp;

def permute(l, i=0):
  if (len(l) == i):
    print(l);
  for x in range(len(l[i:])):
    swap(l, i, x);
    permute(l, i+1);
    swap(l, i, x);

permute(l);
