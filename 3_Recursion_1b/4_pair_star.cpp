#include <bits/stdc++.h>
using namespace std;

void pairStar(char input[])
{
    int len = strlen(input);

    if (len == 1)
        return;

    if (input[0] == input[1])
    {
        for (int i = len; i > 0; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }

    pairStar(input + 1);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
    return 0;
}