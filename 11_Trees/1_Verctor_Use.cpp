#include <bits/stdc++.h>
using namespace std;
#include <vector>

int main()
{
    vector<int> v;
    // vector<int> *vp = new vector<int>();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;
    /*
    Don't use [] for inserting elements
    v[3] = 1002;
    v[4] = 1234;
    */

    v.push_back(23);
    v.push_back(234);

    v.pop_back();

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    /*
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;

    cout << "Size : " << v.size() << endl;

    cout << v.at(2) << endl;
    cout << v.at(6) << endl;
    */

    return 0;
}