#include <iostream>

using namespace std;

int *quick_sort(int *arr, int size)
{
    int pivot = arr[0];
    int *left = new int[size];
    int *right = new int[size];
    int left_size = 0;
    int right_size = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < pivot)
        {
            left[left_size] = arr[i];
            left_size++;
        }
        else
        {
            right[right_size] = arr[i];
            right_size++;
        }
    }

    if (left_size > 1)
    {
        left = quick_sort(left, left_size);
    }

    if (right_size > 1)
    {
        right = quick_sort(right, right_size);
    }

    int *sorted = new int[size];
    for (int i = 0; i < left_size; i++)
    {
        sorted[i] = left[i];
    }
    sorted[left_size] = pivot;
    for (int i = 0; i < right_size; i++)
    {
        sorted[left_size + 1 + i] = right[i];
    }

    delete[] left;
    delete[] right;

    return sorted;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int choice;
    cout << "1. Enter array manually\n2. Generate array randomly\nEnter your choice: ";
    cin >> choice;

    int *arr = new int[size];

    if (choice == 1)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    int *sorted = quick_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] sorted;

    return 0;
}