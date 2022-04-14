#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <queue>
vector<int> kSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    // Insert first k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // Insert remaining n - k elements
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Copy Priority Queue elements in vector
    vector<int> output;

    for (int i = 0; i < k; i++)
    {
        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}