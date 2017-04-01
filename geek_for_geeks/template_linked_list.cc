#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
  T data;
  Node<T>* next;

  Node<T>(T d);
};

template <typename T>
Node<T>::Node(T d)
  : data(std::move(d))
  , next(nullptr)
{}

template <typename T>
void Print(Node<T>* n)
{
  Node<T>* cur = n;
  while (cur != nullptr)
  {
    printf("%d ", cur->data);
    cur = cur->next;
  }

  printf("\n");
}

template <typename T>
void PrintRecursively(Node<T>* n)
{
  if (n == nullptr)
  {
    printf("\n");
    return;
  }

  printf("%d ", n->data);
  PrintRecursively(n->next);
}

template <typename T>
void Push(Node<T>** n, T i)
{
  Node<T>* new_node = new Node<T>(i);
  new_node->next = *n;
  *n = new_node;
}

template <typename T>
void ReverseRecursively(Node<T>** n)
{
  if ((*n)->next == nullptr)
    return;

  Node<T>* first = *n;
  Node<T>* rest = first->next;

  ReverseRecursively(&rest);

  first->next->next = first;
  first->next = nullptr;

  *n = rest;
}

template <typename T>
void Delete(Node<T>** n, int i)
{
  Node<T>* cur = *n;
  if (i == 0)
  {
    *n = (*n)->next;
    delete cur;
    return;
  }

  Node<T>* prev = nullptr;
  for (int j = 0; j < i; ++j)
  {
    if (cur == nullptr)
      return;
    prev = cur;
    cur = cur->next;
  }

  prev->next = prev->next->next;
  delete cur;
}

int main ()
{
  Node<int>* node = new Node<int>(5);

  // Build list
  Push(&node, 4);
  Push(&node, 3);

  // Print original list
  Print(node);

  ReverseRecursively(&node);
  Delete(&node, 2);

  // Print final list
  PrintRecursively(node);
}
