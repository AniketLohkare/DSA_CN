#include <bits/stdc++.h>
using namespace std;

bool checksequenece(char large[], char *small)
{
    // Base Case
    if (small[0] == '\0')
    {
        return true;
    }
    if (large[0] == '\0')
    {
        return false;
    }

    // Recursive Case
    if (large[0] == small[0])
    {
        bool a = checksequenece(++large, ++small);
        return a;
    }
    else
    {
        return checksequenece(++large, small);
    }
}
int main()
{
    char large[10000];
    char small[10000];
    cin >> large;
    cin >> small;
    bool x = checksequenece(large, small);

    if (x)
        cout << "true";
    else
        cout << "false";

    return 0;
}