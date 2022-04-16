#include <bits/stdc++.h>
#include <unordered_map>
#include <cstring>
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;

    // Insert

    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    ourMap["def"] = 2; // Shortcut

    // Find or access

    cout << ourMap["abc"] << endl;
    cout << ourMap.at("def") << endl;

    // cout << ourMap.at("ghi") << endl;
    cout << "Size : " << ourMap.size() << endl;
    cout << ourMap["ghi"] << endl;
    cout << "Size : " << ourMap.size() << endl;

    // Check Presence
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }

    // Erase
    ourMap.erase("ghi");
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }
    cout << "Size : " << ourMap.size() << endl;

    return 0;
}