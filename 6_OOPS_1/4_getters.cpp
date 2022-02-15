#include <bits/stdc++.h>
using namespace std;
#include "3_Student_Class.cpp";

int main()
{
    Student s1;
    s1.rollNumber = 101;
    cout << s1.getAge() << endl;
    s1.display();

    Student *s2 = new Student;
    (*s2).rollNumber = 102;
    cout << (*s2).getAge() << endl;
    // cout << s2->getAge() << endl;
    (*s2).display();

    return 0;
}