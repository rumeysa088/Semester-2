#include <iostream>
using namespace std;

class Student
{
private:
    float cgpa;

public:
    void setCGPA(float c)
    {
        if (c >= 0.0 && c <= 4.0)
        {
            cgpa = c;
        }
        else
        {
            cout << "Invalid CGPA! CGPA must be between 0.0 and 4.0" << endl;
        }
    }
};
int main()
{
    Student s;
    s.setCGPA(3.5);
    s.setCGPA(4.8);
    return 0;
}