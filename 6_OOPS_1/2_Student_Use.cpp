#include <bits/stdc++.h>
using namespace std;
#include "1_Student_Class.cpp";

int main()
{
    Student s1;
    s1.rollNumber = 101;
    s1.age = 23;
    cout << "roll number of s1 " << s1.rollNumber << endl;
    cout << "age of s1 " << s1.age << endl;

    Student *s2 = new Student;
    (*s2).rollNumber = 102;
    (*s2).age = 20;
    cout << "roll number of s2 " << (*s2).rollNumber << endl;
    cout << "age of s2 " << (*s2).age << endl;

    Student *s3 = new Student;
    s3->rollNumber = 105;
    s3->age = 25;
    cout << "roll number of s3 " << s3->rollNumber << endl;
    cout << "age of s3 " << s3->age << endl;

    return 0;
}