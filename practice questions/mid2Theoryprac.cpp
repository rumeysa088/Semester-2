// #include<iostream>
// using namespace std;
// class Employee{
//     string name;
//     int id;
//     float salary;
// public:
//     Employee(){}
//     Employee(string n,int i,float s):name(n),id(i),salary(s){}
// };
// class Analyst:virtual public Employee{
//     string specialization;
//     bool isCertified;
//     string certifications[10];
//     int certCount;
// public:
//     Analyst(){ certCount=0;}
//     Analyst(string s,bool i):specialization(s),isCertified(i){ certCount=0;}
//     void hasCertifications(){
//         if(certCount==1){ cout<<"Certification: "<<certifications[0]<<endl;}
//         else if(certCount>1){cout<<"Certification: "<<endl; for(int i=0;i<certCount;i++){cout<<certifications[i]<<endl;}}
//         else{ cout<<"No Certifications! "<<endl;}
//     }
// };
// class Engineer:virtual public Employee{
//     bool isExpert;
//     bool isAssigned=0;
//     string* p;
//     int pcount;
// public:
//     Engineer(){ p=new string[10]; pcount=0;}
//     Engineer(bool e,string project):isExpert(e){ p=new string[10]; p[0]=project; pcount=1;}
//     void addProject(string project){  if(isAssigned){p[pcount++]=project;}else{cout<<"No projects to add!"<<endl;}}
//     void assignProject(){ if(isExpert){isAssigned=1;}else{isAssigned=0;}  }
//     void displayP( ){ cout<<"Projects: "<<endl;for(int i=0;i<pcount;i++){ cout<<p[i]<<endl;}}
//     ~Engineer(){ delete[] p;}
// };
// class LeadProfessional:public Analyst,public Engineer{
// public:
//     LeadProfessional(bool e,string project,string sp,bool i,string n,int eid,float s):Employee(n,i,s),Analyst(sp,i),Engineer(e,project){}
//     void displayProjects( ){ displayP();}
//     void displayCertifications(){  hasCertifications();}

// };
// int main(){}

// #include<iostream>
// using namespace std;
// class Pastry{
//     string name;
//     string ingredients;
//     float productionCost;
// public:
//     Pastry(){}
//     Pastry(string n,string in,float c):name(n),ingredients(in),productionCost(c){}
//     virtual float calcTotalCost(){ return productionCost * 1.10; }
//     virtual float retailPrice(){   return totalCost() * (1 + taxRate) * 1.06; }
//     virtual float calcProfit(){  return 0.7 * (retailPrice() - totalCost());  }
// };
// class SweetPastry:public Pastry{
//     float taxRate=8;

// };
// class SavoryPastry:public Pastry{
//     float taxRate=5;
// };
// float PastryCalculator(){}
// int main(){}
// #include<iostream>
// #include<string> // Included <string> for proper string usage
// using namespace std;

// class Account; // Forward declaration

// class BankManager{
// public:
//     void approveLoan(Account& a);
// };

// class Account{
// protected:
//     string name;
//     float balance;
//     int accNum;
// public:
//     Account(){}
//     Account(string n,float b,int a):name(n),balance(b),accNum(a){}
//     void deposit(float amount){if(amount>0){balance+=amount;}}
//     void display(){cout<< "\nName: " <<name<< "\tAccount Number: "<<accNum;}
//     friend void checkminBalance(Account& a);
//     friend class Auditor;
//     friend void BankManager::approveLoan(Account& a);
// };

// // Define BankManager function after Account class is fully defined
// void BankManager::approveLoan(Account& a){
//     if(a.balance>5000){cout<< "Loan Approved!" <<endl;}
//     else{cout<< "Loan Rejected!" <<endl;}
// }

// class SavingsAccount:public Account{
//     int interestRate;
// public:
//     SavingsAccount(string n,float b,int a,int i):Account(n,b,a),interestRate(i){}
//     void addInterest(){
//         balance+=((interestRate/100.0)*balance); // Used 100.0 to ensure floating-point division
//     }
// };

// void checkminBalance(Account& a) {
//     if(a.balance<1000)cout<< "Below Minimum Balance.." <<endl;
//     else{cout<< "Balance OK" <<endl;}
// }

// class Auditor{
// public:
//     void showAll(Account &a){
//         a.display();
//         cout<< "\tBalance: "<<a.balance<<endl;
//     }
// };

