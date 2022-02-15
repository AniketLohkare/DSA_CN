#include <bits/stdc++.h>
using namespace std;
#include "11_Fraction_Class.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    // f1.print();
    // ++f1;
    // f1.print();

    // Fraction f3 = ++f1;
    // f3.print();

    f1.print();
    Fraction f3 = ++(++f1);
    f1.print();
    f3.print();

    return 0;
}