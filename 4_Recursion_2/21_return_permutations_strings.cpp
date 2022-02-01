#include <bits/stdc++.h>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input.length() == 0)
    {
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int r = returnPermutations(input.substr(1), smallOutput);
    int k = 0;
    for (int i = 0; i < smallOutput[0].length() + 1; i++)
    {
        for (int j = 0; j < r; j++)
        {
            string temp = smallOutput[j];
            output[k++] = temp.insert(i, input.substr(0, 1));
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}