// int main(){
//     SavingsAccount a1("Rumaisa",7000,10001,2);
//     a1.deposit(500);
//     a1.addInterest();
//     checkminBalance(a1);
//     Auditor a;
//     a.showAll(a1);
//     BankManager b;
//     b.approveLoan(a1);
//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Employee{
// protected:
//     string name;
//     string designation;
//     string department;
//     int salary;
// public:
//     Employee(){}
//     Employee(string n,string d,string dp,int s):name(n),designation(d),department(dp),salary(s){}
//     void verify(string ){}
//     int operator ++(int){
//         Employee temp; temp.salary=salary; salary+=(salary*0.1);
//         return temp.salary;
//     }
// };
// class Course{
//     string name;
//     string code;
//     int cHours;
//     bool assigned;
// public:
//     Course(){}
//     Course(string n,string cd,int ch,bool a):name(n),code(cd),cHours(ch),assigned(a){}
//     string getCourseName(){return name;}
//     string getCourseCode(){return code;}
//     int getcHours(){return cHours;}
// };
// class Faculty:public Employee{
//     int workhrs;
//     Course CourseList[10];
//     int courseCount;
// public:
//     Faculty(){}
//     Faculty(string n,string d,string dp,int s,int w,int cc):Employee(n,d,dp,s),workhrs(w),courseCount(cc){}
//     void AssignCourse(int s,Course Courselist[]){
//         if(department=="Computer Science"){ for(int i=0;i<s;i++){if(Courselist[i].getCourseCode()[0]=='C'){CourseList[courseCount++]=Courselist[i]; break;}}}
//         else if(department=="Management Science"){ for(int i=0;i<s;i++){if(Courselist[i].getCourseCode()[0]=='M'){CourseList[courseCount++]=Courselist[i];break;}}}
//         else if(department=="Electrical Engineering"){ for(int i=0;i<s;i++){if(Courselist[i].getCourseCode()[0]=='E'){CourseList[courseCount++]=Courselist[i];break;}}}
//         int sum=0;for(int i=0;i<courseCount;i++){ sum+=CourseList[i].getcHours(); } if(sum>12)cout<<"Warning! course limit exceeded.."<<endl;
//      }
//     void Salary(){
//         if(workhrs==36){cout<<"Salary: "<<salary<<endl;}
//         if(workhrs>36){int hrs=workhrs-36; salary+=(hrs*1000); cout<<"Updated Salary: "<<salary<<endl;}
//     }
//     Faculty operator ++(int){
//         Faculty temp; temp.salary=salary;
//         salary+=(salary*0.2);
//         if(designation=="instructor"){temp.designation="Lecturer";} else if(designation=="Lecturer"){temp.designation="Assitant Professor";}
//         return temp;
//     }
// };

// class Staff:public Employee{
//     int overtimeHrs;
// public:
//     Staff(){}
//     Staff(string n,string d,string dp,int s,int o):Employee(n,d,dp,s),overtimeHrs(o){}
//     int operator+(Faculty obj){
//         Staff temp; temp.salary=obj.salary+salary;
//         return temp.salary;
//     }
//     bool Verify(string department){ if(department==(this->department))return 1; else return 0;}
//     bool Verify(int a,int b){ if(salary>=a && salary<=b)return 1; else return 0;}
// };
// int main(){

// }


// #include<iostream>
// using namespace std;
// class Mango{
//     int price;
// public:
//     Mango(int i=0):price(i){}
//     friend Mango operator++(Mango& obj);
//     friend Mango operator++(Mango& obj,int);
//     void display(){ cout<<"Price: "<<price<<endl;}
// };
// Mango operator++(Mango& obj){
//     obj.price+=100; return obj;
// }
// Mango operator++(Mango& obj,int){
//     Mango temp; temp.price=obj.price;  obj.price+=100; return temp;
// }
// int main(){
//     Mango m1(100); Mango m2;
//     cout<<"Before: "; m1.display(); m2.display();
//     m2=m1++;
//     cout<<"After Postfix: "; m1.display(); m2.display();
//     m2=++m1;
//     cout<<"After Prefix: "; m1.display(); m2.display();
// }

