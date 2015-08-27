#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
class Node
{
public:
  int data;
  class Node* next;

  explicit Node(int data);

  // Functions
  Node* RotateLinkedList(const int n);

  // Helpers
  void PrintList();
};

void Push (Node **head_ref, int new_data);
Node* MakeLinkedList(int n);

#endif
