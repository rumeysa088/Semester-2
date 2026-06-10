// #include<iostream>
// using namespace std;
// bool isPalindrome(string s){
//     int size=s.length(); int flag=1; int i,j;
//     for(i=0,j=size-1;i<size/2;i++,j--){
//         if(s[i]!=s[j]){flag=0;break;}
//     }
//     return flag;
// }
// string makePal(string s){
//     if(isPalindrome(s)){ return s;}
//     else{
//          int size=s.length();int i,j;
//     for(i=0,j=size-1;i<size/2;i++,j--){
//         if(s[i]!=s[j]){ s[i]=s[j];}
//     } return s;
//     }
// }
// int main(){
//     string str="ABBAA";
//     cout<<"Result: "<<isPalindrome(str)<<endl;
//     cout<<"Corrected string: "<<makePal(str)<<endl;
// }

// #include<iostream>
// using namespace std;

// // -------- COMPANY --------
// class Company{
//     int code;
//     string name;
//     string address;
//     int empCount=0;
// public:
//     Company(){}
//     Company(int c,string n,string a):code(c),name(n),address(a){}

//     void incempcount(){ empCount++; }
// };

// // -------- EMPLOYEE --------
// class Employee{
// protected:
//     Company& c;   // ✔ aggregation (reference)
//     string name;
//     int ID;
//     string position;
// public:
//     Employee(Company& cmp,int i,string en,string p)
//         :c(cmp),name(en),ID(i),position(p)
//     {
//         c.incempcount();   // ✔ increment original company count
//     }
// };

// // -------- FULL TIME --------
// class FullTime : public Employee{
//     int salary;
// public:
//     FullTime(Company& cmp,int i,string n,string p,int s=20000)
//         :Employee(cmp,i,n,p),salary(s){}
// };

// // -------- PART TIME --------
// class PartTime : public Employee{
//     int salaryPerHour;
//     int hoursPerWeek;
// public:
//     PartTime(Company& cmp,int i,string n,string p,int s=500,int h=20)
//         :Employee(cmp,i,n,p),salaryPerHour(s),hoursPerWeek(h){}
// };

// // -------- DEPARTMENT --------
// class Department{
//     string name;
//     int revenue;
//     int id;
//     Employee& hod;   // ✔ aggregation
// public:
//     Department(Employee& e,string n,int i,int r)
//         :hod(e),name(n),revenue(r),id(i){}
// };

// // -------- MAIN --------
// int main(){

//     Company c(111,"AYZ Corp","ABC Street");

//     FullTime e1(c,12234,"Employee1","Manager",30000);
//     PartTime e2(c,12233,"Employee2","Assistant",600,25);

//     Department d1(e1,"Dept1",1,100000);
//     Department d2(e2,"Dept2",2,200000);

// }

#include <iostream>
using namespace std;

// -------- Base Class --------
class Animal {
public:
    virtual void print() {
        cout << "Animal" << endl;
    }
};

// -------- Intermediate Class --------
class Feline : public Animal {
public:
    void print() override {
        cout << "Feline" << endl;
    }

    virtual void speak() {
        cout << "Meow" << endl;
    }
};

// -------- Derived Class Lion --------
class Lion : public Feline {
public:
    void print() override {
        cout << "Lion" << endl;
    }

    void speak() override {
        cout << "Roar" << endl;
    }

    void speak(int n) {
        for (int i = 0; i < n; i++)
            cout << "Roar" << endl;
    }
};

// -------- Derived Class Cat (example) --------
class Cat : public Feline {
public:
    void print() override {
        cout << "Cat" << endl;
    }

    void speak() override {
        cout << "Meow" << endl;
    }
};

// -------- MAIN --------
int main() {
    Animal a;
    Feline f;
    Lion l;
    Cat c;

    a.print();  // Animal
    f.print();  // Feline
    f.speak();  // Meow

    l.print();       // Lion
    l.speak();       // Roar
    l.speak(3);      // Roar 3 times

    c.print();       // Cat
    c.speak();       // Meow

    return 0;
}