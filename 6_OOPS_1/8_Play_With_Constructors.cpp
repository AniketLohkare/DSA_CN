#include <bits/stdc++.h>
using namespace std;
#include "3_Student_Class.cpp";

int main()
{
    Student s1; // Constructor 1 is called

    Student s2(101); // Constructor 2 is called

    Student s3(20, 102); // Constructor 3 is called

    Student s4(s3); // Copy Constructor is called

    s1 = s2; // Copy assignment operator is called

    Student s5 = s4; // Copy Constructor is called

    return 0;
}