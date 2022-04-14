#include <iostream>
using namespace std;

#include <queue>
#include <vector>

vector<int> kLargest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert k integers
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    // Insert n - k integers
    for (int i = k; i < n; i++)
    {
        if (input[i] > pq.top())
        {
            pq.pop();
            pq.push(input[i]);
        }
    }

    // Return Output into the vector
    vector<int> output;
    while (!pq.empty())
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
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

    return 0;
}
