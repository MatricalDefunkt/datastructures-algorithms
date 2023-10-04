#include <iostream>

template <typename T>
class Queue
{
private:
  std::vector<T> queue;

public:
  void enqueue(T value)
  {
    queue.push_back(value);
  }
  T dequeue()
  {
    T value = queue.front();
    queue.erase(queue.begin());
    return value;
  }
  T peek()
  {
    return queue.front();
  }
  bool is_empty()
  {
    return queue.empty();
  }

  std::string operator<<(const Queue<T> &queue)
  {
    std::string output = "";
    for (int i = 0; i < queue.size(); i++)
    {
      output += queue[i] + " ";
    }
    return output;
  }
};

int main()
{
  std::string menu = "1. Enqueue\n2. Dequeue\n3. Peek\n4. Is Empty\n5. Exit\n";

  while (true)
  {
    std::cout << menu;
    int choice;
    std::cin >> choice;
    Queue<int> queue;
    switch (choice)
    {
    case 1:
    {
      std::cout << "Enter value: ";
      int value;
      std::cin >> value;
      queue.enqueue(value);
      break;
    }
    case 2:
    {
      std::cout << queue.dequeue() << std::endl;
      break;
    }
    case 3:
    {
      std::cout << queue.peek() << std::endl;
      break;
    }
    case 4:
    {
      std::cout << queue.is_empty() << std::endl;
      break;
    }
    case 5:
    {
      return 0;
    }
    default:
    {
      std::cout << "Invalid choice" << std::endl;
      break;
    }
    }
  }
}