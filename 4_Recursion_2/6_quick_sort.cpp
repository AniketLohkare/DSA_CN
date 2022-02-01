#include <bits/stdc++.h>
using namespace std;

int partition(int input[], int start, int end)
{
    // Placing first element in its actual position
    int pivot = input[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (input[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;
    input[start] = input[pivotIndex];
    input[pivotIndex] = pivot;

    // Small or equal lements at left side & grater elements at right side
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (input[i] <= pivot)
        {
            i++;
        }
        else if (input[j] > pivot)
        {
            j--;
        }
        else
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSortHelper(int input[], int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }
    // Small Work (create partiton)
    int pivotIndex = partition(input, start, end);

    // Recursive Call
    quickSortHelper(input, start, pivotIndex - 1);
    quickSortHelper(input, pivotIndex + 1, end);
}

void quickSort(int input[], int size)
{
    int start = 0, end = size - 1;
    quickSortHelper(input, start, end);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
    return 0;
}