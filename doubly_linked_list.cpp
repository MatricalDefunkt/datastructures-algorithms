/**
 * Implement the following function for a doubly linked list
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
  Node *prev;
  Node *next;
};

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList()
  {
    head = NULL;
    tail = NULL;
  }

  void insert_front(int data)
  {
    Node *temp = new Node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL)
    {
      head->prev = temp;
    }
    else
    {
      tail = temp;
    }
    head = temp;
  }

  void insert_end(int data)
  {
    Node *temp = new Node;
    temp->data = data;
    temp->prev = tail;
    temp->next = NULL;
    if (tail != NULL)
    {
      tail->next = temp;
    }
    else
    {
      head = temp;
    }
    tail = temp;
  }

  void insert_at(int data, int position)
  {
    Node *temp = new Node;
    temp->data = data;
    Node *prev = NULL;
    Node *curr = head;
    int i = 0;
    while (curr != NULL)
    {
      if (i == position)
      {
        temp->prev = prev;
        temp->next = curr;
        if (prev != NULL)
        {
          prev->next = temp;
        }
        else
        {
          head = temp;
        }
        curr->prev = temp;
        return;
      }
      prev = curr;
      curr = curr->next;
      i++;
    }
    if (i == position)
    {
      insert_end(data);
    }
  }

  int shift()
  {
    if (head == NULL)
    {
      return -1;
    }
    Node *temp = head;
    int data = temp->data;
    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }
    else
    {
      tail = NULL;
    }
    delete temp;
    return data;
  }

  int pop()
  {
    if (tail == NULL)
    {
      return -1;
    }
    Node *temp = tail;
    int data = temp->data;
    tail = tail->prev;
    if (tail != NULL)
    {
      tail->next = NULL;
    }
    else
    {
      head = NULL;
    }
    delete temp;
    return data;
  }

  int remove(int position)
  {
    Node *prev = NULL;
    Node *curr = head;
    int i = 0;
    while (curr != NULL)
    {
      if (i == position)
      {
        if (prev != NULL)
        {
          prev->next = curr->next;
        }
        else
        {
          head = curr->next;
        }
        if (curr->next != NULL)
        {
          curr->next->prev = prev;
        }
        else
        {
          tail = prev;
        }
        int data = curr->data;
        delete curr;
        return data;
      }
      prev = curr;
      curr = curr->next;
      i++;
    }
    return -1;
  }

  Node *reverse()
  {
    Node *temp_head = this->tail;
    Node *temp_tail = this->head;

    while (temp_head != temp_tail)
    {
      temp_head->next = temp_head->prev;
      temp_head->prev = temp_tail;
      temp_head = temp_head->prev;
      temp_tail = temp_tail->next;
    }

    temp_head->next = temp_head->prev;
    temp_head->prev = nullptr;

    return this->tail;
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
};

int main()
{
  DoublyLinkedList list;
  int choice, data, position;
  string menu = "1. Insert at front\n2. Insert at end\n3. Insert at position\n4. Shift\n5. Pop\n6. Remove\n7. Display\n8. Exit\n";
  do
  {
    cout << menu;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter data: ";
      cin >> data;
      list.insert_front(data);
      break;
    case 2:
      cout << "Enter data: ";
      cin >> data;
      list.insert_end(data);
      break;
    case 3:
      cout << "Enter data: ";
      cin >> data;
      cout << "Enter position: ";
      cin >> position;
      list.insert_at(data, position);
      break;
    case 4:
      data = list.shift();
      if (data == -1)
      {
        cout << "List is empty" << endl;
      }
      else
      {
        cout << "Shifted data: " << data << endl;
      }
      break;
    case 5:
      data = list.pop();
      if (data == -1)
      {
        cout << "List is empty" << endl;
      }
      else
      {
        cout << "Popped data: " << data << endl;
      }
      break;
    case 6:
      cout << "Enter position: ";
      cin >> position;
      data = list.remove(position);
      if (data == -1)
      {
        cout << "Invalid position" << endl;
      }
      else
      {
        cout << "Removed data: " << data << endl;
      }
      break;
    case 7:
      list.display();
      break;
    case 8:
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "Invalid choice" << endl;
      break;
    }
  } while (choice != 8);
  return 0;
}