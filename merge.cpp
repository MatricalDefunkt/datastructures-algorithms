#include <iostream>
using namespace std;

void merge(int *left, int left_size, int *right, int right_size, int *arr)
{
  int i = 0, j = 0, k = 0;
  while (i < left_size && j < right_size)
  {
    if (left[i] < right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < left_size)
  {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < right_size)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergesort(int arr[], int size)
{
  if (size < 2)
  {
    return;
  }
  int mid = size / 2;
  int left[mid];
  int right[size - mid];
  for (int i = 0; i < mid; i++)
  {
    left[i] = arr[i];
  }
  for (int i = mid; i < size; i++)
  {
    right[i - mid] = arr[i];
  }
  mergesort(left, mid);
  mergesort(right, size - mid);
  merge(left, mid, right, size - mid, arr);
}

int main()
{
  int arr[] = {1, 2, 4, 3, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  mergesort(arr, size);
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}