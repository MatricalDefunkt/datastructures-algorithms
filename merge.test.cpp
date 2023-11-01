#include <iostream>
#include <cassert>
#include "merge.cpp"

void test_mergesort()
{
  int arr[] = {5, 4, 3, 2, 1};
  int sorted_arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergesort(arr, size);

  for (int i = 0; i < size; i++)
  {
    assert(arr[i] == sorted_arr[i]);
  }

  std::cout << "All tests passed for mergesort." << std::endl;
}

int main()
{
  test_mergesort();
  return 0;
}