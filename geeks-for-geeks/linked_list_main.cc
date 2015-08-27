#include "linked_list.h"


int main()
{
  Node *head = nullptr; 
  for (int i = 5; i >= 0; --i)
  {
    Push(&head, i);
  }

  head = head->RotateLinkedList(3);
  head->PrintList();

  return 0;
}
