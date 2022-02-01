#include <bits/stdc++.h>
using namespace std;

int subSequences(string input, string output[])
{
    // Base Case
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    // Recursive Call
    int smallOutput = subSequences(input.substr(1), output);

    // Small Calculation
    for (int i = 0; i < smallOutput; i++)
    {
        output[i + smallOutput] = input[0] + output[i];
    }

    return 2 * smallOutput;
}

int main()
{
    string input;
    cin >> input;
    int string_size = input.size();

    int output_size = pow(2, input.size());
    string *output = new string[output_size];

    int count = subSequences(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    delete[] output;

    return 0;
}