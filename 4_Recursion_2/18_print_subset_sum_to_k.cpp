#include <bits/stdc++.h>
using namespace std;

void helper(int input[], int n, int output[], int s, int k)
{
    if (n == 0)
    {
        int sum = 0;
        for (int i = 0; i < s; i++)
        {
            sum += output[i];
        }
        if (sum == k)
        {
            for (int i = 0; i < s; ++i)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        }
    }

    else
    {
        output[s] = input[0];
        helper(input + 1, n - 1, output, s + 1, k);
        helper(input + 1, n - 1, output, s, k);
    }
}

void printSubsetSumToK(int input[], int size, int k)
{
    int output[1000] = {0};
    helper(input, size, output, 0, k);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
    return 0;
}