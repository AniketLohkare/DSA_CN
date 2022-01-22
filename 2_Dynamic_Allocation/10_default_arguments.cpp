#include <iostream>
using namespace std;

int sum(int arr[], int size, int si = 0)
{
    int ans = 0;

    for (int i = si; i < size; i++)
    {
        ans += arr[i];
    }

    return ans;
}

/*
int sum2 (int a, int b, int c = 0, int d = 0)
{
    return a + b + c + d;
}
*/

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    cout << sum(a, 10, 3) << endl;
}