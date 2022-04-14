#include <iostream>
using namespace std;
#include <queue>

void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        if (maxHeap.size() != 0 && arr[i] > maxHeap.top())
        {
            minHeap.push(arr[i]);
        }
        else
        {
            maxHeap.push(arr[i]);
        }

        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else
            {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        int median;
        int totalSize = maxHeap.size() + minHeap.size();

        if (totalSize % 2 != 0)
        {
            if (maxHeap.size() > minHeap.size())
            {
                median = maxHeap.top();
            }
            else
            {
                median = minHeap.top();
            }
        }
        else
        {
            median = 0;
            if (!maxHeap.empty())
            {
                median += maxHeap.top();
            }

            if (!minHeap.empty())
            {
                median += minHeap.top();
            }

            median = median / 2;
        }

        cout << median << " ";
    }
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

    findMedian(arr, n);

    delete[] arr;
}
