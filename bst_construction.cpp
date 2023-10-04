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

  int search(int data)
  {
    Node *curr = root;
    while (curr != nullptr)
    {
      if (data == curr->data)
      {
        return 1;
      }
      else if (data < curr->data)
      {
        curr = curr->left;w
      }
      else
      {
        curr = curr->right;
      }
    }
    return 0;
  }
};

int main()
{
  int arr[] = {4, 2, 5, 6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  Tree tree;
  for (int i = 0; i < n; i++)
  {
    tree.insert(arr[i]);
  }

  int choice;
  do
  {
    cout << "1. Insert a node" << endl;
    cout << "2. Print inorder traversal" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      int data;
      cout << "Enter data to insert: ";
      cin >> data;
      tree.insert(data);
      break;
    case 2:
      cout << "Inorder traversal: ";
      tree.inorder_traversal(tree.root);
      cout << endl;
      break;
    case 3:
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  } while (choice != 3);

  return 0;
}