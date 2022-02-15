#include <bits/stdc++.h>
using namespace std;
#include "11_Fraction_Class.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f3 = f1 + f2;
    Fraction f4 = f1 * f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();

    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }

    return 0;
}