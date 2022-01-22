#include <bits/stdc++.h>
using namespace std;

int stringToNumber(char input[])
{
    int len = strlen(input);

    if (len == 1)
        return input[0] - '0';

    int firstDigit = input[0] - '0';
    int lastDigits = stringToNumber(input + 1);
    return firstDigit * pow(10, len - 1) + lastDigits;
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
    return 0;
}