// #include<iostream>
// using namespace std;
// class Employee{};
// class TemporaryEmployee:public Employee{};
// class Consultant:public TemporaryEmployee{};
// class PermanentEmployee:public Employee{};
// class Manager:public Employee{};
// class ConsultantManager:public Consultant,public Manager{};
// class PermanentManager:public PermanentEmployee,public Manager{};
// class Director:public Manager{};
// int main(){}

// #include<iostream>
// using namespace std;
// class Evento{
//     Card printed[10];
// public:
//     Evento(){}
//     Evento(Card p[10]){ printed=p;}
//     void view_catalog(){ for(int i=0;i<10;i++){ printed[i].display();}}
//     void view_catalog(string bg, string f){ for(int i=0;i<10;i++){ if((printed[i].getbg==bg)&&(printed[i].getfont==f))printed[i].display();}}
//     bool operator ==(string lng){ int i;
//     cout << "Enter card to compare language" << endl;
//     cin >> i;
//     if (this->cards[i].get_language() == language)
//     return true;
//     return false; }
// };
// class Client{
//     string name;
//     string contact;
//     string address;
// public:
//     Client(){}
//     Client(string n,string c,strng a)name(n),contact(c),address(a){}
// };
// class Digital_Evento:public Evento{
// public:
//     Digital_Evento(Card p[10]):Evento(p){}
//     void view_catalog(int n){ for(int i=0;i<n;i++){ printed[i].display();}}
// };
// class Card{
//     string color;
//     string font;
//     string texture;
//     string lang;
//     bool ribbon;
// public:
//     Card(){}
//     Card(string c,string f,string t,string l,bool r):color(c),font(f),texture(t),lang(l),ribbon(r){}
//     void display(){ cout<<"\nColor: "<<color<<"\nFont: "<<font<<"\nTexture: "<<texture<<"\nLanguage: "<<lang<<"\nRibbon or not: "<<ribbon<<endl;}
//     string getbg(){ return color;}
//     string getfont(){ return font;}
//     string getlang(){ return lang;}
// };
// int main(){}

// #include<iostream>
// using namespace std;
// class Student{
//     string name;
//     int age;
// public:
//     Student(){}
//     Student(string n,int a):name(n),age(a){}
//     friend ostream& operator<<(ostream& out,Student& s){
//         out<<"Name: "<<s.name<<"Age: "<<s.age;
//         return out;
//     }
//     friend  istream& operator>>(istream& in,Student& s){
//         cout<<"Enter Name: ";
//         in>>s.name;
//         cout<<"\nEnter Age: ";
//         in>>s.age;
//         return in;
//     }
// };
// int main(){
//     Student s1;
//     cin>>s1;
//     cout<<s1;
// }

// #include<iostream>
// using namespace std;
// class Employee{
//     int workhrs;
//     const int ID;
//     string name;
// public:
//     Employee(){}
//     Employee(int w,int id,string n):workhrs(w),ID(id),name(n){}
// };
// class Xemy{
//     int code;
//     float revenue;
//     string address;
//     string phoneNo;
//     Employee arr[10];
//     int empcount;
//     string taxReport;
// public:
//     Xemy(){}
//     Xemy(int c,float r,string a,string ph,string t):code(c),revenue(r),address(a),phoneNo(ph),taxReport(t){ empcount=0;}
//     void addEmp(int w,int id,string n){ arr[empcount++]=Employee(w,id,n); }
// };
// class Brokerage:public Xemy{
// public:
//     Brokerage(int c,float r,string a,string ph,string t):Xemy(c,r,a,ph,t){}
// };
// class Marketing:public Xemy{
// public:
//    Marketing(int c,float r,string a,string ph,string t):Xemy(c,r,a,ph,t){}
// };
// class Leasing:public Xemy{
// public:
//     Leasing(int c,float r,string a,string ph,string t):Xemy(c,r,a,ph,t){}
// };

// int main(){}

// #include<iostream>
// using namespace std;

// // ---------------- BASE CLASS ----------------
// class Medicine{
// protected:
//     string name;
//     string formula;
//     float retailPrice;
//     string manufactureDate;
//     string expirationDate;

// public:
//     Medicine(){}

//     Medicine(string n,string f,float r,string m,string e)
//         :name(n),formula(f),retailPrice(r),manufactureDate(m),expirationDate(e){}

//     string getName(){ return name; }
//     string getFormula(){ return formula; }
//     string getExpiry(){ return expirationDate; }

