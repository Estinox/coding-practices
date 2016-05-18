
class Node:
  def __init__(self, val):
    self.left = None;
    self.right = None;
    self.val = val;

  def insert(self, node):
    if (self.val < node.val):
      if (self.right == None):
        self.right = node;
      else:
        self.right.insert(node);
    else:
      if (self.left == None):
        self.left = node;
      else:
        self.left.insert(node);

  def printTree(self):
    if (self.left is not None):
      self.left.printTree();

    print(self.val);

    if (self.right is not None):
      self.right.printTree();

  def swap(self, sd, d=0):
    if (d % sd == 0):
      temp = self.left;
      self.left = self.right;
      self.right = temp;

    if (self.left is not None):
      self.left.swap(sd, d+1);

    if (self.right is not None):
      self.right.swap(sd, d+1);

## Main ##
n = int(raw_input());

root = Node(1);
for i in range(n):
  l = map(int, raw_input().split(" "));
  for j in l:
    if (j != -1):
      root.insert(Node(j));

n = int(raw_input());
for i in range(n):
  k = int(raw_input());
  root.swap(k);


root.printTree();

