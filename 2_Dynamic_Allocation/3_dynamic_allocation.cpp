#include <iostream>
using namespace std;
int main()
{
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    double *pd = new double;
    *pd = 5.14;
    cout << *pd << endl;

    char *pc = new char;
    *pc = 'H';
    cout << *pc << endl;

    // Arrays
    int *pa = new int[50];

    int n;
    cin >> n;
    int *pa2 = new int[n];
    pa2[0] = 10;
    cout << pa2[0] << endl;
}