#include <bits/stdc++.h>
using namespace std;
#include "11_Fraction_Class.cpp"

int main()
{
    Fraction f1(10, 3);
    Fraction f2(5, 2);

    // Fraction f3 = f1++;
    // f1.print();
    // f3.print();

    (f1 += f2) += f2;
    f1.print();
    f2.print();

    return 0;
}