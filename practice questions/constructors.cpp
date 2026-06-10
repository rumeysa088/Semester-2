#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int roll;
    
    Student(){

    }
    Student(string name,int roll){
               this->name=name;
               this->roll=roll;
            }
    void print(){
        cout<<"Name: "<<this->name<<"\tRoll: "<<roll<<endl;
    }        
      
};
int main(){
    Student s1;
    s1.name="rumaisa";
    s1.roll=19;
    Student s2("Ayesha",20);
    Student s3=s1;
    s3.roll=21;
    Student s4(s1);
    // cout<<"Name: "<<s1.name<<"\tRoll: "<<s1.roll<<endl;
    // cout<<"Name: "<<s2.name<<"\tRoll: "<<s2.roll<<endl;
    // cout<<"Name: "<<s3.name<<"\tRoll: "<<s3.roll<<endl;
    //   cout<<"Name: "<<s4.name<<"\tRoll: "<<s4.roll<<endl;
    s1.print();
}