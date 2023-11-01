
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

// Function to create a new node with the given data
node *create_node(int data)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a new node with the given data into the binary search tree
node *insert_node(node *root, int data)
{
  if (root == NULL)
  {
    return create_node(data);
  }
  if (data < root->data)
  {
    root->left = insert_node(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Function to delete a node with the given data from the binary search tree
node *delete_node(node *root, int data)
{
  if (root == NULL)
  {
    return root;
  }
  if (data < root->data)
  {
    root->left = delete_node(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = delete_node(root->right, data);
  }
  else
  {
    if (root->left == NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }
    node *temp = root->right;
    while (temp->left != NULL)
    {
      temp = temp->left;
    }
    root->data = temp->data;
    root->right = delete_node(root->right, temp->data);
  }
  return root;
}

// Function to print the binary search tree in order
void print_tree(node *root)
{
  if (root != NULL)
  {
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
  }
}

// Function to search for a node with the given data in the binary search tree
node *search_tree(node *root, int data)
{
  if (root == NULL || root->data == data)
  {
    return root;
  }
  if (data < root->data)
  {
    return search_tree(root->left, data);
  }
  return search_tree(root->right, data);
}

// Example usage of the binary search tree functions
int main()
{
  char menu[] = "1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\n";
  int choice, data, first_data;

  printf("Enter the first data: ");
  scanf("%d", &first_data);
  node *root = create_node(first_data);

  while (1)
  {
    printf("%s", menu);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      root = insert_node(root, data);
      break;
    case 2:
      printf("Enter the data to delete: ");
      scanf("%d", &data);
      root = delete_node(root, data);
      break;
    case 3:
      printf("Enter the data to search: ");
      scanf("%d", &data);
      if (search_tree(root, data) != NULL)
      {
        printf("Found\n");
      }
      else
      {
        printf("Not found\n");
      }
      break;
    case 4:
      print_tree(root);
      printf("\n");
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}
