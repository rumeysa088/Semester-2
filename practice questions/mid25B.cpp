#include<iostream>
using namespace std;
class LMS{
    const int ID;
    static int isAvailable;
    static const string name;
    static int bookCount;
public:
    LMS():ID(bookCount+1000){bookCount++;}
    void borrow(){isAvailable--;}
    void submit(){isAvailable++;}
    ~LMS(){bookCount--;}
    static int getAvailableCount(){return isAvailable;}
};
int LMS::bookCount=0;
const string LMS::name="Liberty";
int LMS::isAvailable=bookCount;
int main(){
   LMS* b1=new LMS();
   cout<<"Book count: "<<LMS::getAvailableCount()<<endl;
   b1->borrow();
   cout<<"Book count: "<<LMS::getAvailableCount()<<endl;
   delete b1;
}

#include<iostream>
using namespace std;
class Member{
protected:
    int ID;
    const string name;
    static int memberCount;
public:
    Member(string n):ID(memberCount+1000),name(n){memberCount++;}
    ~Member(){ memberCount--; }
};
int Member::memberCount=0;
class Driver:public Member{
    int carNum;
    int wins;
public:
    Driver(int num,string n):carNum(num),wins(w),Member(n){}
    void display(){
        cout<<"ID: "<<ID<<"\nName: "<<name<<"\nCar Num: "<<carNum<<"\nWins: "<<wins<<endl;
    }
};
class Engineer:public Member{
    string specialization;
public:
    Engineer(string s,int w,string n):specialization(s),Member(n){}
    void display(){
        cout<<"ID: "<<ID<<"\nName: "<<name<<"\nSpecilization: "<<specialization<<endl;
    }
};
int main(){
  
}

#include<iostream>
using namespace std;

// Base class — holds common attributes to avoid redundancy in Driver/Engineer
class Member{
protected:
    int ID;
    const string name;
    static int memberCount;
public:
    Member(string n) : ID(memberCount + 1000), name(n){ memberCount++; }
    
    // Move constructor for base class
    Member(Member&& other) : ID(other.ID), name(move(other.name)){
        // ID stays same, memberCount unchanged (same member, just moved)
    }

    // Pure virtual — ENFORCES every subclass to implement display()
    virtual void display() = 0;

    // Virtual destructor — ensures correct cleanup when deleting via base pointer
    virtual ~Member(){ memberCount--; }

    static int getCount(){ return memberCount; }
};
int Member::memberCount = 0;

// Driver inherits from Member — only adds car-specific attributes
class Driver : public Member{
    int carNum;
    int wins;
public:
    Driver(int num, int w, string n) : carNum(num), wins(w), Member(n){}

    // Move constructor — transfers Driver data, leaves old object empty
    Driver(Driver&& other) : Member(move(other)), carNum(other.carNum), wins(other.wins){
        other.carNum = 0;
        other.wins   = 0;
        cout << "Driver move constructor called." << endl;
    }

    void display() override {
        cout << "--- Driver ---"       << endl
             << "ID:      " << ID      << endl
             << "Name:    " << name    << endl
             << "Car No:  " << carNum  << endl
             << "Wins:    " << wins    << endl;
    }

    ~Driver(){ cout << "Driver " << name << " deleted." << endl; }
};

// Engineer inherits from Member — only adds specialization
class Engineer : public Member{
    string specialization;
public:
    Engineer(string s, string n) : specialization(s), Member(n){}

    // Move constructor — transfers Engineer data
    Engineer(Engineer&& other) : Member(move(other)), specialization(move(other.specialization)){
        cout << "Engineer move constructor called." << endl;
    }

    void display() override {
        cout << "--- Engineer ---"              << endl
             << "ID:             " << ID        << endl
             << "Name:           " << name      << endl
             << "Specialization: " << specialization << endl;
    }

    ~Engineer(){ cout << "Engineer " << name << " deleted." << endl; }
};

int main(){
    // Dynamically allocated objects
    Driver*   d1 = new Driver(44, 103, "Lewis Hamilton");
    Engineer* e1 = new Engineer("Aerodynamics", "Adrian Newey");

    d1->display();
    cout << endl;
    e1->display();
    cout << endl;

    // Move semantics — transfer d1's data into d2, then delete d1
    cout << "Moving d1 into d2..." << endl;
    Driver* d2 = new Driver(move(*d1));
    delete d1;   // old object deleted after move
    cout << endl;

    cout << "d2 after move:" << endl;
    d2->display();
    cout << endl;

    cout << "Total members: " << Member::getCount() << endl;

    delete d2;
    delete e1;

    cout << "Total members: " << Member::getCount() << endl;
} //why virtual destructor?
/*## Simple Analogy
Think of it like this:
```
Without virtual:  C++ reads the LABEL on the box (Member*)
                  → acts based on label only

With virtual:     C++ opens the box to see what's inside (Driver)
                  → acts based on actual contents*/
#include<iostream>
using namespace std;

class Department{
    static int deptCount;
    static int nextID;

    int deptID;
    string name;

public:
    Department(string n){
        deptID = nextID++;
        name = n;
        deptCount++;
    }

    ~Department(){
        deptCount--;
    }

    void show(){
        cout<<"Department ID: "<<deptID<<" Name: "<<name<<endl;
    }
};

int Department::deptCount = 0;
int Department::nextID = 1;



class Doctor{
    static int docCount;
    static int nextID;

    int ID;
    const string name;
    Department* const dept;

public:
    Doctor(string n, Department* d)
    : ID(nextID++), name(n), dept(d)
    {
        docCount++;
    }

    ~Doctor(){
        docCount--;
    }

    void show(){
        cout<<"Doctor ID: "<<ID<<" Name: "<<name<<endl;
        dept->show();
        cout<<endl;
    }
};

int Doctor::docCount = 0;
int Doctor::nextID = 100;



int main(){

    Department* d1 = new Department("Cardiology");
    Department* d2 = new Department("Neurology");

    Doctor* doc1 = new Doctor("Ali", d1);
    Doctor* doc2 = new Doctor("Sara", d2);

    doc1->show();
    doc2->show();

    delete doc1;
    delete doc2;

    delete d1;
    delete d2;
}