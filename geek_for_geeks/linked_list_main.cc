#include "linked_list.h"


int main()
{
  Stack<int> intStack;  // stack of ints
  Stack<string> stringStack;    // stack of strings

  // manipulate int stack
  intStack.push(7);
  cout << intStack.top() << endl;

  // manipulate string stack
  stringStack.push("hello");
  cout << stringStack.top() << std::endl;
  stringStack.pop();
  stringStack.pop();

  /*
  Node<int> *tmp = new Node<int>(5);

  //Node<int> *head = nullptr;
  //Node<int> temp = Node(10);

  //Push(&head, 0);

  for (int i = 5; i >= 0; --i)
  {
    Push(&head, i);
  }
  head->PrintList();
  */

  //DeleteNodeIterative(&head, 0);

  //head->PrintList();

  return 0;
}

