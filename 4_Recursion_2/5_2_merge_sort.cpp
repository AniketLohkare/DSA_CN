#include <bits/stdc++.h>
using namespace std;

void mergeTwoSortedArrys(int input[], int start, int end)
{
    // Creating Output Aray
    int size = start + end + 1;
    int *output = new int[size];

    // Typical Merge Sort Code
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
        {
            output[k] = input[i];
            i++;
            k++;
        }
        else
        {
            output[k] = input[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        output[k] = input[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        output[k] = input[j];
        j++;
        k++;
    }

    // Copy elements of output array to original input array
    int m = 0;
    for (int i = start; i <= end; i++)
    {
        input[i] = output[m];
        m++;
    }

    // deleting output array (created dynamically)
    delete[] output;
}

void mergeSortHelper(int input[], int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    // Small Calculation
    int mid = (start + end) / 2;

    // Recursivv Call
    mergeSortHelper(input, start, mid);
    mergeSortHelper(input, mid + 1, end);
    mergeTwoSortedArrys(input, start, end);
}

void mergeSort(int input[], int size)
{
    int start = 0, end = size - 1;
    mergeSortHelper(input, start, end);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}