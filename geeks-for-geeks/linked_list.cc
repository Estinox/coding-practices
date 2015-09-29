#include "linked_list.h"


template <class T>
void Stack<T>::push (T const& elem)
{
  // append copy of passed element
  elems.push_back(elem);
}

template <class T>
void Stack<T>::pop ()
{
  if (elems.empty())
  {
    throw out_of_range("Stack<>::pop(): empty stack");
  }
  // remove last element
  elems.pop_back();
}

template <class T>
T Stack<T>::top () const
{
  if (elems.empty())
  {
    throw out_of_range("Stack<>::top(): empty stack");
  }
  // return copy of last element
  return elems.back();
}

/*
template <typename T>
Node<T>::Node(T data)
//  : data(data)
//  , next(nullptr)
{}

template <typename T>
Node<T>* MakeLinkedList(int n)
{
  Node<int> *head = new Node<int>(n);

  for (int i = n - 1; i > 0; --i)
  {
    Node<int> *new_node = new Node<int>(i);
    new_node->next = head;
    head = new_node;
  }

  return head;
}

// Function to push a node
template <typename T>
void Push (Node<T> **head_ref, T new_data)
{
  // allocate node
  Node<T> *new_node = new Node<T>(new_data);

  // link the old list off the new node
  new_node->next = (*head_ref);

  // move the head to point to the new node
  (*head_ref) = new_node;
}

//Function to print linked list
template <typename T>
void Node<T>::PrintList()
{
  Node<T> *iter = this;

  do
  {
    printf("%d ", iter->data);
    iter = iter->next;
  }
  while (iter != nullptr);
  printf("\n");
}

template <typename T>
void PrintListRecursively(Node<T>* node)
{
  if (node == nullptr)
    return;

  printf("%d ", node->data);
  PrintListRecursively(node->next);
}

template <typename T>
Node<T>* Node<T>::RotateLinkedList(const int n)
{
  if (n == 0)
    return nullptr;

  Node<T> *cur = this;
  Node<T> *prev = nullptr;
  for (int i = 0; i < n && cur->next != nullptr; ++i)
  {
    prev = cur;
    cur = cur->next;
  }

  if (cur == nullptr)
    return nullptr;

  prev->next = nullptr;

  Node<T> *end = cur;
  while (end->next != nullptr)
    end = end->next;

  end->next = this;

  return cur;
}

// -------------------------------------------
// Reverse Nodes
// -------------------------------------------

template <typename T>
void ReverseLinkedListIterative(Node<T>** node)
{
  Node<T>* prev = nullptr;
  Node<T>* cur = *node;
  Node<T>* rest = cur->next;

  while(cur != nullptr)
  {
    rest = cur->next;
    cur->next = prev;
    prev = cur;
    cur = rest;
  }

  *node = prev;
}


template <typename T>
void ReverseLinkedListRecusively(Node<T>** node)
{
  Node<T>* first = *node;
  Node<T>* rest = first->next;

  if (rest == nullptr)
    return;

  ReverseLinkedListRecusively(&rest);

  first->next->next = first;
  first->next = nullptr;

  *node = rest;
}

template <typename T>
void ReverseLinkedList(Node<T>* node)
{
  Node<T>* prev = nullptr;
  Node<T>* cur = node;
  Node<T>* rest = node->next;

  while(cur != nullptr)
  {
    rest = cur->next;
    cur->next = prev;
    prev = cur;
    cur = rest;
  }

  node = prev;
}

template <typename T>
void ReverseLinkedListTailRecursion(Node<T>** node)
{
  if (node == nullptr || *node == nullptr)
    return;

  ReverseLinkedListTailRecursionUtility(*node, nullptr, node);
}

template <typename T>
void ReverseLinkedListTailRecursionUtility(Node<T>* cur, Node<T>* before, Node<T>** head)
{
}

// -------------------------------------------
// Delete Nodes
// -------------------------------------------

template <typename T>
void DeleteNodeIterative(Node<T>** node, int n)
{
  Node<T>* cur = *node;

  if (n == 0)
  {
    *node = cur->next;
    delete cur;
    return;
  }

  Node<T>* before = nullptr;

  for (int i = 0; i < n; ++i)
  {
    if (cur == nullptr)
      return;

    before = cur;
    cur = cur->next;
  }

  before->next = cur->next;
  delete cur;
}
*/


