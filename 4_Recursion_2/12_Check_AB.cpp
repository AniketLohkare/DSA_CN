#include <bits/stdc++.h>
using namespace std;

bool checkABHelper(char input[], int start)
{
    if (input[start] == '\0')
    {
        return true;
    }

    if (input[start] != 'a')
    {
        return false;
    }

    if (input[start + 1] != '\0' && input[start + 2] != '\0')
    {
        if (input[start + 1] == 'b' && input[start + 2] == 'b')
        {
            return checkABHelper(input, start + 3);
        }
    }
    return checkABHelper(input, start + 1);
}

bool checkAB(char input[])
{
    int start = 0;
    bool ans = checkABHelper(input, start);
    return ans;
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
