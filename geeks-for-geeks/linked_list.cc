#include "linked_list.h"

Node::Node(int data)
  : data(data)
  , next(nullptr)
{}

Node* MakeLinkedList(int n)
{
  Node *head = new Node(n);

  for (int i = n - 1; i > 0; --i)
  {
    Node *new_node = new Node(i);
    new_node->next = head;
    head = new_node;
  }

  return head;
}

/* Function to push a node */
void Push (Node **head_ref, int new_data)
{
  /* allocate node */
  Node *new_node = new Node(new_data);

  /* link the old list off the new node */
  new_node->next = (*head_ref);

  /* move the head to point to the new node */
  (*head_ref) = new_node;
}

/* Function to print linked list */
void Node::PrintList()
{
  Node *iter = this;

  do
  {
    printf("%d ", iter->data);
    iter = iter->next;
  }
  while (iter->next != nullptr);
}

Node* Node::RotateLinkedList(const int n)
{
  if (n == 0)
    return nullptr;

  Node *cur = this;
  Node *prev = nullptr;
  for (int i = 0; i < n && cur->next != nullptr; ++i)
  {
    prev = cur;
    cur = cur->next;
  }

  if (cur == nullptr)
    return nullptr;

  prev->next = nullptr;

  Node *end = cur;
  while (end->next != nullptr)
    end = end->next;

  end->next = this;

  return cur;
}
