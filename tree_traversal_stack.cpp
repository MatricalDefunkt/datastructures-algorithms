#include <iostream>
#include <stack>

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
private:
  Node *root;

public:
  void pre_order()
  {
    stack<Node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
      Node *current = stack.top();
      stack.pop();
      cout << current->data << " ";
      if (current->right)
      {
        stack.push(current->right);
      }
      if (current->left)
      {
        stack.push(current->left);
      }
    }
  }

  void in_order()
  {
    stack<Node *> stack;
    Node *current = root;
    while (current != nullptr || !stack.empty())
    {
      while (current != nullptr)
      {
        stack.push(current);
        current = current->left;
      }
      current = stack.top();
      stack.pop();
      cout << current->data << " ";
      current = current->right;
    }
  }

  void post_order()
  {
    stack<Node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
      Node *current = stack.top();
      stack.pop();
      cout << current->data << " ";
      if (current->left)
      {
        stack.push(current->left);
      }
      if (current->right)
      {
        stack.push(current->right);
      }
    }
  }
  void add_node(int data)
  {
    Node *new_node = new Node(data);
    if (root == nullptr)
    {
      root = new_node;
      return;
    }
    Node *current = root;
    Node *prev = nullptr;
    while (current != nullptr)
    {
      prev = current;
      if (data < current->data)
      {
        current = current->left;
      }
      else if (data > current->data)
      {
        current = current->right;
      }
      else
      {
        delete new_node;
        return;
      }
    }
    if (data < prev->data)
    {
      prev->left = new_node;
    }
    else
    {
      prev->right = new_node;
    }
  }
  void delete_node(int data)
  {
    Node *current = root;
    Node *parent = nullptr;
    while (current != nullptr && current->data != data)
    {
      parent = current;
      if (data < current->data)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    if (current == nullptr)
    {
      // data not found in the tree
      return;
    }
    if (current->left == nullptr && current->right == nullptr)
    {
      // case 1: current has no children
      if (current == root)
      {
        root = nullptr;
      }
      else if (current == parent->left)
      {
        parent->left = nullptr;
      }
      else
      {
        parent->right = nullptr;
      }
      delete current;
    }
    else if (current->left == nullptr || current->right == nullptr)
    {
      // case 2: current has one child
      Node *child = current->left != nullptr ? current->left : current->right;
      if (current == root)
      {
        root = child;
      }
      else if (current == parent->left)
      {
        parent->left = child;
      }
      else
      {
        parent->right = child;
      }
      delete current;
    }
    else
    {
      // case 3: current has two children
      Node *successor = current->right;
      parent = current;
      while (successor->left != nullptr)
      {
        parent = successor;
        successor = successor->left;
      }
      current->data = successor->data;
      if (successor == parent->left)
      {
        parent->left = successor->right;
      }
      else
      {
        parent->right = successor->right;
      }
      delete successor;
    }
  }
};

int main()
{
  string menu = "1. Add a node\n2. Delete a node\n3. Pre-order traversal\n4. In-order traversal\n5. Post-order traversal\n6. Exit\n";

  Tree tree;

  while (true)
  {
    cout << menu;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "Enter value: ";
      int value;
      cin >> value;
      tree.add_node(value);
      break;
    }
    case 2:
    {
      cout << "Enter value: ";
      int value;
      cin >> value;
      tree.delete_node(value);
      break;
    }
    case 3:
    {
      tree.pre_order();
      cout << endl;
      break;
    }
    case 4:
    {
      tree.in_order();
      cout << endl;
      break;
    }
    case 5:
    {
      tree.post_order();
      cout << endl;
      break;
    }
    case 6:
    {
      return 0;
    }
    default:
    {
      cout << "Invalid choice" << endl;
      break;
    }
    }
  }
}