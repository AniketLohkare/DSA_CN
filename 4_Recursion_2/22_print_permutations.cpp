#include <bits/stdc++.h>
using namespace std;

void helper(string s, string output)
{
    if (s.length() <= 0)
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < s.length(); ++i)
    {
        string temp = s;
        rotate(temp.begin(), temp.begin() + i, temp.end());
        helper(temp.substr(1), output + temp[0]);
    }
}

void printPermutations(string input)
{
    string output = "";
    helper(input, output);
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
    return 0;
}