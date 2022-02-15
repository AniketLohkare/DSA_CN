#include <bits/stdc++.h>
using namespace std;
#include "8_Student_Class.cpp"

int main()
{
    Student s1;
    cout << s1.rollNumber << " " << s1.age << endl;
    cout << s1.totoalStudents << endl;

    s1.totoalStudents = 20;

    Student s2;
    cout << s2.totoalStudents << endl;

    cout << Student ::totoalStudents << endl;

    return 0;
}