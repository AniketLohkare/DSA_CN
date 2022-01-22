#include <iostream>
using namespace std;

#include <cstring>

#include <cstring>

void removeX(char input[])
{
    int len = strlen(input);

    if (len == 0)
        return;

    if (input[0] == 'x')
    {
        for (int i = 1; i <= len; i++)
        {
            input[i - 1] = input[i];
        }

        removeX(input);
    }
    removeX(input + 1);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
