#include <bits/stdc++.h>
#include "7_mapClass.h"
using namespace std;

int main()
{
    myMap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.Insert(key, value);
    }

    cout << map.getSize() << endl;

    map.Remove("abc2");
    map.Remove("abc7");

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " : " << map.getValue(key) << endl;
    }

    cout << map.getSize() << endl;

    return 0;
}