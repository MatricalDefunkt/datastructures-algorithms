#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct LinkedList
{
  struct Node *head;
  struct Node *current_node;
};

void init_linked_list(struct LinkedList *list, int data)
{
  list->head = malloc(sizeof(struct Node));
  list->head->data = data;
  list->head->next = NULL;
  list->current_node = list->head;
}

void insert_front(struct LinkedList *list, int data)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = list->head;
  list->head = temp;
}

void insert_end(struct LinkedList *list, int data)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  list->current_node->next = temp;
  list->current_node = temp;
}

void insert_at(struct LinkedList *list, int data, int position)
{
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  struct Node *prev = NULL;
  struct Node *curr = list->head;
  int i = 0;
  while (curr != NULL)
  {
    if (i == position)
    {
      prev->next = temp;
      temp->next = curr;
      return;
    }
    prev = curr;
    curr = curr->next;
    i++;
  }
}

int shift(struct LinkedList *list)
{
  struct Node *temp = list->head;
  list->head = list->head->next;
  int data = temp->data;
  free(temp);
  return data;
}

int pop(struct LinkedList *list)
{
  struct Node *temp = list->head;
  struct Node *prev = NULL;
  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  int data = temp->data;
  free(temp);
  return data;
}

int remove_node(struct LinkedList *list, int position)
{
  struct Node *temp = list->head;
  struct Node *prev = NULL;
  int i = 0;
  while (temp != NULL)
  {
    if (i == position)
    {
      prev->next = temp->next;
      int data = temp->data;
      free(temp);
      return data;
    }
    prev = temp;
    temp = temp->next;
    i++;
  }
}

void display(struct LinkedList *list)
{
  struct Node *temp = list->head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  int first_data;
  printf("Enter data for the first node: ");
  scanf("%d", &first_data);
  struct LinkedList linked_list;
  init_linked_list(&linked_list, first_data);

  char *menu = "1. Insert at front\n2. Insert at end\n3. Insert at position\n4. Shift\n5. Pop\n6. Remove\n7. Display\n8. Exit\n";

  while (1)
  {
    int choice;
    printf("%s", menu);
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
      int data;
      printf("Enter data for the node: ");
      scanf("%d", &data);
      insert_front(&linked_list, data);
      break;
    }
    case 2:
    {
      int data;
      printf("Enter data for the node: ");
      scanf("%d", &data);
      insert_end(&linked_list, data);
      break;
    }
    case 3:
    {
      int data;
      int position;
      printf("Enter data for the node: ");
      scanf("%d", &data);
      printf("Enter position for the node: ");
      scanf("%d", &position);
      insert_at(&linked_list, data, position);
      break;
    }
    case 4:
    {
      int data = shift(&linked_list);
      printf("Data shifted: %d\n", data);
      break;
    }
    case 5:
    {
      int data = pop(&linked_list);
      printf("Data popped: %d\n", data);
      break;
    }
    case 6:
    {
      int position;
      printf("Enter position for the node: ");
      scanf("%d", &position);
      int data = remove_node(&linked_list, position);
      printf("Data removed: %d\n", data);
      break;
    }
    case 7:
    {
      display(&linked_list);
      break;
    }
    case 8:
    {
      return 0;
    }
    default:
    {
      printf("Invalid choice\n");
      break;
    }
    }
  }
}