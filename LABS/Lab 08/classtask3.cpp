#include<iostream>
using namespace std;
class  Person{
protected:
	string name;
public:
	Person(){	}
	Person(string n):name(n){}
};
class Employee: virtual public Person{
	protected:
	int ID;
public:
	Employee(int id):ID(id),Person(){}
};
class Student: virtual public Person{
	protected:
	float GPA;
public:
	Student(float gpa):GPA(gpa),Person(){}
};
class TeachingAssistant:public Employee,public Student{
	public:
		TeachingAssistant(string n,int id,float gpa):Person(n),Employee(id),Student(gpa){}
		void display(){
			cout<<"Name: "<<name<<"\nID: "<<ID<<"\nGPA: "<<GPA<<endl;}
};
int main(){
	TeachingAssistant ta("Ali",1001,3.7);
	ta.display();
}