//     virtual void display(){
//         cout<<"Name: "<<name
//             <<"\nFormula: "<<formula
//             <<"\nPrice: "<<retailPrice<<endl;
//     }

//     // 🔥 Operator Overloading (Expiry Check)
//     bool operator <= (string currentDate){
//         return expirationDate <= currentDate;
//     }
// };

// // ---------------- DERIVED CLASSES ----------------
// class Tablet:public Medicine{
//     int sucroseLevel; // 0–1
// public:
//     Tablet(){}

//     Tablet(string n,string f,float r,string m,string e,int s)
//         :Medicine(n,f,r,m,e){
//         if(s>=0 && s<=1) sucroseLevel=s;
//         else sucroseLevel=0;
//     }
// };

// class Capsule:public Medicine{
//     int absorbPercent; // 1–100
// public:
//     Capsule(){}

//     Capsule(string n,string f,float r,string m,string e,int a)
//         :Medicine(n,f,r,m,e){
//         if(a>=1 && a<=100) absorbPercent=a;
//         else absorbPercent=0;
//     }
// };

// class Syrup:public Medicine{
// public:
//     Syrup(){}

//     Syrup(string n,string f,float r,string m,string e)
//         :Medicine(n,f,r,m,e){}
// };

// // ---------------- EMPLOYEE BASE (POLYMORPHISM) ----------------
// class Employee{
// public:
//     virtual void SearchMedicine(Medicine* m[], int size, string key)=0;
// };

// // ---------------- PHARMACIST ----------------
// class Pharmacist:public Employee{
// public:
//     void SearchMedicine(Medicine* m[], int size, string key){
//         cout<<"\nSearching by Formula...\n";
//         for(int i=0;i<size;i++){
//             if(m[i]->getFormula()==key){
//                 m[i]->display();
//             }
//         }
//     }
// };

// // ---------------- COUNTER STAFF ----------------
// class CounterStaff:public Employee{
// public:
//     void SearchMedicine(Medicine* m[], int size, string key){
//         cout<<"\nSearching by Name...\n";
//         for(int i=0;i<size;i++){
//             if(m[i]->getName()==key){
//                 m[i]->display();
//             }
//         }
//     }
// };

// // ---------------- MAIN SYSTEM ----------------
// class KosarMedicos{
//     Medicine* stock[20];
//     int count;

//     Pharmacist pharm;
//     CounterStaff counter;

//     float revenue;

// public:
//     KosarMedicos(){
//         count=0;
//         revenue=0;
//     }

//     void addMedicine(Medicine* m){
//         stock[count++] = m;
//     }

//     // 🔥 Expiry + Billing
//     void sell(string currentDate){
//         cout<<"\n--- Selling Medicines ---\n";
//         for(int i=0;i<count;i++){
//             if((*stock[i]) <= currentDate){
//                 cout<<"Expired: "<<stock[i]->getName()<<endl;
//             }
//             else{
//                 cout<<"Sold: "<<stock[i]->getName()<<endl;
//                 revenue += 100; // assumed price
//             }
//         }
//         cout<<"Total Revenue: "<<revenue<<endl;
//     }

//     void searchByPharmacist(string formula){
//         pharm.SearchMedicine(stock,count,formula);
//     }

//     void searchByCounter(string name){
//         counter.SearchMedicine(stock,count,name);
//     }
// };

// // ---------------- MAIN ----------------
// int main(){
//     KosarMedicos store;

//     store.addMedicine(new Tablet("Panadol","ABC",50,"2023","2027",1));
//     store.addMedicine(new Capsule("Brufen","XYZ",40,"2022","2025",90));
//     store.addMedicine(new Syrup("Calpol","LMN",30,"2023","2026"));

//     store.searchByPharmacist("ABC");   // search by formula
//     store.searchByCounter("Brufen");   // search by name

//     store.sell("2025");

//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Gift{
//     string catID;
//     int price;
//     bool taxApplicable;
//     int stock;
// public:
//     int tax;
//     int revenue;
//     void setID(string id){ catID=id;}
//     void setPrice(int p){price=p;}
//     void setBool(bool b){taxApplicable=b;}
//     void settax(int t){tax=t;}
//     void setRev(int amount){}
//     void bill(){}
// };

