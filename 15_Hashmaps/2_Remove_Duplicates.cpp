#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int input[], int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;

    for (int i = 0; i < size; i++)
    {
        if (seen.count(input[i]) > 0)
        {
            continue;
        }
        seen[input[i]] = true;
        output.push_back(input[i]);
    }

    return output;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};

    vector<int> output = removeDuplicates(arr, 11);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}