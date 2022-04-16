#include <iostream>
#include <vector>
using namespace std;

#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> visitedElements;
    unordered_map<int, int> elementsToIndexMapping;

    for (int i = 0; i < n; i++)
    {
        elementsToIndexMapping[arr[i]] = i;

        if (visitedElements.count(arr[i]) == 0)
        {
            visitedElements[arr[i]] = true;
        }
    }

    vector<int> longestSequence;

    int globalMaxSequenceLength = 1;
    int globalMinStartIndex = 0;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int currentMinIndex = i;
        int count = 0;
        int tempNum = num;

        // Forward
        while (visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true)
        {
            visitedElements[tempNum] = false;
            count++;
            tempNum++;
        }

        // Backward
        tempNum = num - 1;
        while (visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true)
        {
            visitedElements[tempNum] = false;
            currentMinIndex = elementsToIndexMapping[tempNum];
            count++;
            tempNum--;
        }

        if (count > globalMaxSequenceLength)
        {
            globalMaxSequenceLength = count;
            globalMinStartIndex = currentMinIndex;
        }
        else if (count == globalMaxSequenceLength)
        {
            if (currentMinIndex < globalMinStartIndex)
            {
                globalMinStartIndex = currentMinIndex;
            }
        }
    }

    int globalStartNum = arr[globalMinStartIndex];
    longestSequence.push_back(globalStartNum);

    if (globalMaxSequenceLength > 1)
    {
        longestSequence.push_back(globalStartNum + globalMaxSequenceLength - 1);
    }

    return longestSequence;
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

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
