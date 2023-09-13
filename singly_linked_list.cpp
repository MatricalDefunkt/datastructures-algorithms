/**
 * Implement the following function for a linked list
 *
 * void insert_front()
 * void insert_end()
 * void insert_at()
 * int shift()
 * int pop()
 * int remove()
 * void display()
 */

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
    Node *head;
    Node *current_node;
    LinkedList(int data)
    {
        this->head = new Node(); // create new Node
        this->head->data = data;
        this->head->next = nullptr;
        this->current_node = this->head;
    }
    void insert_front(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    void insert_end(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        current_node->next = temp;
        current_node = temp;
    }
    void insert_at(int data, int position)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        Node *prev = NULL;
        Node *curr = head;
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
    int shift()
    {
        Node *temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        return data;
    }
    int pop()
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        int data = temp->data;
        delete temp;
        return data;
    }
    int remove(int position)
    {
        Node *temp = head;
        Node *prev = NULL;
        int i = 0;
        while (temp != NULL)
        {
            if (i == position)
            {
                prev->next = temp->next;
                int data = temp->data;
                delete temp;
                return data;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *intersection(Node *head1)
    {
        Node *temp = head;
        Node *temp1 = head1;
        Node *head2 = NULL;
        Node *temp2 = NULL;
        while (temp != NULL && temp1 != NULL)
        {
            if (temp->data == temp1->data)
            {
                if (head2 == NULL)
                {
                    head2 = new Node();
                    head2->data = temp->data;
                    head2->next = NULL;
                    temp2 = head2;
                }
                else
                {
                    Node *new_node = new Node();
                    new_node->data = temp->data;
                    new_node->next = NULL;
                    temp2->next = new_node;
                    temp2 = new_node;
                }
                temp = temp->next;
                temp1 = temp1->next;
            }
            else if (temp->data < temp1->data)
            {
                temp = temp->next;
            }
            else
            {
                temp1 = temp1->next;
            }
        }
        return head2;
    }
};

int main()
{
    int first_data;
    cout << "Enter data for the first node: ";
    cin >> first_data;
    LinkedList linked_list = LinkedList(first_data);

    string menu = "1. Insert at front\n2. Insert at end\n3. Insert at position\n4. Shift\n5. Pop\n6. Remove\n7. Display\n8. Exit\n";
    while (true)
    {
        int choice;
        cout << menu;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data for the node: ";
            cin >> data;
            linked_list.insert_front(data);
            break;
        }
        case 2:
        {
            int data;
            cout << "Enter data for the node: ";
            cin >> data;
            linked_list.insert_end(data);
            break;
        }
        case 3:
        {
            int data;
            int position;
            cout << "Enter data for the node: ";
            cin >> data;
            cout << "Enter position for the node: ";
            cin >> position;
            linked_list.insert_at(data, position);
            break;
        }
        case 4:
        {
            int data = linked_list.shift();
            cout << "Data shifted: " << data << endl;
            break;
        }
        case 5:
        {
            int data = linked_list.pop();
            cout << "Data popped: " << data << endl;
            break;
        }
        case 6:
        {
            int position;
            cout << "Enter position for the node: ";
            cin >> position;
            int data = linked_list.remove(position);
            cout << "Data removed: " << data << endl;
            break;
        }
        case 7:
        {
            linked_list.display();
            cout << endl;
            break;
        }
        case 8:
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