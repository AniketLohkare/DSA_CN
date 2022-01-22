#include <iostream>
using namespace std;
int main()
{
    /*
    while (true)
    {
        int i = 10;
    }

    while (true)
    {
        int *p = new int;
    }
    */

    // single element delete in heap
    int *p = new int;
    delete p;

    p = new int;
    delete p;

    // array element delete in heap
    p = new int[100];
    delete[] p;
}