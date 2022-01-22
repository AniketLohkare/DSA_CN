#include <iostream>
using namespace std;

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int c = max(a, b);
    cout << c << endl;

    int x, y;
    x = 41;
    y = 35;
    cout << max(x, y) << endl;
}