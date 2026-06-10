#include<iostream>
using namespace std;
class Person{
public:
    string name;
    int age;
    void displayInfo(){
        cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
    }
};
class Student:public Person{
public:
    int rollNum;
    void displayStudent(){
        cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
        cout<<"Roll no: "<<rollNum<<endl;
    }
};
int main(){
   Student s1;
   s1.name="Ali";s1.age=19;s1.rollNum=123;
   s1.displayStudent();
}