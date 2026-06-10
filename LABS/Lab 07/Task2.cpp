#include<iostream>
using namespace std;
class Employee{
public:
    void calculateSalary(){cout<< "Calculating Salary..."<<endl;}
};
class Manager:public Employee{
public:
    void calculateSalary(){cout<< "Salary: 20K$"<<endl;}
};
class Developer:public Employee{
public:
    void calculateSalary(){cout<< "Salary: 10K$"<<endl;}
};
class Intern:public Employee{
public:
    void calculateSalary(){cout<< "Salary: 5K$"<<endl;}
};
int main(){
    Employee e; Manager m; Developer d;Intern i;
    e.calculateSalary();
    m.calculateSalary();
    d.calculateSalary();
    i.calculateSalary();
}