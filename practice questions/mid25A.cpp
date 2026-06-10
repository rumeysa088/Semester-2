#include<iostream>
using namespace std;
class BAMS{  //bank acc management system
   static int accCount;
   const string bankName="HBL";
   const int accNum;
   int balance;
public:
  BAMS():accNum(accCount+1000){ balance=0; accCount++;}
  static int getCount(){return accCount;}
  void display(){
     cout<<"Bank Name: "<<bankName<<"\nAccount Number: "<<accNum<<"\nBalance: "<<balance<<endl;
  }
  void deposit(int amount){ if (amount>0){balance+=amount;cout<<"Deposit Successful!"<<endl;}}
  void withdraw(int amount){if(amount<=balance){balance-=amount;cout<<"Withdrawal Successfull"<<endl;}else cout<<"Withdraw Failed!"<<endl;}
  ~BAMS(){ accCount--;}
};
int BAMS::accCount=0;
int main(){
   BAMS* a1=new BAMS();
   BAMS* a2=new BAMS();
   a1->deposit(1000);
   a1->withdraw(500);
   delete a1;
   cout<<"Count: "<<BAMS::getCount();
   delete a2;
}

#include <iostream>
using namespace std;

class Department {
    string name;
    static int deptCount;

public:
    Department(string n) : name(n) {
        deptCount++;
    }

    ~Department() {
        deptCount--;
    }

    string getName() {
        return name;
    }

    static int getCount() {
        return deptCount;
    }
};

int Department::deptCount = 0;

class Employee {
    const int ID;
    const string name;
    Department* const dept;   // department cannot change
    static int empCount;

public:
    Employee(string n, Department* d)
        : ID(1000 + empCount), name(n), dept(d) {
        empCount++;
    }

    ~Employee() {
        empCount--;
    }

    void display() {
        cout << "Employee ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << dept->getName() << endl;
        cout << endl;
    }

    static int getCount() {
        return empCount;
    }
};

int Employee::empCount = 0;

int main() {

    // Create departments
    Department* d1 = new Department("CS");
    Department* d2 = new Department("Math");

    // Create employees
    Employee* e1 = new Employee("Ali", d1);
    Employee* e2 = new Employee("Asif", d1);
    Employee* e3 = new Employee("Sara", d2);

    // Display employees
    e1->display();
    e2->display();
    e3->display();

    cout << "Total Employees: " << Employee::getCount() << endl;
    cout << "Total Departments: " << Department::getCount() << endl;

    cout << endl << "Deleting employees..." << endl;

    delete e1;
    delete e2;
    delete e3;

    cout << "Total Employees: " << Employee::getCount() << endl;

    cout << endl << "Deleting departments..." << endl;

    delete d1;
    delete d2;

    cout << "Total Departments: " << Department::getCount() << endl;

    return 0;
}

#include<iostream>
using namespace std;
class Staff{
protected:
    const int ID;
    const string name;
public:
    Staff(string n):ID(count+1000),name(n){count++;}
    virtual void display(){
        cout<<"ID: "<<ID<<"\nName: "<<name<<endl;
    }
    static int count;
    ~Staff() { count--; }
};int Staff::count=0;
class Professor:public Staff{
   string subject;
public:
    Professor(string s,string n):Staff(n){subject=s;}
    void display(){
        cout<<"ID: "<<ID<<"\nName: "<<name<<"\nSubject:"<<subject <<endl;
    }
};
class Administrative:public Staff{
    string department;
public:
    Administrative(string d,string n):Staff(n){department=d;}
    void display(){
        cout<<"ID: "<<ID<<"\nName: "<<name<<"\nDepartment: "<<department<<endl;
    }
};
int main(){
   Professor* p=new Professor("OOP","Obaid");
   Administrative* a=new Administrative("CS","Ali");
   cout<<"Staff Count: "<<Staff::count<<endl;
   delete p;delete a;
}