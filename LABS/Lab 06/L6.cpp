#include<iostream>
using namespace std;
class University{
public:
    void universityInfo() { cout << "University Function" << endl;}
};
class Faculty:public University{
public:
    void facultyInfo() { cout << "Faculty Function" << endl;}
};
class Administration{
public:
    void adminInfo() {cout << "Administration Function" << endl;}
};
class HOD:public Faculty,public Administration{
public:
    void hodInfo() {  cout << "HOD Function" << endl;}
};
int main(){
    HOD h;
   h.universityInfo();  
    h.facultyInfo();     
    h.adminInfo();       
    h.hodInfo();         

}