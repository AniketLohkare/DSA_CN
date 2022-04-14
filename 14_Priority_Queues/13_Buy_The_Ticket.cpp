#include <iostream>
#include <vector>
using namespace std;
#include <queue>

int buyTicket(int *arr, int n, int k)
{
    queue<int> pQueue;
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        pQueue.push(arr[i]);
        maxHeap.push(arr[i]);
    }

    int count = 0;

    while (!maxHeap.empty())
    {
        if (pQueue.front() == maxHeap.top())
        {
            if (k == 0)
            {
                return count + 1;
            }
            else
            {
                count++;
                pQueue.pop();
                maxHeap.pop();
                k--;
            }
        }
        else
        {
            pQueue.push(pQueue.front());
            pQueue.pop();
            if (k == 0)
            {
                k = pQueue.size() - 1;
            }
            else
            {
                k--;
            }
        }
    }

    return count;
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

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}