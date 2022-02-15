class Student
{
public:
    int rollNumber;

    // private:
    int age;

public:
    // Constructor
    ~Student()
    {
        cout << "Destructor called ! " << endl;
    }

    // Default constructor
    Student()
    {
        cout << "Constructor 1 called ! " << endl;
    }

    // Parameterized constructor
    Student(int rollNumber)
    {
        cout << "Constructor 2 called ! " << endl;
        this->rollNumber = rollNumber;
    }

    Student(int a, int r)
    {
        cout << "this " << this << endl;
        cout << "Constructor 3 called ! " << endl;
        this->age = a;
        this->rollNumber = r;
    }

    void display()
    {
        cout << rollNumber << " " << age << endl;
    }

    int getAge()
    {
        return age;
        ;
    }

    void setAge(int a, int password)
    {
        // We can add constaint here

        // a less than 0 is not allowed
        if (a < 0)
        {
            cout << "Age cannot be less than 0" << endl;
            return;
        }

        // If password is wrong
        if (password != 1234)
        {
            cout << "Wrong password" << endl;
            return;
        }
        age = a;
    }
};
