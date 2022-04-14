#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int input[], int n, int k)
{
    priority_queue<int> pq;

    // Insert first k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    // Insert k - n elements and place elements in the correct index
    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    // pop remainging elements and place them into the array
    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
}