// class Perfumes:public Gift{
//       string brand;
// public:
//      Perfumes(){}
//      Perfumes(string b){
//         brand=b; setID("PF1"); setBool(1); if(brand=="GUCCI")setPrice(1200); elseif(brand=="Versace")setPrice(1100); esleif(brand=="Chanel")setPrice(950);  
//         settax(7); 
//     }

// };
// class ChocolateCake:public Gift{
//     int weight;
//     string msgoncake;
// public:
//     ChocolateCake(){}
//     ChocolateCake(int w,string msg):weight(w),msgoncake(msg){setID("CK1"); setBool(1); setPrice(700); settax(4);}
// };
// class Flowers:public Gift{
//     string floralType;
// public:
//     Flowers(){}
//     Flowers(int s,int r,string fl):floralType(fl),Gift("FL1",50,0,s,0,r){}
// };
// class HappyBundle:public Flowers,public Perfumes,public ChocolateCake{
    
// };
// class NineTails{
//     string contact;
//     string address;
//     string email;
// };
// class TaxationDept:{};
// int main(){}

// #include<iostream>
// using namespace std;
// class Employee{
// protected:
//     string name;
//     int ID;
//     float baseSalary;
//     float salary;
// public: 
//     Employee(){}
//     Employee(string n,int id,float b):name(n),ID(id),baseSalary(b){}
//     virtual float calculateSalary(){ return baseSalary;}
//     int operator+(Employee& e){ return salary+=e.salary;}
//     float operator++(int){ Employee temp; temp=*this; salary=salary+(salary*0.1); return temp.salary;}
//     friend float calculateBonus(Employee& e);
//     friend class Audit;
//     friend void promote(Employee& e);
// };
// float calculateBonus(Employee& e){ float bonus; bonus=e.salary*0.2; return bonus;}
// class Audit{
// public:
//     void generateReport(Employee* arr[], int size){
//          for(int i=0;i<size;i++){ cout<<"Name: "<<arr[i]->name<<"Salary: "<<arr[i]->salary<<endl;}
//         }
// };
// class HR{
// public:
//     void promote(Employee& e);
// };
// void promote(Employee& e){ e.salary=e.salary+(e.salary*0.15);}
// class Engineer: virtual public Employee{
// protected:
//     int projectCount;
//     bool isExpert;
    
// public:
//     Engineer(){}
//     Engineer(int p,bool i):projectCount(p),isExpert(i){}
//     float calculateSalary(){ salary = baseSalary + (projectCount * 1500); if(isExpert){salary+=5000; return salary;}}
// };
// class Analyst:virtual public Employee{
// protected:
//     int certificationCount;
    
// public:
//     Analyst(){}
//     Analyst(int c):certificationCount(c){ salary=0;}
//     float calculateSalary(){ salary = baseSalary + (certificationCount * 2000);  return salary;}
// };
// class Lead:public Analyst,public Engineer{
// public:
//     Lead(){}
//     Lead(string n,int id,float b,int c,int p,bool i):Employee(n,id,b),Analyst(c),Engineer(p,i){}
//     void display(){
//         cout<<"Name: "<<name<<endl;
//         int combine;
//         combine=Analyst::calculateSalary()+Engineer::calculateSalary();
//         cout<<"Combined Salary= "<<combine<<endl;
//     }
//     float calculateSalary(){return salary;}
// };
// int main(){
//     Employee* arr[3];
//     arr[0]=new Analyst(2); arr[1]=new Engineer(3,1); arr[2]=new Lead("Ali",1001,20000,2,2,1);
//     for(int i=0;i<3;i++){ cout<<"\tSalary: "<<arr[i]->calculateSalary();}
// }

// #include<iostream>
// using namespace std;

// class HR; // forward declaration

// class Employee{
// protected:
//     string name;
//     int ID;
//     float baseSalary;
//     float salary;

// public:
//     Employee(){}
//     Employee(string n,int id,float b):name(n),ID(id),baseSalary(b),salary(0){}

//     virtual float calculateSalary(){
//         salary = baseSalary;
//         return salary;
//     }

//     // + operator (no modification)
//     int operator+(Employee& e){
//         return salary + e.salary;
//     }

//     // postfix ++
//     float operator++(int){
//         float old = salary;
//         salary += salary * 0.1;
//         return old;
//     }

//     friend float calculateBonus(Employee& e);
//     friend class Audit;
//     friend void HR::promote(Employee& e);
// };

// // -------- Friend Function --------
// float calculateBonus(Employee& e){
//     return e.salary * 0.2;
// }

