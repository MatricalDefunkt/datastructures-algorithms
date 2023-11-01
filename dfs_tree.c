#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *create_node(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void dfs(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  printf("%d ", node->data);
  dfs(node->left);
  dfs(node->right);
}

int main()
{
  int root_data, left_data, right_data, left_left_data, left_right_data;
  printf("Enter root node data: ");
  scanf("%d", &root_data);
  printf("Enter left child data: ");
  scanf("%d", &left_data);
  printf("Enter right child data: ");
  scanf("%d", &right_data);
  printf("Enter left child of left child data: ");
  scanf("%d", &left_left_data);
  printf("Enter right child of left child data: ");
  scanf("%d", &left_right_data);

  Node *root = create_node(root_data);
  root->left = create_node(left_data);
  root->right = create_node(right_data);
  root->left->left = create_node(left_left_data);
  root->left->right = create_node(left_right_data);
  printf("DFS: ");
  dfs(root);
  return 0;
}