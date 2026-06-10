#include<iostream>
using namespace std;
class employee{
    public:
    int salary;
    void displaySalary(){
        cout<<"Salary: "<<salary<<endl;
    }
};
class manager: public employee{
    public:
    void bonus(){
        cout<<"Bonus is 5000";
    }
};
int main(){
 manager m1;
 m1.salary=20000;
 m1.displaySalary();
 m1.bonus();
}