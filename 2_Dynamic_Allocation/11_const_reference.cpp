#include <iostream>
using namespace std;
int main()
{
    // constant int declaration
    int const a = 24;
    const int i = 10;
    // i = 12;  (can not change because it is constant)
    cout << i << endl;

    // constant reference from a non constant int
    int j = 15;
    const int &k = j;
    // k++;   (can not chanbe because it is constant)
    j++;
    cout << k << endl;

    // constant reference from a constant int
    const int j2 = 45;
    const int &k2 = j2;
    // j2++   (can not be chanbe because
    // k2++             it is constant)

    // reference from a const int
    const int j3 = 15;
    // int &k3 = j3; can not declare because it is referring a constant int
}