

n = input();
cav = [[0 for x in range(n)] for x in range(n)];

for i in range(n):
  row = str(input());
  j = 0;
  for depth in row:
    cav[i][j] = depth;
    j += 1;

result = cav;

for i in range(1,n-1):
  for j in range(1,n-1):
    if (cav[i-1][j] < cav[i][j]
        and cav[i+1][j] < cav[i][j]
        and cav[i][j-1] < cav[i][j]
        and cav[i][j+1] < cav[i][j]):
      result[i][j] = 'X';

print('\n'.join(map(str,result)).translate(None, "[',] "));
