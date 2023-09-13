#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

class Tree
{

public:
  Node *root;

  Tree(int data)
  {
    root = new Node();
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;
  }
  void add_node(int data)
  {
    Node *temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
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
  void remove_node(int data)
  {
    Node *prev = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {
      if (data < curr->data)
      {
        prev = curr;
        curr = curr->left;
      }
      else if (data > curr->data)
      {
        prev = curr;
        curr = curr->right;
      }
      else
      {
        if (curr->left == nullptr && curr->right == nullptr)
        {
          if (prev == nullptr)
          {
            root = nullptr;
          }
          else if (prev->left == curr)
          {
            prev->left = nullptr;
          }
          else
          {
            prev->right = nullptr;
          }
          delete curr;
        }
        else if (curr->left == nullptr)
        {
          if (prev == nullptr)
          {
            root = curr->right;
          }
          else if (prev->left == curr)
          {
            prev->left = curr->right;
          }
          else
          {
            prev->right = curr->right;
          }
          delete curr;
        }
        else if (curr->right == nullptr)
        {
          if (prev == nullptr)
          {
            root = curr->left;
          }
          else if (prev->left == curr)
          {
            prev->left = curr->left;
          }
          else
          {
            prev->right = curr->left;
          }
          delete curr;
        }
        else
        {
          Node *temp = curr->right;
          while (temp->left != nullptr)
          {
            temp = temp->left;
          }
          curr->data = temp->data;
          remove_node(temp->data);
        }
        return;
      }
    }
  }
  bool search(int data)
  {
    Node *curr = root;
    while (curr != nullptr)
    {
      if (data < curr->data)
      {
        curr = curr->left;
      }
      else if (data > curr->data)
      {
        curr = curr->right;
      }
      else
      {
        return true;
      }
    }
    return false;
  }

  void print_tree(Node *root, int indent = 0)
  {
    if (root == nullptr)
    {
      return;
    }

    for (int i = 0; i < indent; i++)
    {
      cout << " ";
    }
    cout << root->data << endl;

    print_tree(root->left, indent + 4);
    print_tree(root->right, indent + 4);
  }
};

int main()
{
  int data;
  cout << "Enter data for the first node: ";
  cin >> data;

  Tree *tree = new Tree(data);

  string menu = "1. Add node\n2. Remove node\n3. Search\n4. Print tree\n5. Exit\nEnter your choice: ";

  while (true)
  {
    int choice;
    cout << menu;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      cout << "Enter data: ";
      cin >> data;
      tree->add_node(data);
      break;
    }
    case 2:
    {
      cout << "Enter data: ";
      cin >> data;
      if (tree->search(data))
        tree->remove_node(data);
      else
        cout << "Not found" << endl;
      break;
    }
    case 3:
    {
      cout << "Enter data: ";
      cin >> data;
      if (tree->search(data))
        cout << "Found" << endl;
      else
        cout << "Not found" << endl;
      break;
    }
    case 4:
    {
      tree->print_tree(tree->root);
      break;
    }
    case 5:
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