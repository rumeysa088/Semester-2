#include<iostream>
using namespace std;
class Student{
   
 public:  
    string name;
    int roll;
  
    Student(string name,int roll){
               this->name=name;
               this->roll=roll;
            }
        
};
void change(Student *c){
    (*c).name="Ali";
}
int main(){
    Student s1("Rumaisa",19);
    
    Student* p1=&s1;
  
    change(p1);
    // cout<<"Name: "<<(*p1).name<<"\tRoll: "<<p1->roll<<endl;
    cout<<"Name: "<<s1.name<<"\tRoll: "<<s1.roll<<endl;
    
}