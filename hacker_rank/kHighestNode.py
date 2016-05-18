
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

  def kHighest(self, k, i=0):

    if (i < k and self.right is not None):
      i = self.right.kHighest(k, i);

    i = i + 1;
    if (i == k):
      print(self.val);

    if (self.left is not None):
      i = self.left.kHighest(k, i);

    return i;

## Main ##
l = [8,2,10,1,9,7,6,3,4]
root = Node(5);
for i in l:
  root.insert(Node(i));

for i in range(len(l)+1):
  root.kHighest(i+1);
