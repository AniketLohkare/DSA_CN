#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cout << "Enter the num of elements" << endl;
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (p[i] > max)
        {
            max = p[i];
        }
    }

    cout << "Max element is " << max << endl;
}