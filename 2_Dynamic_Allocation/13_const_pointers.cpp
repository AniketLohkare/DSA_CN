#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    int j = 21;
    const int *p = &i;
    // (*p)++  not allowed
    p++;
    p = &j;

    int *const p2 = &j;
    (*p2)++;
    //  p2++; not allowed
    //  p2 = &i;  not allowed

    int const *const p3 = &i;
    // p++;    not allowed
    // (*p)++;  not allowed
}