#include<iostream>
using namespace std;
class Employee{
public:
    int ID;
    int salary;
    void showEmployee(){ cout<<"ID: "
        <<ID<<"\nsalary: "<<salary<<endl;}
};
class Manager:public Employee{
public:
    int bonus;
    void showManager(){ cout<<"Salary + Bonus: "
        <<(salary+bonus)<<endl;}
};
int main(){
   Manager m1;
   m1.ID=123;m1.salary=150000;m1.bonus=3000;
   m1.showManager();
}