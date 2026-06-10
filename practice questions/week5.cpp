#include<iostream>
using namespace std;
class Employee
{
private:
 int id; string name;
public:
Employee(int id, string name)
    {
    this->id = id;
    this->name = name;
    }
Employee() {}
    void display()
    { cout<<" "<<name<< " "<< endl;}
    void set (int id, string name)
    {
    this->id = id;
    this->name = name;
    }
};
class Department {
private:
    string name; Employee HoD; int numEmployees; int
    maxEmployees; Employee *employees;                 //aggregation
public:
    Department(string name, string managerName, int managerID,
    int maxEmployees)
    : name(name), HoD( managerID,managerName),
    numEmployees(0), maxEmployees(maxEmployees) {
    employees= new Employee[maxEmployees];
    }
Department(const Department& d){
    name=d.name; numEmployees=d.numEmployees; maxEmployees=d.maxEmployees; 
    employees=new Employee[maxEmployees];
    for(int i=0;i<numEmployees;i++){
        employees[i]=d.employees[i];
    }
    Hod=d.HoD;
}
};
int main(){

}