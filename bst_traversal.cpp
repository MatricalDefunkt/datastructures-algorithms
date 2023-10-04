#include <iostream>
#include <queue>

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
    this->left = nullptr;
    this->right = nullptr;
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
    Node *newNode = new Node(data);
    if (root == nullptr)
    {
      root = newNode;
      return;
    }
    Node *curr = root;
    while (true)
    {
      if (data < curr->data)
      {
        if (curr->left == nullptr)
        {
          curr->left = newNode;
          return;
        }
        curr = curr->left;
      }
      else
      {
        if (curr->right == nullptr)
        {
          curr->right = newNode;
          return;
        }
        curr = curr->right;
      }
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

  void breadth_first_traversal(Node *curr)
  {
    if (curr == nullptr)
    {
      return;
    }
    queue<Node *> q;
    q.push(curr);
    while (!q.empty())
    {
      Node *node = q.front();
      q.pop();
      cout << node->data << " ";
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
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

  cout << "Breadth first traversal: ";
  tree.breadth_first_traversal(tree.root);
  cout << endl;

  return 0;
}

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