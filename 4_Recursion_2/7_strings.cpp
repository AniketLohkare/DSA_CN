#include <bits/stdc++.h>
using namespace std;
int main()
{
    string *sp = new string;
    *sp = "aniket";
    cout << sp << endl;
    cout << *sp << endl;

    string s;
    // getline(cin, s);
    cout << s << endl;
    s = "programming";
    cout << s << endl;
    cout << s[0] << endl;

    string s2;
    s2 = "coding";
    cout << s2 << endl;

    string s3 = s + s2;
    cout << s3 << endl;

    s += s2;
    cout << s << endl;

    cout << s.size() << endl;
    cout << s2.length() << endl;

    cout << s.substr(11) << endl;
    cout << s.substr(11, 3) << endl;
    cout << s.find("coding") << endl;

    return 0;
}