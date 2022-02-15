#include <bits/stdc++.h>
using namespace std;
#include "1_Student_Class.cpp"

int main()
{
	char name[] = "abcd";
	Student s1(20, name);
	s1.display();

	Student s2(s1);

	s2.name[0] = 'x';
	s1.display();
	s2.display();
}
