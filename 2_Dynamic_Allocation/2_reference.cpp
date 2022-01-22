#include <iostream>
using namespace std;

void increment(int &a)
{
    a++;
}

// bad practice
int &f(int n)
{
    int a = n;
    return a;
}

// bad practice
int *f2()
{
    int i = 10;
    return &i;
}

int main()
{
    int i = 10;
    int &j = i;

    int *p = f2();

    // int &k = f(i);
    // cout << k << endl;

    // increment(i);
    // cout << i << endl;

    // i++;
    // cout << i << endl;
    // cout << j << endl;

    // int k = 50;
    // j = k;
    // cout << i << endl;
    // cout << j << endl;
}