#include<iostream>
using namespace std;
class ElectricityBill{
    int ID;
    string name;
    float units;
    float ratePunit;
public:
    ElectricityBill(){}
    ElectricityBill(int i,string n,float u,float r):ID(i),name(n){ 
        try{
             if(units<0)throw "UNits cant be neg! "; else units=u;
        }
        catch(const char* e){cout<<e;}
        try{
            if(ratePunit<0)throw "rate cant be neg! "; else ratePunit=r;
        }
        catch(const char* s){cout<<s;}
    }
    ~ElectricityBill(){}
    void inputDetails(int i,string n,float u){ ID=i; name=n;units=u;}
    float calcBill(float u,float r){ return u*r;}
    void displayBill(){ cout<<"Name: "<<name<<"\n UNit: "<<units<<"\n Total: "<<calcBill(units,ratePunit)<<endl;}
};
int main(){}

#include <iostream>
#include <string>
using namespace std;
class Subject {
public:
    string sName;
    void setSubject(string n) { sName = n; }
};
class Teacher {
protected:
    string name;
public:
    void setData(string n) { this->name = n; } // this pointer
};
class SeniorTeacher : public Teacher {
    Subject sub; // Has-a relationship
public:
    static int count; // Static member
    SeniorTeacher() { }
    void setup(string n, string s) {
        if(s == "") return; // Constraint
        setData(n);
        sub.setSubject(s);
        count++;
    }
    void assignClass(string section) {
        cout << name << " assigned to " << section << endl;
    }
    void assignClass(string section, int room) {
        cout << name << " assigned to " << section << " Room " << room << endl;
    }
};
int SeniorTeacher::count = 0;

int main() {
    SeniorTeacher list[10]; // Array of objects (Max 10)
    list[0].setup("Smith", "Math");
    list[0].assignClass("A");
    list[1].setup("Adams", "Science");
    list[1].assignClass("B", 101);
    list[2].setup("White", "History");
    list[2].assignClass("C");
    cout << "\nTeacher Assigned Successfully" << endl;
    cout << "Total Senior Teachers: " << SeniorTeacher::count << endl;
    return 0;
}


