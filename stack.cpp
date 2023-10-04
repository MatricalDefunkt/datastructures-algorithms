#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
  std::vector<T> stack;

public:
  void push(T value)
  {
    stack.push_back(value);
  }
  T pop()
  {
    T value = stack.back();
    stack.pop_back();
    return value;
  }
  T peek()
  {
    return stack.back();
  }
  bool is_empty()
  {
    return stack.empty();
  }

  std::string operator<<(const Stack<T> &stack)
  {
    std::string output = "";
    for (int i = 0; i < stack.size(); i++)
    {
      output += stack[i] + " ";
    }
    return output;
  }
};

int main()
{
  std::string menu = "1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Exit\n";

  while (true)
  {
    std::cout << menu;
    int choice;
    std::cin >> choice;
    Stack<int> stack;
    switch (choice)
    {
    case 1:
    {
      std::cout << "Enter value: ";
      int value;
      std::cin >> value;
      stack.push(value);
      break;
    }
    case 2:
    {
      std::cout << "Popped: " << stack.pop() << std::endl;
      break;
    }
    case 3:
    {
      std::cout << stack.peek() << std::endl;
      break;
    }
    case 4:
    {
      std::cout << (stack.is_empty() ? "The stack is empty" : "The stack is not empty") << std::endl;
      break;
    }
    case 5:
    {
      return 0;
    }
    }
  }
}