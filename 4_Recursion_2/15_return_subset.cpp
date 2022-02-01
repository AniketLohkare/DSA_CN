#include <bits/stdc++.h>
using namespace std;

int subset(int input[], int n, int output[][20])
{
    // Base Case
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    // Recursive Call
    int smallOutput = subset(input + 1, n - 1, output);
    // Small Calculation
    for (int i = 0; i < smallOutput; i++)
    {
        // increasing col by 1
        int col = output[i][0] + 1;
        // Puting col length in 0th col next to i + smallOutput
        output[i + smallOutput][0] = col;
        // Puting first index of input array to next column (1)
        output[i + smallOutput][1] = input[0];
        // Copying remaning elements of size equal to col
        for (int j = 2; j <= col; j++)
        {
            // Placing elements from 2nd col untill col size
            output[i + smallOutput][j] = output[i][j - 1];
        }
    }
    // return output (will increase 2 times)
    return 2 * smallOutput;
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}