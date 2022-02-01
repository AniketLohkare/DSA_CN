#include <iostream>
using namespace std;

void helper(int input[], int size, int output[], int oSize)
{
    // Base Case
    if (size == 0)
    {
        for (int i = 0; i < oSize; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    // Exclude 0th index
    helper(input + 1, size - 1, output, oSize);

    // Include 0th index
    output[oSize] = input[0]; // (Small Work)
    helper(input + 1, size - 1, output, oSize + 1);
}

void printSubsetsOfArray(int input[], int size)
{
    int output[10000];
    helper(input, size, output, 0);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
