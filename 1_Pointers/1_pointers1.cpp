#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    cout << &i << endl;
    int *p = &i;
    cout << p << endl;
    cout << *p << endl;

    /*
        float f = 2.1;
        cout << &f << endl;
        float *pf = &f;
        cout << pf << endl;

        double d = 231.456;
        cout << &d << endl;
        double *pd = &d;
        cout << pd << endl;
        */
}