#include<iostream>
#include<fstream>
using namespace std;
class Vehicle{
public:
    int num;
    string owner;
    float serviceCost;
public:
    Vehicle(){}
    Vehicle(int n,string o,float s):num(n),owner(o){ 
        try{
                if(s<0) throw "INvalid Service Cost!";
           } 
           catch(const char* s){cout<<s<<endl;}         
}
    virtual void calculateService() = 0;
    float operator +(Vehicle b){
        return serviceCost+b.serviceCost;
    }
    friend void displayDetails(Vehicle v);
};
void displayDetails(Vehicle v){
    cout<<"Vehicle No. : "<<v.num<<"\nOwner: "<<v.owner<<endl;
}
class Bike:public Vehicle{
public:
    Bike(){}
};
class Car:public Vehicle{
public:
    Car(){}
};
class Truck:public Vehicle{
public:
    BTruck(){}
};
int main(){
    Vehicle* ptr=new Bike;
    ofstream file("ServiceRecords.txt");
    file.open();
    try{
        if(!file.is_open) throw "Could not open file!";
    }
    catch(const char* e){cout<<e<<endl;}
    Vehicle v(001,"rumaisa",10000);
    file<<v.serviceCost;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vehicle {
public:
    int num;
    string owner;
    float serviceCost;

    Vehicle(int n, string o, float s) : num(n), owner(o), serviceCost(s) {
        if (s < 0) throw runtime_error("Invalid Service Cost!");
    }

    virtual void calculateService() = 0; // Pure virtual

    // Use reference here because Vehicle is abstract
    float operator+(const Vehicle& b) {
        return this->serviceCost + b.serviceCost;
    }

    friend void displayDetails(const Vehicle& v);
    virtual ~Vehicle() {} // Good practice for polymorphism
};

void displayDetails(const Vehicle& v) {
    cout << "Vehicle No. : " << v.num << "\nOwner: " << v.owner << "\nCost: " << v.serviceCost << endl;
}

class Car : public Vehicle {
public:
    Car(int n, string o, float s) : Vehicle(n, o, s) {}
    void calculateService() override {
        cout << "Service Completed Successfully" << endl;
        cout << "Service Cost: " << serviceCost << endl;
    }
};
class Bike : public Vehicle {
public:
    Bike(int n, string o, float s) : Vehicle(n, o, s) {}
    
    void calculateService() override {
        // Specific logic for Bike
        cout << "Bike Service Completed Successfully" << endl;
        cout << "Service Cost: " << serviceCost << endl;
    }
};

class Truck : public Vehicle {
public:
    Truck(int n, string o, float s) : Vehicle(n, o, s) {}
    
    void calculateService() override {
        // Specific logic for Truck
        cout << "Truck Service Completed Successfully" << endl;
        cout << "Service Cost: " << serviceCost << endl;
    }
};

int main() {
    try {
        // Runtime Polymorphism
        Vehicle* ptr = new Car(101, "Rumaisa", 6500);
        ptr->calculateService();

        ofstream file("ServiceRecords.txt");
        if (!file.is_open()) throw runtime_error("File opening error!");

        file << "Owner: " << ptr->owner << " Cost: " << ptr->serviceCost << endl;
        file.close();
        
        cout << "Record Saved Successfully" << endl;

        delete ptr; 
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

#include<iostream>
using namespace std;
class Vehicle {
    string model;
public:
    Vehicle(string m = "") {
        if (m == "") cout << "Model can't be empty!\n";
        model = m;
    }
    string getModel() {
        return model;
    }
};
class Driver {
protected:
    string name;
    int id;
public:
    Driver(string n = "", int i = 0) : name(n), id(i) {}
};
class SeniorDriver : public Driver {
    Vehicle vc;
    static int total;
public:
    SeniorDriver(string n, int i, Vehicle v)
        : Driver(n, i), vc(v) {
        total++;
    }
    void assignRoute(string route) {
        cout << "Route: " << route << endl;
    }
    void assignRoute(string route, string shiftTime) {
        cout << "Route: " << route
             << " ShiftTime: " << shiftTime << endl;
    }
    static int getTotal() {
        return total;
    }
};
int SeniorDriver::total = 0;
int main() {
    SeniorDriver arr[10] = {
        SeniorDriver("Ali", 1, Vehicle("Bus")),
        SeniorDriver("Sara", 2, Vehicle("Truck"))
    };
    arr[0].assignRoute("City Center");
    arr[1].assignRoute("Airport", "Night");
    cout << "Total Senior Drivers: "
         << SeniorDriver::getTotal() << endl;
    return 0;
}


#include<iostream>
#include<fstream>
using namespace std;
class Device {
protected:
    int id;
    string name;
    float cost;
public:
    Device() {}
    Device(int i, string n, float c) {
        if (c < 0) throw "Maintenance cost can't be negative!";
        id = i;
        name = n;
        cost = c;
    }
    virtual void computeMaintenance() = 0;
    virtual ~Device() {}
    float operator+(Device &d) {
        return cost + d.cost;
    }
    friend void display(Device *d);
    string getName() { return name; }
    float getCost() { return cost; }
};
void display(Device *d) {
    cout << "Client: " << d->name
         << "  ID: " << d->id
         << "  Cost: " << d->cost << endl;
}
class Laptop : public Device {
public:
    Laptop(int i, string n, float c) : Device(i, n, c) {}

    void computeMaintenance() override {
        cout << "Laptop Maintenance Cost: 30$" << endl;
    }
};
class Smartphone : public Device {
public:
    Smartphone(int i, string n, float c) : Device(i, n, c) {}
    void computeMaintenance() override {
        cout << "Smartphone Maintenance Cost: 40$" << endl;
    }
};
class Printer : public Device {
public:
    Printer(int i, string n, float c) : Device(i, n, c) {}

    void computeMaintenance() override {
        cout << "Printer Maintenance Cost: 60$" << endl;
    }
};
int main() {

    Device* arr[3];

    try {
        arr[0] = new Laptop(101, "Rumaisa", 100);
        arr[1] = new Smartphone(102, "Ali", 200);
        arr[2] = new Printer(103, "Sara", 150);
        for (int i = 0; i < 3; i++) {
            arr[i]->computeMaintenance();
        }
        cout << "\nTotal Cost (0 + 1): "
             << (*arr[0] + *arr[1]) << endl;
        ofstream out("Records.txt");

        if (!out) throw "File could not be opened!";

        for (int i = 0; i < 3; i++) {
            out << "Client: " << arr[i]->getName()
                << " Cost: " << arr[i]->getCost() << endl;
        }
        out.close();
        cout << "\nRecord Saved Successfully" << endl;
    }
    catch (const char* e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}

#include<iostream>
#include<fstream>
using namespace std;
class Account{
public:
    int accnum;
    string name;
    float balance;
public:
    Account(int num,string n,float b){ accnum=num; name=n; balance=b;}
    virtual void calculateInterest() = 0;
    void operator -(float am){
        if(am<=balance)
        balance-=am;
        else{ throw "Invalid withdrawal! ";}
    }
    friend ofstream& operator<<(ofstream& out,account* a);
};
ofstream& operator<<(ofstream& out,account* a){
    out<<"Name: "<<a->name;
    return out;
}
class SavingsAccount:public Account{
public:
    SavingsAccount(int num,string n,float b):Account(num,n,b){}
    virtual void calculateInterest(){cout<<"Interest: 2% ";}
};
class CurrentAccount:public Account{
public:
    CurrentAccount(int num,string n,float b):Account(num,n,b){}
    virtual void calculateInterest(){cout<<"Interest: 2.5% ";}
};
class FixedDepositAccount:public Account{
public:
    FixedDepositAccount(int num,string n,float b):Account(num,n,b){}
    virtual void calculateInterest(){cout<<"Interest: 3% ";}
};

int main(){
    Account* arr[3];
    try{
        arr[0] = new SavingsAccount(101, "Rumaisa", 1000.0);
        arr[1] = new CurrentAccount(102, "Ali", 2000.0);
        arr[2] = new FixedDepositAccount(103, "Sara", 15000.0);
        for (int i = 0; i < 3; i++) {
            arr[i]->calculateInterest();
        }
    ofstream out("account.txt");
    if(!out)throw" cdnt open file" ;
    for(i=0;i<3;i++){
        out<<"ACC NUM: "<<arr[i]->accnum<<"Name: "<<arr[i]->name<<"Balance: "<<arr[i]->balance<<endl;
    }
    out.close();
}catch (const char* e) {
        cout << "Error: " << e << endl;
    }
    out.open("account.txt",ios::binary);
    out.write((char*)arr[0],sizeof(*arr[0]));
    out.close();
}

#include<iostream>
#include<fstream>
using namespace std;
class Publication{
protected;
   int publicationId;
   string title ;
   string author ;
   float baseScore;
public:
    Publication(int id,string t,string a,float b){publicationId=id; title=t; author=a; baseScore=b;}
    virtual void evaluateImpact() = 0;
    virtual void display() = 0;
    float operator*(Publication& p){
        return baseScore*p.baseScore;
    }
    bool operator==(Publication& p){
        return baseScore==p.baseScore;
    }
    friend class PublicationManager;
    friend void analyzePublication(Publication*);
};
void analyzePublication(Publication*){
    cout<<"Hidden edtails";
    //cout stuff and compute
}
class JournalPaper:public Publication{
public:
    JournalPaper(int id,string t,string a,float b):Publication(id,t,a,b){}
    virtual void evaluateImpact(){cout<<"Score: "<<baseScore;}
    virtual void display(){cout<<"Journal Info: "; /*cout stuff*/}
};
class ConferencePaper:public Publication{
public:
    ConferencePaper(int id,string t,string a,float b):Publication(id,t,a,b){}
    virtual void evaluateImpact(){cout<<"Score: "<<baseScore;}
    virtual void display(){cout<<"Conference Info: "; /*cout stuff*/}
};
class ThesisReport:public Publication{
public:
    ThesisReport(int id,string t,string a,float b):Publication(id,t,a,b){}
    virtual void evaluateImpact(){cout<<"Score: "<<baseScore;}
    virtual void display(){cout<<"Thesis Info: "; /*cout stuff*/}
};
class PublicationManager{
public:
    void approvePublication(Publication* p){
        if(p->baseScore>=8)cout<<"Approved! ";
        else cout<<"Not Approved! ";
    }
};
template<class T,int size>
class Repository{
    T array[size];
    int count;
public:
    void addPub(T& a){
        if(count<size){
            array[count++]=a;
        }
    }
    void removePub(T& a){bool found=0;
        for(int i=0;i<count;i++){
            if(array[i]==a){found=1;index=i;}
        }if(found){
        for(int i=index;i<count;i++){
            array[i]=array[i+1];
        }
    }
    }
    //not adding display
};
int main(){
    Publication* arr[3];
    arr[0]=new JournalPaper(101,"xyz","ddd",9);
     arr[1]=new Conference(102,"xyz","ddd",8);
      arr[2]=new ThesisReport(103,"xyz","ddd",4);
    ofstream out("records.txt");
    for(int i=0;i<3;i++){
        out<<"stuff";
    }
    out.close();
    string t,a;int i;
    ifstream in("records.txt");
    while(in>>t>>a>>i){
        cout<<t<<a<<i;
    }
}
#include<iostream>
#include<fstream>
using namespace std;

// ================= EXCEPTION CLASS =================
class InvalidData : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Data Error!";
    }
};

// ================= ABSTRACT BASE CLASS =================
class Publication {
protected:
    int publicationId;
    string title;
    string author;
    float baseScore;

public:
    Publication(int id, string t, string a, float b) {
        if (t == "") throw "Empty Title!";
        if (b < 0 || b > 100) throw "Invalid Score!";

        publicationId = id;
        title = t;
        author = a;
        baseScore = b;
    }

    virtual void evaluateImpact() = 0;
    virtual void display() = 0;

    // -------- OPERATOR OVERLOADING --------
    float operator*(Publication& p) {
        return (this->baseScore * 0.5) + (p.baseScore * 0.5);
    }

    bool operator==(Publication& p) {
        return this->baseScore == p.baseScore;
    }

    friend class PublicationManager;
    friend void analyzePublication(Publication*);
};

// ================= FRIEND FUNCTION =================
void analyzePublication(Publication* p) {
    cout << "\n--- Hidden Details ---\n";
    cout << "ID: " << p->publicationId << endl;
    cout << "Title: " << p->title << endl;
    cout << "Author: " << p->author << endl;

    float adjustedScore = p->baseScore + (p->baseScore * 0.2);
    cout << "Adjusted Score: " << adjustedScore << endl;
}

// ================= DERIVED CLASSES =================
class JournalPaper : public Publication {
public:
    JournalPaper(int id, string t, string a, float b)
        : Publication(id, t, a, b) {}

    void evaluateImpact() override {
        cout << "Journal Impact Evaluated\n";
    }

    void display() override {
        cout << "Journal: " << title << endl;
    }
};

class ConferencePaper : public Publication {
public:
    ConferencePaper(int id, string t, string a, float b)
        : Publication(id, t, a, b) {}

    void evaluateImpact() override {
        cout << "Conference Impact Evaluated\n";
    }

    void display() override {
        cout << "Conference: " << title << endl;
    }
};

class ThesisReport : public Publication {
public:
    ThesisReport(int id, string t, string a, float b)
        : Publication(id, t, a, b) {}

    void evaluateImpact() override {
        cout << "Thesis Impact Evaluated\n";
    }

    void display() override {
        cout << "Thesis: " << title << endl;
    }
};

// ================= FRIEND CLASS =================
class PublicationManager {
public:
    void approve(Publication* p) {
        if (p->baseScore >= 60)
            cout << "Publication Approved\n";
        else
            cout << "Rejected\n";
    }
};

// ================= TEMPLATE CLASS =================
template <class T, int SIZE>
class Repository {
    T arr[SIZE];
    int count;

public:
    Repository() { count = 0; }

    void add(T x) {
        if (count >= SIZE) throw "Repository Overflow!";
        arr[count++] = x;
    }

    void remove(int index) {
        if (index < 0 || index >= count) throw "Invalid Index!";
        for (int i = index; i < count - 1; i++)
            arr[i] = arr[i + 1];
        count--;
    }

    void display() {
        for (int i = 0; i < count; i++)
            arr[i]->display();
    }
};

// ================= MAIN =================
int main() {

    try {
        Publication* arr[10];

        arr[0] = new JournalPaper(1, "AI", "Ali", 80);
        arr[1] = new ConferencePaper(2, "ML", "Sara", 70);
        arr[2] = new ThesisReport(3, "DL", "Ahmed", 90);

        // -------- POLYMORPHISM --------
        for (int i = 0; i < 3; i++) {
            arr[i]->evaluateImpact();
            arr[i]->display();
        }

        // -------- FRIEND FUNCTION --------
        analyzePublication(arr[0]);

        // -------- OPERATOR OVERLOADING --------
        cout << "\nCombined Impact: " << (*arr[0] * *arr[1]) << endl;

        // -------- FRIEND CLASS --------
        PublicationManager pm;
        pm.approve(arr[0]);

        // -------- FILE WRITING --------
        ofstream out("publications.txt");
        if (!out) throw "File Open Error!";

        for (int i = 0; i < 3; i++) {
            out << arr[i]->publicationId << " "
                << arr[i]->title << " "
                << arr[i]->author << " "
                << arr[i]->baseScore << endl;
        }
        out.close();

        cout << "Data Written to File\n";

        // -------- FILE READING --------
        ifstream in("publications.txt");
        if (!in) throw "File Read Error!";

        int id;
        string t, a;
        float s;

        cout << "\n--- File Data ---\n";
        while (in >> id >> t >> a >> s) {
            cout << id << " " << t << " " << a << " " << s << endl;
        }

        cout << "File Loaded Successfully\n";
        in.close();
    }

    catch (const char* e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}

#include<iostream>
using namespace std;
class Room{
    int num;
    int capacity;
public:
    Room(){}
    Room(int n,int c):num(n),capacity(c){}
    void display(){}
};
class Student{
    studentId;
    string name ;
    const int rollNumber;
public:
    Student(){}
    Student(int i,string n,int r):studentId(i),name(n),rollNumber(r){}
    void display(){}
};
class Hostel{
    string hostelNam;
    Room* rooms; 
    Student* students ;
    int roomCount; int crc=0;
    int studentCount; int csc;
    static int totalStuds;
public:
    Hostel(){}
    Hostel(string n,int r,int c):hostelNam(n),roomCount(r),studentCount(c){
        rooms=new Room[r];
        students=new Student[c];
    }
    void assignRoom(Room* room){if(crc<roomCount){ rooms[crc++]=room;}}
    void addStudent(Student* s){if(csc<studentCount){ students[csc++]=s; totalStuds++;}}
    void displayHostel(){
        for(int i=0;i<crc;i++){
            rooms[i]->display();
        }
    }
    for(int i=0;i<csc;i++){
            students[i]->display();
        }
    
};
int Hostel::totalStuds=0;
int main(){

}
#include<iostream>
#include<fstream>
using namespace std;

class AssetManager; // forward declaration

class Asset {
protected:
    int assetid;
    string name;
    float value;

public:
    Asset(int i,string n,float v) {
        if(n=="") throw "Empty name!";
        if(v<0) throw "Invalid value!";
        assetid=i; name=n; value=v;
    }

    virtual void evaluate() = 0;
    virtual void display() = 0;

    // ✔ operator &
    float operator&(Asset& a) {
        return (value * 0.5) + (a.value * 0.5);
    }

    // ✔ operator []
    float operator[](int index) {
        if(index==0) return value;
        else if(index==1) return value + value*0.10;
        else if(index==2) return value - value*0.05;
        else throw "Invalid index!";
    }

    friend class AssetManager;

    // ✔ friend member function
    friend void AssetManager::secretAccess(Asset*);
};

// ================= DERIVED CLASSES =================

class VehicleAsset:public Asset{
public:
    VehicleAsset(int i,string n,float v):Asset(i,n,v){}
    void evaluate(){ cout<<"Vehicle Asset Evaluated\n"; }
    void display(){
        cout<<"[Vehicle] "<<assetid<<" "<<name<<" "<<value<<endl;
    }
};

class ElectronicAsset:public Asset{
public:
    ElectronicAsset(int i,string n,float v):Asset(i,n,v){}
    void evaluate(){ cout<<"Electronic Asset Evaluated\n"; }
    void display(){
        cout<<"[Electronic] "<<assetid<<" "<<name<<" "<<value<<endl;
    }
};

class RealEstateAsset:public Asset{
public:
    RealEstateAsset(int i,string n,float v):Asset(i,n,v){}
    void evaluate(){ cout<<"RealEstate Asset Evaluated\n"; }
    void display(){
        cout<<"[RealEstate] "<<assetid<<" "<<name<<" "<<value<<endl;
    }
};

// ================= FRIEND CLASS =================

class AssetManager{
public:
    void approve(Asset* a) {
        if(a->value > 50000) cout<<"Approved\n";
        else cout<<"Rejected\n";
    }

    // ✔ friend member function
    void secretAccess(Asset* a){
        cout<<"[SECRET DATA] "<<a->name<<" value="<<a->value<<endl;
    }
};

// ================= MAIN =================

int main(){
    try{
        Asset* arr[3];

        arr[0] = new VehicleAsset(1,"Car",80000);
        arr[1] = new ElectronicAsset(2,"Laptop",70000);
        arr[2] = new RealEstateAsset(3,"House",90000);

        // ✔ runtime polymorphism
        for(int i=0;i<3;i++){
            arr[i]->evaluate();
            arr[i]->display();
        }

        // ✔ operator &
        cout<<"\nCombined value: "<<(*arr[0] & *arr[1])<<endl;

        // ✔ operator []
        cout<<"With Tax: "<<(*arr[0])[1]<<endl;
        cout<<"After Depreciation: "<<(*arr[0])[2]<<endl;

        // ✔ friend class + member function
        AssetManager m;
        m.approve(arr[0]);
        m.secretAccess(arr[0]);

        // ✔ FILE HANDLING
        ofstream out("assets.txt");
        if(!out) throw "File error!";

        for(int i=0;i<3;i++){
            out<<i<<" "<<(*arr[i])[0]<<" "<<(*arr[i])[1]<<endl;
        }
        out.close();

        cout<<"\nFile Written\n";

        // ✔ FILE READ
        ifstream in("assets.txt");
        if(!in) throw "File read error!";

        int id;
        float base, taxed;

        cout<<"\n--- File Data ---\n";
        while(in>>id>>base>>taxed){
            cout<<id<<" "<<base<<" "<<taxed<<endl;
        }

        in.close();
    }
    catch(const char* e){
        cout<<"Error: "<<e<<endl;
    }

    return 0;
}