#include <iostream>
using namespace std;
int main()
{
       int i = 10;
       int *p = &i;
       cout << p << endl;

       p = p + 1;
       cout << p << endl;

       p = p + 2;
       cout << p << endl;

       p = p - 2;
       cout << p << endl;

       double d = 231.45;
       double *dp = &d;
       cout << dp << endl;
       dp++;
       cout << dp << endl;
}