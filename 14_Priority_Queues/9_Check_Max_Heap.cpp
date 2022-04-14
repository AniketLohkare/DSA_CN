#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    for (int i = 0; 2 * i + 1 < n; i++)
    {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = leftChildIndex + 1;

        if (arr[i] < arr[leftChildIndex])
        {
            return false;
        }

        if (rightChildIndex < n)
        {
            if (arr[i] < arr[rightChildIndex])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}