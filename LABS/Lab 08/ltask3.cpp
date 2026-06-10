#include <iostream>
using namespace std;
class Person {
private:
    int ID;
    string name;
public:
    Person(int i, string n) : ID(i), name(n) {}
    void displayPerson() {
        cout << "ID: " << ID << ", Name: " << name << endl;}
};
class Student : public Person {
protected:
    float GPA;
public:
    Student(int i, string n, float g) : Person(i,n), GPA(g) {}
    void displayStudent() { 
        displayPerson(); 
        cout << "GPA: " << GPA << endl; }
};

class Employee : public Person {
protected:
    float Salary;
public:
    Employee(int i, string n, float s) : Person(i,n), Salary(s) {}
    void displayEmployee() { 
        displayPerson(); 
        cout << "Salary: " << Salary << endl; }
};
class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(int i1, string n1, float g, int i2, string n2, float s)
        : Student(i1,n1,g), Employee(i2,n2,s) {}
    void displayTA() {
        Student::displayStudent();   
        Employee::displayEmployee();  }
};
int main() {
    TeachingAssistant ta(1,"Ali",3.8, 2,"Ali", 5000);
    ta.displayTA();
    return 0;
}