#include <stdio.h>

template <typename T>
class Node
{
public:
  T val;
  Node<T>* left;
  Node<T>* right;

  Node(T val);
};

template <typename T>
Node<T>::Node(T val)
  : val(val)
  , left(nullptr)
  , right(nullptr)
{}

template <typename T>
void PrintBfs(Node<T>* tree)
{
  if (tree == nullptr)
    return;

  if (tree->left != nullptr)
    PrintBfs(tree->left);

  printf("%d ", tree->val);

  if (tree->right != nullptr)
    PrintBfs(tree->right);
}

int main()
{
  Node<int> tree = Node<int>(1);

  Node<int> new_node = Node<int>(2);
  tree.left = &new_node;


  PrintBfs(&tree);
}
