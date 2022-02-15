#include <bits/stdc++.h>
using namespace std;
#include "3_Student_Class.cpp";
int main()
{
    Student s1;
    s1.display();

    Student s2;

    Student *s3 = new Student;
    s3->display();

    cout << "Parameterized constructor Demo" << endl;
    Student s4(10);
    s4.display();

    Student *s5 = new Student(15);
    s5->display();

    Student s6(20, 54);
    s6.display();

    Student *s7 = new Student(19, 208);
    s7->display();

    Student s8(101, 25);
    cout << "Address of s8 " << &s8 << endl;
    s1.display();

    Student s9(20);
    s2.display();

    return 0;
}