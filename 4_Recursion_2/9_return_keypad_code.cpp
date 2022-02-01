#include <bits/stdc++.h>
using namespace std;

string getString(int n)
{
    if (n == 2)
    {
        return "abc";
    }
    if (n == 3)
    {
        return "def";
    }
    if (n == 4)
    {
        return "ghi";
    }
    if (n == 5)
    {
        return "jkl";
    }
    if (n == 6)
    {
        return "mno";
    }
    if (n == 7)
    {
        return "pqrs";
    }
    if (n == 8)
    {
        return "tuv";
    }
    if (n == 9)
    {
        return "wxyz";
    }
    return " ";
}

int keypad(int num, string output[])
{
    // Base Case
    if (num == 0 || num == 1)
    {
        output[0] = "";
        return 1;
    }

    // Recursive Call
    int smallNum = num / 10;
    int smallOutput = keypad(smallNum, output);

    // Small Calculation
    int lastDigit = num % 10;
    string options = getString(lastDigit);

    // Copying output array into options.length times
    for (int i = 0; i < options.length() - 1; i++)
    {
        for (int j = 0; j < smallOutput; j++)
        {
            output[j + (i + 1) * smallOutput] = output[j];
        }
    }

    // Filling last index of output array by adding element of optins strng
    int k = 0;
    for (int i = 0; i < options.length(); i++)
    {
        for (int j = 0; j < smallOutput; j++)
        {
            output[k] = output[k] + options[i];
            k++;
        }
    }
    return smallOutput * options.length();
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
