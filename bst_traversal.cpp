#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class Tree
{
public:
  Node *root;

  Tree()
  {
    root = nullptr;
  }

  void insert(int data)
  {
    Node *temp = new Node(data);
    if (root == nullptr)
    {
      root = temp;
      return;
    }
    Node *prev = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {
      if (data < curr->data)
      {
        prev = curr;
        curr = curr->left;
      }
      else
      {
        prev = curr;
        curr = curr->right;
      }
    }
    if (data < prev->data)
    {
      prev->left = temp;
    }
    else
    {
      prev->right = temp;
    }
  }

  void inorder_traversal(Node *curr)
  {
    if (curr == nullptr)
    {
      return;
    }
    inorder_traversal(curr->left);
    cout << curr->data << " ";
    inorder_traversal(curr->right);
  }

  void preorder_traversal(Node *curr)
  {
    if (curr == nullptr)
    {
      return;
    }
    cout << curr->data << " ";
    preorder_traversal(curr->left);
    preorder_traversal(curr->right);
  }

  void postorder_traversal(Node *curr)
  {
    if (curr == nullptr)
    {
      return;
    }
    postorder_traversal(curr->left);
    postorder_traversal(curr->right);
    cout << curr->data << " ";
  }
};

int main()
{
  Tree tree;
  tree.insert(4);
  tree.insert(2);
  tree.insert(5);
  tree.insert(6);
  tree.insert(1);
  tree.insert(3);

  cout << "Inorder traversal: ";
  tree.inorder_traversal(tree.root);
  cout << endl;

  cout << "Preorder traversal: ";
  tree.preorder_traversal(tree.root);
  cout << endl;

  cout << "Postorder traversal: ";
  tree.postorder_traversal(tree.root);
  cout << endl;

  return 0;
}