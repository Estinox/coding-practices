#include <stdio.h>
#include <queue>

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
void PrintDfs(Node<T>* tree)
{
  if (tree == nullptr)
    return;

  if (tree->left != nullptr)
    PrintDfs(tree->left);

  printf("%d ", tree->val);

  if (tree->right != nullptr)
    PrintDfs(tree->right);
}

template <typename T>
void PrintBfs(Node<T>* tree)
{
  using namespace std;

  queue<Node<T>*> children;
  children.push(tree);

  while (!children.empty())
  {
    Node<T>* cur = children.front();
    children.pop();

    if (cur == nullptr)
      continue;

    printf("%d ", cur->val);
    children.push(cur->left);
    children.push(cur->right);

    delete cur;
  }
}

template <typename T>
int LowestCommonAncestor(Node<int>* root, const T& n1, const T& n2)
{
  if (root == nullptr)
    return -1;

  if (root->val > n1 && root->val > n2)
    return LowestCommonAncestor(root->left, n1, n2);
  else if (root->val < n1 && root->val < n2)
    return LowestCommonAncestor(root->right, n1, n2);
  else
    return root->val;
}

int main()
{
  Node<int>* root = new Node<int>(20);
  root->left               = new Node<int>(8);
  root->right              = new Node<int>(22);
  root->left->left         = new Node<int>(4);
  root->left->right        = new Node<int>(12);
  root->left->right->left  = new Node<int>(10);
  root->left->right->right = new Node<int>(14);

  printf("%d", LowestCommonAncestor(root, 10, 14));
}
