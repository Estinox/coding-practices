import copy

l = [1,2,3,4];

s = [[],[l[0]]];

for i in l[1:]:
  s2 = copy.deepcopy(s);
  for j in s2:
    j += [i];

  s += s2;

print(s);

