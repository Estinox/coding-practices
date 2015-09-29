#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack
{
private:
  vector<T> elems;     // elements

public:
  void push(T const&);  // push element
  void pop();               // pop element
  T top() const;            // return top element
  bool empty() const        // return true if empty.
  {
    return elems.empty();
  }
};

/*
template <typename T>
class Node
{
public:
  T data;
  Node<T>* next;

  Node<T>(T data);

  // Functions
  //Node<T>* RotateLinkedList(const int n);

  // Helpers
  //void PrintList();
};

template <typename T>
void Push (Node<T> **head_ref, T new_data);

template <typename T>
Node<T>* MakeLinkedList(int n);

template <typename T>
void PrintListRecursively(Node<T>* node);

template <typename T>
void ReverseLinkedListIterative(Node<T>* node);

template <typename T>
void ReverseLinkedList(Node<T>** node);

template <typename T>
void ReverseLinkedListRecusively(Node<T>** node);

template <typename T>
void DeleteNodeIterative(Node<T>** node, int n);
*/


#endif




