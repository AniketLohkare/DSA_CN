#include <bits/stdc++.h>
using namespace std;
#include "3_Student_Class.cpp";

int main()
{
    Student s1;
    s1.setAge(20, 1234);
    s1.display();

    Student *s2 = new Student;
    s2->setAge(25, 1234);
    s2->display();

    return 0;
}