#include <iostream>
using namespace std;
#include <cstring>

bool help(char input[], int start, int end)
{
    if (start >= end)
        return true;

    if (input[start] != input[end])
        return false;
    bool smallCheck = help(input, start + 1, end - 1);
    return smallCheck;
}

bool checkPalindrome(char input[])
{
    int start = 0, end = strlen(input) - 1;
    return help(input, start, end);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
