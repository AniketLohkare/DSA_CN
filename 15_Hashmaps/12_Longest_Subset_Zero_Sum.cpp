#include <iostream>
using namespace std;

#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    unordered_map<int, int> sumAtIndex;

    int maxLength = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLength = i + 1;
        }
        else if (sumAtIndex.find(sum) != sumAtIndex.end())
        {
            maxLength = max(maxLength, i - sumAtIndex[sum]);
        }
        else
        {
            sumAtIndex[sum] = i;
        }
    }

    return maxLength;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}