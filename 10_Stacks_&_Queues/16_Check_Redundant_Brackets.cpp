#include <iostream>
#include <string>
using namespace std;

#include <stack>
bool checkRedundantBrackets(string expression)
{
    stack<char> s;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ')')
        {
            int count = 0;
            while (s.top() != '(')
            {
                count++;
                s.pop();
            }
            s.pop();
            if (count <= 1)
            {
                return true;
            }
        }
        else
        {
            s.push(expression[i]);
        }
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}