#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node
{
public:
  T data;
  Node<T> *left;
  Node<T> *right;

  Node(T data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class Board
{
public:
  int n;
  vector<int> queens;

  Board(int n)
  {
    this->n = n;
  }

  bool is_valid()
  {
    for (int i = 0; i < queens.size(); i++)
    {
      for (int j = i + 1; j < queens.size(); j++)
      {
        if (queens[i] == queens[j] || abs(i - j) == abs(queens[i] - queens[j]))
        {
          return false;
        }
      }
    }
    return true;
  }

  void print()
  {
    for (int i = 0; i < queens.size(); i++)
    {
      for (int j = 0; j < queens.size(); j++)
      {
        if (queens[i] == j)
        {
          cout << "Q ";
        }
        else
        {
          cout << ". ";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
};

class Tree
{
public:
  Node<Board *> *root;

  Tree(int n)
  {
    root = new Node<Board *>(new Board(n));
    generate_children(root);
  }

  void generate_children(Node<Board *> *node)
  {
    Board *board = node->data;
    if (board->queens.size() == board->n)
    {
      return;
    }
    for (int i = 0; i < board->n; i++)
    {
      Board *child_board = new Board(board->n);
      child_board->queens = board->queens;
      child_board->queens.push_back(i);
      Node<Board *> *child_node = new Node<Board *>(child_board);
      node->left = child_node;
      if (child_board->is_valid())
      {
        generate_children(child_node);
      }
      else
      {
        delete child_node;
      }
    }
  }

  void print_tree(Node<Board *> *curr)
  {
    if (curr == nullptr)
    {
      return;
    }
    curr->data->print();
    print_tree(curr->left);
    print_tree(curr->right);
  }

  void print_tree()
  {
    print_tree(root);
  }
};

int main()
{
  Tree tree(8);
  tree.print_tree();
  return 0;
}