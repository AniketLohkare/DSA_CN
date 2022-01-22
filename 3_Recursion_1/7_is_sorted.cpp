#include <iostream>
using namespace std;

bool is_sorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }

    bool is_smallSorted = is_sorted(arr + 1, size - 1);
    return is_smallSorted;
}

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    bool ans = is_sorted(p, n);

    if (ans == true)
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }

    delete[] p;
}