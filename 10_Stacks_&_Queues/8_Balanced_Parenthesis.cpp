#include <iostream>
#include <string>
using namespace std;

#include <stack>

bool isBalanced(string expression)
{
    stack<char> s;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        else
        {
            if (s.empty())
            {
                s.push(expression[i]);
            }
            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}