
class Node:
  def __init__(self, val):
    self.val = val;
    self.left = None;
    self.right = None;

  def printTree(self):
    if (self.left is not None):
      self.left.printTree();

    print(self.val);

    if (self.right is not None):
      self.right.printTree();

  def maxValue(self, globalMax=0):
    left, right = None, None;

    print("O: %d" % globalMax);
    if (self.left is not None):
      left, globalMax = self.left.maxValue(globalMax);

    print("L: %d %d" % (self.val, globalMax));
    if (self.right is not None):
      right, globalMax = self.right.maxValue(globalMax);
    print("R: %d %d" % (self.val, globalMax));

    globalMax = max(max(left,0) + max(right,0) + self.val, left, right, globalMax);
    print("F: %d %d %d %d %d" % (self.val, max(left,0) + max(right,0) + self.val, max(left,0), max(0,right), globalMax));

    return max(left,right,0) + self.val, globalMax;


root = Node(-15);
root.left = Node(5);
root.right = Node(6);
root.left.left = Node(-8);
root.left.right = Node(1);
root.left.left.left = Node(2);
root.left.left.right = Node(6);
root.right.left = Node(3);
root.right.right = Node(9);
root.right.right.right = Node(0);
root.right.right.right.left = Node(4);
root.right.right.right.right = Node(-1);
root.right.right.right.right.left = Node(10);

root.printTree();

print(root.maxValue());
