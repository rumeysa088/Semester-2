#include<iostream>
using namespace std;
class Person{
public:
    void show(){cout<<"Person Function"<<endl;}
};
class Student : public Person {
};
class Teacher : public Person {
};
class TA:public Student,public Teacher {
};
int main(){
    TA t;
    t.Student::show(); // Resolves ambiguity temporarily
    t.Teacher::show(); 
    return 0;
}