#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    Node *head;
    Node *tail;

    void add_node(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;

        tail->next = temp;
        tail = tail->next;
    }
    void remove_node(int data)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                    delete temp;
                    return;
                }
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void insert_node(int data, int position)
    {
        Node *temp = head;
        Node *prev = NULL;
        int i = 0;
        while (temp != NULL)
        {
            if (i == position)
            {
                Node *new_node = new Node();
                new_node->data = data;
                new_node->next = temp;
                if (prev == NULL)
                {
                    head = new_node;
                    return;
                }
                prev->next = new_node;
                return;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
    }
};

int main()
{
    LinkedList *linked_list = new LinkedList();
    int size = 0;
    int data;

    linked_list->head = new Node();
    linked_list->head->data = 0;
    linked_list->head->next = NULL;
    linked_list->tail = linked_list->head;

    string menu = "1. Add node\n2. Remove node\n3. Print linked list\n4. Insert node\n5. Exit\nEnter your choice: ";

    while (true)
    {
        int choice;
        cout << menu;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the data for node: " << size + 1 << ": ";
            cin >> data;
            linked_list->add_node(data);
            size++;
            break;
        }
        case 2:
        {
            cout << "Enter the data for node to be removed: ";
            cin >> data;
            linked_list->remove_node(data);
            size--;
            break;
        }
        case 3:
        {
            Node *temp = linked_list->head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            break;
        }
        case 4:
        {
            int position;
            cout << "Enter the position to insert node: ";
            cin >> position;
            cout << "Enter the data for node: ";
            cin >> data;
            linked_list->insert_node(data, position);
            size++;
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    }
}