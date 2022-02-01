#include <bits/stdc++.h>
using namespace std;

int getCodes(string input, string output[10000])
{
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }

    string s1[1000], s2[1000];
    int r1, r2 = 0, k = 0;
    r1 = getCodes(input.substr(1), s1);
    if (input[1] != '\0')
    {
        r2 = getCodes(input.substr(2), s2);
    }
    int c1 = input[0] - '0' + 'a' - 1;
    for (int i = 0; i < r1; i++)
    {
        output[k++] = (char)c1 + s1[i];
    }
    int c2 = ((input[0] - '0') * 10) + input[1] - '0';
    if (c2 >= 10 && c2 <= 26)
    {
        c2 = c2 + 'a' - 1;
        for (int i = 0; i < r2; i++)
        {
            output[k++] = (char)c2 + s2[i];
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}