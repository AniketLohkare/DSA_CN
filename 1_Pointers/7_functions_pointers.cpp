#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void incrementPointer(int *p)
{
    p = p + 1;
}

void increment(int *p)
{
    (*p)++;
}

int main()
{
    int a = 10;
    int *p = &a;
    print(p);

    cout << p << endl;
    incrementPointer(p);
    cout << p << endl;

    increment(p);
    cout << *p << endl;
}