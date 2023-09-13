#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL, *current_node = NULL;

    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        int data;
        printf("Enter the node's data: ");
        scanf("%d", &data);

        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->link = NULL;

        if (head == NULL)
        {
            head = new_node;
            current_node = new_node;
        }
        else
        {
            current_node->link = new_node;
            current_node = new_node;
        }
    }

    current_node = head;
    while (current_node != NULL)
    {
        printf("%d, ", current_node->data);
        current_node = current_node->link;
    }

    printf("\n");

    int data;
    printf("Enter the data for a new node: ");
    scanf("%d", &data);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    current_node = head;
    while (current_node->link != NULL)
    {
        current_node = current_node->link;
    }
    current_node->link = new_node;

    current_node = head;
    while (current_node != NULL)
    {
        printf("%d, ", current_node->data);
        current_node = current_node->link;
    }

    return 0;
}