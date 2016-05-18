
class Node:
  def __init__(self):
    self.next = None;
    self.accepted = set();

  def add(self, val):
    if (len(val) == 0):
      return;

    if val[0] in self.accepted:
      if (self.next is None):
        self.next = Node();

      self.add(val[1:]);
    else:
      self.accepted.add(i);
      self.add(val[1:]);

  def exists(self, val):
    if 



