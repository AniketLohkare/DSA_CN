#include <iostream>
using namespace std;

#include <unordered_map>

int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        maxFreq = max(maxFreq, freq[arr[i]]);
    }

    int maxFreqElement;
    for (int i = 0; i < n; i++)
    {
        if (maxFreq == freq[arr[i]])
        {
            maxFreqElement = arr[i];
            break;
        }
    }
    return maxFreqElement;
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}

// 13
// 2 12 2 11 12 2 1 2 2 11 12 2 6