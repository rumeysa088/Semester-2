#include<iostream>
using namespace std;
class Person {
protected:
    string name;
public:
    void setName(string n) {name = n;}
};
class Employee : public Person {
protected:
    double salary;
public:
    void setSalary(double s) {salary = s;}
};
class Developer : public Employee {
private:
    string language;
public:
    void setLanguage(string l) {language = l;}
    void display() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Programming Language: " << language << endl;
    }
};
int main() {
    Developer d;
    d.setName("Ali");
    d.setSalary(75000);
    d.setLanguage("C++");
    d.display();
    return 0;
}