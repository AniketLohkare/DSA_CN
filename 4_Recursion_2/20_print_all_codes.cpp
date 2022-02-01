#include <bits/stdc++.h>
using namespace std;

void helper(string input, string output)
{
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }

    int s1 = input[0] - '0' + 'a' - 1;
    helper(input.substr(1), output + (char)s1);
    if (input[1] != '\0')
    {
        int s2 = ((input[0] - '0') * 10) + (input[1] - '0');
        if (s2 >= 10 && s2 <= 26)
        {
            s2 = s2 + 'a' - 1;
            helper(input.substr(2), output + (char)s2);
        }
    }
}

void printAllPossibleCodes(string input)
{
    string output = "";
    helper(input, output);
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);

    return 0;
}