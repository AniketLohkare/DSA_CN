#include <bits/stdc++.h>
using namespace std;

#include <queue>

int main()
{
    // Max heap
    priority_queue<int> pq;

    // Min heap
    // priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(16);
    pq.push(11);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "Size " << pq.size() << endl;
    cout << "Top " << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}