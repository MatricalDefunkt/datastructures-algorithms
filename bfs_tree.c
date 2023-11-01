#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct Queue
{
  Node *node;
  struct Queue *next;
} Queue;

Queue *create_queue(Node *node)
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->node = node;
  queue->next = NULL;
  return queue;
}

void enqueue(Queue **queue, Node *node)
{
  Queue *new_queue = create_queue(node);
  if (*queue == NULL)
  {
    *queue = new_queue;
    return;
  }
  Queue *temp = *queue;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new_queue;
}

Node *dequeue(Queue **queue)
{
  if (*queue == NULL)
  {
    return NULL;
  }
  Queue *temp = *queue;
  *queue = (*queue)->next;
  Node *node = temp->node;
  free(temp);
  return node;
}

Node *create_node(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void bfs(Node *root)
{
  Queue *queue = NULL;
  enqueue(&queue, root);
  while (queue != NULL)
  {
    Node *node = dequeue(&queue);
    printf("%d ", node->data);
    if (node->left != NULL)
    {
      enqueue(&queue, node->left);
    }
    if (node->right != NULL)
    {
      enqueue(&queue, node->right);
    }
  }
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
  bfs(root);
  return 0;
}