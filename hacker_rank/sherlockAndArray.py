def sherlockAndArray(l):
  if (len(l) > 2):
    leftSum = l[0];
    center = l[1];
    rightSum = sum(l[j] for j in range(2,len(l)));

#   print(l);

    for i in range(1, len(l)-1):

#     print("%d) " % (i-1), " leftSum: %d, center %d, rightSum %d" % (leftSum, center, rightSum));

      if (leftSum == rightSum):
        print("YES");
        return;

      leftSum += center;
      center = l[i+1];
      rightSum -= center;

    print("NO");
  elif (len(l) == 1):
    print("YES");
  else:
    print("NO");


n = int(raw_input());

for i in range(n):
  t = raw_input();
  l = map(int, raw_input().split(" "));
  print(l);
  sherlockAndArray(l);
