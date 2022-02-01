#include <bits/stdc++.h>
using namespace std;

string getString(int n)
{
    if (n == 2)
        return "abc";
    if (n == 3)
        return "def";
    if (n == 4)
        return "ghi";
    if (n == 5)
        return "jkl";
    if (n == 6)
        return "mno";
    if (n == 7)
        return "pqrs";
    if (n == 8)
        return "tuv";
    if (n == 9)
        return "wxyz";
    return " ";
}

void printKeypadHelper(int num, string output)
{
    // Base Case
    if (num == 0)
    {
        cout << output << endl;
        return;
    }

    // Small Calculation
    int lastDigit = num % 10;
    int smallNumber = num / 10;

    string options = getString(lastDigit);

    for (int i = 0; i < options.length(); i++)
    {
        // Recursive Call
        printKeypadHelper(smallNumber, options[i] + output);
    }
}

void printKeypad(int num)
{
    string output = "";
    printKeypadHelper(num, output);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
