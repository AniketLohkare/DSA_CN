class Student
{
    static int totoalStudents; // total number of students present
public:
    int rollNumber;
    int age;

    Student()
    {
        totoalStudents++;
    }

    int getRollNumber()
    {
        return rollNumber;
    }

    static int getTotalStudents()
    {
        return totoalStudents;
    }
};

int Student ::totoalStudents = 0; // Initialixe static data members