// // -------- Friend Class --------
// class Audit{
// public:
//     void generateReport(Employee* arr[], int size){
//         for(int i=0;i<size;i++){
//             cout<<"Name: "<<arr[i]->name
//                 <<" Salary: "<<arr[i]->salary<<endl;
//         }
//     }
// };

// // -------- HR Class (Friend Member Function) --------
// class HR{
// public:
//     void promote(Employee& e);
// };

// void HR::promote(Employee& e){
//     e.salary += e.salary * 0.15;
// }

// // -------- Engineer --------
// class Engineer : virtual public Employee{
// protected:
//     int projectCount;
//     bool isExpert;

// public:
//     Engineer(){}
//     Engineer(string n,int id,float b,int p,bool i)
//         : Employee(n,id,b), projectCount(p), isExpert(i) {}

//     float calculateSalary(){
//         salary = baseSalary + (projectCount * 1500);
//         if(isExpert) salary += 5000;
//         return salary;
//     }
// };

// // -------- Analyst --------
// class Analyst : virtual public Employee{
// protected:
//     int certificationCount;

// public:
//     Analyst(){}
//     Analyst(string n,int id,float b,int c)
//         : Employee(n,id,b), certificationCount(c) {}

//     float calculateSalary(){
//         salary = baseSalary + (certificationCount * 2000);
//         return salary;
//     }
// };

// // -------- Lead (Diamond Resolution) --------
// class Lead : public Analyst, public Engineer{
// public:
//     Lead(string n,int id,float b,int c,int p,bool i)
//     : Employee(n,id,b), Analyst(n,id,b,c), Engineer(n,id,b,p,i) {}

//     float calculateSalary(){
//         salary = Analyst::calculateSalary() + Engineer::calculateSalary();
//         return salary;
//     }

//     void display(){
//         cout<<"Name: "<<name<<endl;
//         cout<<"Combined Salary: "<<salary<<endl;
//     }
// };

// // -------- MAIN --------
// int main(){
//     Employee* arr[3];

//     arr[0] = new Analyst("Ali",101,20000,2);
//     arr[1] = new Engineer("Sara",102,25000,3,true);
//     arr[2] = new Lead("Ahmed",103,30000,2,2,true);

//     for(int i=0;i<3;i++){
//         cout<<"Salary: "<<arr[i]->calculateSalary()<<endl;
//     }

//     // operator +
//     cout<<"Total Salary (0 + 1): "<<(*arr[0] + *arr[1])<<endl;

//     // postfix ++
//     (*arr[0])++;
//     cout<<"After increment: "<<arr[0]->calculateSalary()<<endl;

//     // friend function
//     cout<<"Bonus: "<<calculateBonus(*arr[1])<<endl;

//     // friend class
//     Audit a;
//     a.generateReport(arr,3);

//     // friend member function
//     HR h;
//     h.promote(*arr[2]);
//     cout<<"After promotion: "<<arr[2]->calculateSalary()<<endl;
// }

// #include<iostream>
// using namespace std;
// class Number {
//     int x;
// public:
//     Number(int a):x(a){}

//     friend Number operator+(Number a, Number b){
//         return Number(a.x + b.x);
//     }

//     void show(){ cout << x; }
// };

// int main(){
//     Number n1(5), n2(10);
//     Number n3 = n1 + n2;
//     n3.show();
// }

#include<iostream>
using namespace std;
class Gadget{
    string name;
    string brand;
    float cost;
    int taxrate;
public:
    Gadget(){}
    Gadget(string n,string b,float c,int t):name(n)brand(b),cost(c),taxrate(t){}
    virtual float totalCost(){ return cost=cost+(cost*0.15);}
    virtual float sellingprice(){ return cost=cost+(cost*taxrate)+(cost*0.05);}
    virtual float profit(){  return (sellingprice()-cost)*0.65;}
    friend double GadgetCalculator(Gadget& g);
    friend class StoreReport;
};
double GadgetCalculator(Gadget& g){ /*idk wtf the logic for this is*/}
class StoreReport{
    void display(){}
};
class Electronic:public Gadget{
public:
    Electronic(string n,string b,float c):Gadget(n,b,c,12){}
};
class Accessory:public Gadget{
public:
    Accessory(string n,string b,float c):Gadget(n,b,c,6){}
};
int main(){}