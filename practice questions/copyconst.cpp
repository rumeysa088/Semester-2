// #include<iostream>
// using namespace std;
// class Student{

//     public:
//     string name;
//     int* marks;
    
   
//     Student(){
//                marks=new int(10);  //copy ctors are used cz incase of pointers in a class direct assignment of objects like s1=s2 creates shallow copy
//             } 
   
//      ~Student(){
//         delete marks;
//      }    
      
// };
// int main(){    
//     Student s; 
//     *(s.marks)=90;
//     Student s2=s;   //creates shallow copy fix this issue by making a copy contructor 
    
//     *(s2.marks)=30;
 
//     cout<<"S marks"<<*(s.marks);
//     cout<<"\n s2 marks"<<*(s2.marks);
// }

#include<iostream>
using namespace std;
class Student {
public:
    string name;
    int* marks;

    Student() {
        marks = new int(10);
    }

    // COPY CONSTRUCTOR
    Student(const Student& s) {
        marks = new int(*s.marks);
    }

    ~Student() {
        delete marks;
    }
};
int main(){    
    Student s; 
    *(s.marks)=90;
    Student s2=s;   
    
    *(s2.marks)=30;
 
    cout<<"S marks"<<*(s.marks);
    cout<<"\n s2 marks"<<*(s2.marks);
}
