#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class SinglyLinkedList
{
private:
  Node *head;

public:
  SinglyLinkedList()
  {
    head = NULL;
  }

  // Insert at front
  void insert_front(int data)
  {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
  }

  // Insert at end
  void insert_end(int data)
  {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
      head = new_node;
      return;
    }

    Node *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_node;
  }

  // Insert at a given position
  void insert_at(int data, int position)
  {
    Node *new_node = new Node;
    new_node->data = data;

    if (position == 0)
    {
      new_node->next = head;
      head = new_node;
      return;
    }

    Node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
      if (current == NULL)
      {
        cout << "Invalid position" << endl;
        return;
      }
      current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
  }

  // Remove and return the first element
  int shift()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return -1;
    }

    int data = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    return data;
  }

  // Remove and return the last element
  int pop()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return -1;
    }

    if (head->next == NULL)
    {
      int data = head->data;
      delete head;
      head = NULL;
      return data;
    }

    Node *current = head;
    while (current->next->next != NULL)
    {
      current = current->next;
    }

    int data = current->next->data;
    delete current->next;
    current->next = NULL;
    return data;
  }

  // Remove the element at a given position
  int remove(int position)
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return -1;
    }

    if (position == 0)
    {
      int data = head->data;
      Node *temp = head;
      head = head->next;
      delete temp;
      return data;
    }

    Node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
      if (current->next == NULL)
      {
        cout << "Invalid position" << endl;
        return -1;
      }
      current = current->next;
    }

    int data = current->next->data;
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    return data;
  }

  // Display the list
  void display()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }

    Node *current = head;
    while (current != NULL)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  // Concatenate two lists
  void concatenate(SinglyLinkedList &list2)
  {
    if (head == NULL)
    {
      head = list2.head;
      return;
    }

    Node *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = list2.head;
  }

  // Sort the list in ascending order using bubble sort
  void sort()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }

    bool swapped;
    Node *current;
    Node *last = NULL;

    do
    {
      swapped = false;
      current = head;

      while (current->next != last)
      {
        if (current->data > current->next->data)
        {
          int temp = current->data;
          current->data = current->next->data;
          current->next->data = temp;
          swapped = true;
        }
        current = current->next;
      }
      last = current;
    } while (swapped);
  }

  // Search for a key element and display its address
  void search(int key)
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }

    Node *current = head;
    int position = 0;
    while (current != NULL)
    {
      if (current->data == key)
      {
        cout << "Key element found at position " << position << endl;
        return;
      }
      current = current->next;
      position++;
    }
    cout << "Key element not found" << endl;
  }
};

int main()
{
  SinglyLinkedList list;
  SinglyLinkedList list2;
  int choice, data, position, key;

  do
  {
    cout << "1. Insert at front" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert at a given position" << endl;
    cout << "4. Remove and return the first element" << endl;
    cout << "5. Remove and return the last element" << endl;
    cout << "6. Remove the element at a given position" << endl;
    cout << "7. Display the list" << endl;
    cout << "8. Concatenate two lists" << endl;
    cout << "9. Sort the list in ascending order" << endl;
    cout << "10. Search for a key element" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter data to insert: ";
      cin >> data;
      list.insert_front(data);
      break;

    case 2:
      cout << "Enter data to insert: ";
      cin >> data;
      list.insert_end(data);
      break;

    case 3:
      cout << "Enter data to insert: ";
      cin >> data;
      cout << "Enter position to insert: ";
      cin >> position;
      list.insert_at(data, position);
      break;

    case 4:
      cout << "Removed element: " << list.shift() << endl;
      break;

    case 5:
      cout << "Removed element: " << list.pop() << endl;
      break;

    case 6:
      cout << "Enter position to remove: ";
      cin >> position;
      cout << "Removed element: " << list.remove(position) << endl;
      break;

    case 7:
      list.display();
      break;

    case 8:
      cout << "Enter elements of second list (0 to stop): ";
      while (true)
      {
        cin >> data;
        if (data == 0)
        {
          break;
        }
        list2.insert_end(data);
      }
      list.concatenate(list2);
      break;

    case 9:
      list.sort();
      cout << "List sorted in ascending order" << endl;
      break;

    case 10:
      cout << "Enter key element to search: ";
      cin >> key;
      list.search(key);
      break;

    case 0:
      cout << "Exiting..." << endl;
      break;

    default:
      cout << "Invalid choice" << endl;
      break;
    }

    cout << endl;
  } while (choice != 0);

  return 0;
}