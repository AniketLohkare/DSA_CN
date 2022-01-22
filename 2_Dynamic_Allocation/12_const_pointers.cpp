#include <iostream>
using namespace std;

void f(const int *p)
{
    // (*p)++;   not allowed
}

void g(const int &a)
{
    // a++; not allowed
}

int main()
{
    const int i = 10;
    // int *p = &i; can not store address in normal pointer
    const int *p = &i;
    // (*p)++; not allowed

    int j = 12;
    const int *p2 = &j;
    j++;
    cout << *p2 << endl;

    int k = 20;
    int *p3 = &k;
    f(p3);
    g(k);
}