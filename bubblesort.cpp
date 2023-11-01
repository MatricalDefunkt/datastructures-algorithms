// Bubble sort

#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> arr)
{
  int size = arr.size();
  for (int i = 0; i < size - 1; i++)
  {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j + 1] < arr[j])
      {
        swap(arr[j + 1], arr[j]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

int main()
{
  vector<int> arr;
  cout << "Enter the elements seperated by space: ";
  int input;
  while (cin >> input)
  {
    arr.push_back(input);
  }
  bubble_sort(arr);
}