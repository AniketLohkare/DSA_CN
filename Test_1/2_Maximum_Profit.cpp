#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int budget[], int n)
{
    sort(budget, budget + n);

    int *cost = new int[n];

    for (int i = 0; i < n; i++)
    {
        cost[i] = budget[i] * (n - i);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (cost[i] > max)
        {
            max = cost[i];
        }
    }
    return max;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;

    return 0;
}