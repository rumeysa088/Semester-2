// #include<iostream>
// using namespace std;
// class BAMS{
//     const string bankName;
//     const int accountNo;
//     static int active;
//     float balance;
//     static int nextID;
// public:
//     BAMS():accountNo(nextID++),bankName("UBL"),balance(0.0){ active++;}
//     int getActive(){ return active;}
//      void deposit(int amount){ if (amount>0){balance+=amount;cout<<"Deposit Successful!"<<endl;}}
//   void withdraw(int amount){if(amount<=balance){balance-=amount;cout<<"Withdrawal Successfull"<<endl;}else cout<<"Withdraw Failed!"<<endl;}
// };
// int BAMS:: active=0;
// int BAMS:: nextID=100;
// int main(){

// }
     //PRACTICE QUESTION 
     /*Develop a university exam management system. The system manages exam halls, each containing multiple exam slots, and each slot containing multiple registered students.
Classes:
Student — holds studentID (int) and studentName (string).
ExamSlot — holds slotID (int), an array of up to 4 students, and a student count. Member functions: addStudent(Student), displaySlotInfo().
ExamHall — holds hallNumber (int), an array of up to 3 exam slots, and a slot count. Member functions: addSlot(ExamSlot), calculateTotalStudents(), displayHallInfo() — which displays all slots and the total student count in that hall.
In main(), set up one exam hall with at least 2 slots and varying students, then display the full hall info.*/
// #include<iostream>
// using namespace std;
// class Student{
//     string name;
//     int ID;
// public:
//     Student(){}
//     Student(string n,int id):name(n),ID(id){}
// };
// class Examslot{
//     int slotID;
//     Student arr[4];
//     int studcount;
// public:
//     ExamSlot(int id):slotID(id){studcount=0;}
//     void addStudent(Student s){
//         if(studcount<4){ arr[studcount++]= s;}
//     }
//     int getStud(){return studcount;}
//     //void displaySlot(){}
// };
// class ExamHall{
//     int hallNumber;
//     Examslot arr[3];
//     int slotcount;
// public:
//     ExamHall(int n):hallNumber(n){slotcount=0;}
//     void addSlot(ExamSlot e){
//         if(slotcount<3){arr[slotcount++]=e;}
//     }
//     int get totStud(){ int tot=0;
//         for(int i=0;i<slotcount;i++){
//             tot+=arr[i].getStud();
//         }return tot;
//     }
// };
// int main(){
    
// }
/*Question 1 — Classes, Static & Const Members
A hospital has patients. Each patient has an ID, name, age, and diagnosis. Track total 
patients and total patients who are critical (age > 60). Display each patient's info and the overall stats. 
Add a const function that returns whether the patient is critical, and a static function for the totals.

Question 2 — Object Composition
Design a school timetable system. A Subject has a name and teacher. A ClassRoom holds up to 5 subjects and
 can calculate total teaching hours per day (each subject = 1 hour). A School holds up to 6 classrooms and 
 can display the classroom with the most subjects assigned.

Question 3 — Inheritance & Polymorphism
A base class Vehicle has name, fuel type, and daily km driven. A FleetManager (derived) manages up to 4 vehicles 
and calculates total fuel cost (assume 12 km/litre, fuel = $1.2/litre). A Penalty class applies a surcharge for
 vehicles exceeding 100 km/day. Use multiple inheritance and display cost before/after surcharge.*/

 /*Question 1 — Classes, Static & Const Members
Design a stock trading system. Each Stock has a constant stock symbol, company name, number of shares purchased, 
and buy price per share. Track across all stocks: total stocks registered, total money invested, and total current 
portfolio value (shares × current price, passed at display time).
Add a const function that returns profit/loss for a stock given a current price. Add a static function that
 displays overall stats. In main(), create an array of 4 stocks, ask the user to input current prices for each,
display individual profit/loss, then show total invested vs total current value and whether the overall portfolio
 is in profit or loss.

Question 2 — Object Composition
Build a hospital management system. A Medicine has a name and price per unit. A Prescription holds up to 4 medicines with 
their quantities and can calculate its subtotal. A Patient holds a constant patient ID, name, and up to 3 prescriptions. 
A Hospital manages up to 6 patients and can: calculate each patient's total bill, find the patient with the highest bill,
 and display a full structured report of all patients, their prescriptions, medicines, quantities, and grand total bill 
 across the entire hospital.

Question 3 — Multiple Inheritance & Polymorphism
A base class Employee holds name, base salary, and department. A PerformanceBonus class holds a bonus percentage and applies
it to a salary. A TaxPolicy class holds a tax rate and deducts it. A derived class CompanyPayroll inherits from all three 
and manages up to 5 employees. For each employee it must: apply bonus first, then deduct tax from the bonused salary, and
track who gets the highest and lowest final take-home pay. Implement generatePayslip() that displays each employee's base 
salary, bonus added, tax deducted, and final pay, then shows company-wide total payout after all deductions.*/

//  #include<iostream>
// using namespace std;

// class Stock {
//     const string symbol;
//     string name;
//     int noOfShares;
//     float buyPrice;
//     static int totalStocks;
//     static float totalMoneyInvested;

// public:
//     Stock(string sym, string n, int ns, float bp)
//         : symbol(sym), name(n), noOfShares(ns), buyPrice(bp) {
//         totalStocks++;
//         totalMoneyInvested += ns * bp;
//     }

//     float profitLoss(float cp) const {
//         return (cp - buyPrice) * noOfShares;
//     }

//     float currentValue(float cp) const {
//         return cp * noOfShares;
//     }

//     void display(float cp) const {
//         cout << "Symbol: " << symbol << ", Name: " << name;
//         cout << ", Shares: " << noOfShares << ", Buy Price: $" << buyPrice;
//         cout << ", Profit/Loss: $" << profitLoss(cp) << endl;
//     }

//     static void displayStats(float totalPortValue) {
//         cout << "\nTotal Stocks Registered: " << totalStocks << endl;
//         cout << "Total Money Invested: $" << totalMoneyInvested << endl;
//         cout << "Total Current Portfolio Value: $" << totalPortValue << endl;
//         if (totalPortValue > totalMoneyInvested)
//             cout << "Overall Portfolio: IN PROFIT" << endl;
//         else
//             cout << "Overall Portfolio: IN LOSS" << endl;
//     }
// };

// int Stock::totalStocks = 0;
// float Stock::totalMoneyInvested = 0;

// int main() {
//     Stock arr[4] = {
//         Stock("AAPL", "Apple", 21, 120),
//         Stock("GOOGL", "Google", 12, 300),
//         Stock("AMZN", "Amazon", 26, 150),
//         Stock("TSLA", "Tesla", 10, 300)
//     };

//     float cp;
//     float totalPortValue = 0;

//     for (int i = 0; i < 4; i++) {
//         cout << "Enter current price for stock " << i + 1 << ": ";
//         cin >> cp;
//         arr[i].display(cp);
//         totalPortValue += arr[i].currentValue(cp);
//     }

//     Stock::displayStats(totalPortValue);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Medicine {
//     string name;
//     float price;
//     int units;
// public:
//     Medicine() : units(1) {}
//     Medicine(string n, float p, int u) : name(n), price(p), units(u) {}
//     float getPrice() const { return price * units; }
//     void displayM() const {
//         cout << "  Medicine: " << name << ", $" << price
//              << " x " << units << " units" << endl;
//     }
// };

// class Prescription {
//     Medicine arr[4];
//     int quantity;
// public:
//     Prescription() : quantity(0) {}
//     void addMedicine(Medicine m) {
//         if (quantity < 4) arr[quantity++] = m;
//     }
//     float calcSubTotal() const {
//         float tot = 0;
//         for (int i = 0; i < quantity; i++)
//             tot += arr[i].getPrice();
//         return tot;
//     }
//     void displayPres() const {
//         for (int i = 0; i < quantity; i++)
//             arr[i].displayM();
//         cout << "  Prescription Total: $" << calcSubTotal() << endl;
//     }
// };

// class Patient {
//     string name;
//     const int ID;
//     Prescription arr[3];
//     int pcount;
// public:
//     Patient() : ID(0), pcount(0) {}
//     Patient(string n, int id) : name(n), ID(id), pcount(0) {}
//     void addPrescription(Prescription p) {
//         if (pcount < 3) arr[pcount++] = p;
//     }
//     float calctot() const {
//         float tot = 0;
//         for (int i = 0; i < pcount; i++)
//             tot += arr[i].calcSubTotal();
//         return tot;
//     }
//     string getName() const { return name; }
//     void displayP() const {
//         cout << "Patient: " << name << "\tID: " << ID << endl;
//         for (int i = 0; i < pcount; i++) {
//             cout << "Prescription " << i + 1 << ":" << endl;
//             arr[i].displayPres();
//         }
//         cout << "Total Bill: $" << calctot() << endl;
//     }
// };

// class Hospital {
//     Patient arr[6];
//     int pcount;
// public:
//     Hospital() : pcount(0) {}
//     void addPatient(Patient p) {
//         if (pcount < 6) arr[pcount++] = p;
//     }
//     void findHighest() {
//         int index = 0;
//         for (int i = 1; i < pcount; i++)
//             if (arr[i].calctot() > arr[index].calctot())
//                 index = i;
//         cout << "Highest Bill: " << arr[index].getName()
//              << " -> $" << arr[index].calctot() << endl;
//     }
//     void display() {
//         for (int i = 0; i < pcount; i++) {
//             arr[i].displayP();
//             cout << "-------------------" << endl;
//         }
//     }
//     float grandTotal() const {
//         float gtot = 0;
//         for (int i = 0; i < pcount; i++)
//             gtot += arr[i].calctot();
//         return gtot;
//     }
// };

// int main() {
//     Medicine m1("Panadol", 2.5, 2);
//     Medicine m2("Aspirin", 1.5, 3);
//     Medicine m3("Antibiotic", 5.0, 1);

//     Prescription p1, p2;
//     p1.addMedicine(m1);
//     p1.addMedicine(m2);
//     p2.addMedicine(m3);

//     Patient pat1("Sara Ali", 101);
//     pat1.addPrescription(p1);

//     Patient pat2("Omar Shah", 102);
//     pat2.addPrescription(p2);

//     Hospital h;
//     h.addPatient(pat1);
//     h.addPatient(pat2);

//     h.display();
//     h.findHighest();
//     cout << "Grand Total: $" << h.grandTotal() << endl;

//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Employee{
// protected:
//     string name;
//     float salary;
//     string department;
// public:
//     Employee(){}
//     Employee(string n,int s,string d):name(n),salary(s),department(d){}
//     string getName(){return name;}
//     float getSal(){return salary;}
// };
// class PerformanceBonus{
// protected:
//     int bonusPercent;
// public:
//     PerformanceBonus(float bp) : bonusPercent(bp) {}
//     float applyBonus(float salary){ salary=salary+((salary*bonusPercent)/100); return salary;}
// };
// class TaxPolicy{
// protected:
//     int taxRate=2;
// public:
//     TaxPolicy(float tr) : taxRate(tr) {}
//     float applyTax(float salary){ salary=salary-((salary*taxRate)/100); return salary;}
// };
// class CompanyPayroll:public Employee,public PerformanceBonus,public TaxPolicy{
//     Employee arr[5];
//     int empCount;
// public:
//     CompanyPayroll(float bp, float tr) : PerformanceBonus(bp), TaxPolicy(tr), empCount(0) {}
//     void addEmp(Employee e){
//         if(empCount<5){arr[empCount++]=e;}
//     }
//     float calcPay(Employee e){ float sal;
//             sal=applyBonus(e.getSal());
//             sal=applyTax(sal); return sal;
//         }
//     void track(){ float max=0;int index=0;float min=calcPay(arr[0]);
//         for(int i=0;i<empCount;i++){
//             if(calcPay(arr[i])>max){max=calcPay(arr[i]);index=i;}
//         }
//         cout<<"Employee with highest salary: "<<arr[index].getName()<<"  Salary: "<<calcPay(arr[index])<<endl;index=0;
//         for(int i=0;i<empCount;i++){
//             if(calcPay(arr[i])<min){min=calcPay(arr[i]);index=i;}
//         }
//         cout<<"Employee with lowest salary: "<<arr[index].getName()<<"  Salary: "<<calcPay(arr[index])<<endl;
//     }
//     void generatePayslip(){
//         for(int i=0;i<empCount;i++){
//             cout<<"Base Salary: "<<arr[i].getSal()<<"\tTax payed: "<<arr[i].getSal()*(taxRate/100.0)<<"\tBonus added: "<<arr[i].getSal()*(bonusPercent/100.0)<<"\tFinal pay: "<<calcPay(arr[i])<<endl;
//         }float totalPayout=0;
//         for(int i=0;i<empCount;i++){
//             totalPayout+=calcPay(arr[i]);
//         }
//         cout<<"Total company payout: "<<totalPayout<<endl;
//     }
// };
// int main(){
//     Employee e1("ALI",20000,"IT");
//     Employee e2("RUMAISA",200000,"IT");
//     CompanyPayroll C(10,2);
//     C.addEmp(e1);C.addEmp(e2);C.track();C.generatePayslip();
// }
/*Question 1 — Static, Const Members, Array of Objects
(Topic: Week 5)
Design a university course registration system. Each Course has a constant course code, course name, credit hours, and 
number of students enrolled. The system should track shared statistics: total courses offered and total students enrolled 
across all courses.
Create a Course class with private data members. Use a parameterized constructor with an initializer list to initialize all
 members and update shared statistics. Add a const function that returns whether the course is full (max capacity =
  30 students), a const function to return enrolled students, and a static function to display overall stats.
In main(), create an array of 4 courses, display each course's details and whether it is full, then display overall
 statistics.
 
 Build a supermarket billing system. A Product has a name, price per unit, and quantity. An Invoice holds up to 5 products and
  can calculate the invoice subtotal. A Checkout manages up to 4 invoices and can calculate the grand total, find the invoice 
  with the highest subtotal, and display a complete structured billing report showing all invoices, their products, and the 
  grand total.
In main(), create at least 2 invoices with different products, add them to checkout, and display the full report.

Create a university staff payroll system. A base class StaffMember holds name, base salary, and department. A derived class Lecturer adds
 number of courses taught and overrides a virtual function calculatePay() — each extra course adds $500 to base salary. Another derived class
  Administrator adds an overtime hours field and overrides calculatePay() — each overtime hour adds $50.
A separate class Allowance holds a transport and meal allowance. A derived class SeniorStaff inherits from both Lecturer and Allowance,
 overriding calculatePay() to include course bonuses plus both allowances added on top.
Implement a displayPayDetails() virtual function in each class. In main(), create a pointer array of StaffMember* holding all three types,
 loop through and call displayPayDetails() on each to demonstrate runtime polymorphism, then display total payroll.
Sample Output:
Lecturer: Ali Khan | Department: CS
Base Salary: $3000 | Courses: 3 | Final Pay: $4500

Administrator: Sara Malik | Department: Admin
Base Salary: $2500 | Overtime: 10hrs | Final Pay: $3000

Senior Staff: Omar Sheikh | Department: CS
Base Salary: $3000 | Courses: 2 | Transport: $200 | Meal: $150 | Final Pay: $4350

Total Payroll: $11850

These match your exact syllabus weeks and the same difficulty pattern as your original questions. Want solutions or want to attempt them first?*/

//#include<iostream>
// using namespace std;
// class Student {
//     string name;   
//     int age; 
// public:
//     Student(string n, int a) : name(n), age(a) {}
//     friend ostream& operator<<(ostream& out, Student& s);
//     friend istream& operator>>(istream& in,Student& s);
// };
// ostream& operator<<(ostream& out, Student& s){
//     out<<"Name: "<<s.name<<" , Age: "<<s.age;
//     return out;
// }
//  istream& operator>>(istream& in,Student& s){
//     in>>s.name;
//     in>>s.age;
//     return in;
// }
// int main(){
//     Student s1("Rumaisa",18);
//     cout<<s1<<endl;
// }

// #include<iostream>
// using namespace std;
// class StaffMember{
// protected:
//     string name;
//     float salary;
//     string department;
// public:
//     StaffMember(){}
//     StaffMember(string n,float s,string d):name(n),salary(s),department(d){}
//     virtual float calcPay(){ return salary;}
//     virtual void displayPayDetails(){ cout<<"Salary: "<<salary<<endl;}
//     virtual ~StaffMember(){}
// };
// class Lecturer:public StaffMember{
// protected:
//     int noOfCourses;
// public:
//     Lecturer(){}
//     Lecturer(string n,float s,string d,int c):StaffMember(n,s,d),noOfCourses(c){}
//     float calcPay() override {
//         return salary+(noOfCourses*500); // dont modify salary directly
//     }
//     void displayPayDetails() override {
//         cout<<"Lecturer: "<<name<<"\tDepartment: "<<department<<endl;
//         cout<<"Base Salary: $"<<salary<<"\tCourses: "<<noOfCourses<<endl;
//         cout<<"Final Pay: $"<<calcPay()<<endl;
//     }
// };
// class Administrator:public StaffMember{
//     int overtimehrs;
// public:
//     Administrator(string n,float s,string d,int o):StaffMember(n,s,d),overtimehrs(o){}
//     float calcPay() override {
//         return salary+(overtimehrs*50); // dont modify salary directly
//     }
//     void displayPayDetails() override {
//         cout<<"Administrator: "<<name<<"\tDepartment: "<<department<<endl;
//         cout<<"Base Salary: $"<<salary<<"\tOvertime hrs: "<<overtimehrs<<endl;
//         cout<<"Final Pay: $"<<calcPay()<<endl;
//     }
// };
// class Allowance{
// protected:
//     float transport;
//     float meal;
// public:
//     Allowance(float t,float m):transport(t),meal(m){}
// };
// class SeniorStaff:public Lecturer,public Allowance{
// public:
//     SeniorStaff(string n,float s,string d,int c,float t,float m):Lecturer(n,s,d,c),Allowance(t,m){}
//     float calcPay() override { // fixed name
//         return salary+(noOfCourses*500)+transport+meal; // dont modify salary directly
//     }
//     void displayPayDetails() override {
//         cout<<"Senior Staff: "<<name<<"\tDepartment: "<<department<<endl;
//         cout<<"Base Salary: $"<<salary<<"\tCourses: "<<noOfCourses<<endl;
//         cout<<"Transport: $"<<transport<<"\tMeal: $"<<meal<<endl;
//         cout<<"Final Pay: $"<<calcPay()<<endl;
//     }
// };
// int main(){
//     StaffMember* arr[3];
//     arr[0]=new Lecturer("ALI",20000,"cs",5);      // new instead of &
//     arr[1]=new Administrator("Ahmed",30000,"CS",2);
//     arr[2]=new SeniorStaff("Rumaisa",100000,"BIO",5,3.3,2);

//     float totalPayroll=0;
//     for(int i=0;i<3;i++){
//         arr[i]->displayPayDetails();
//         totalPayroll+=arr[i]->calcPay();
//         cout<<"-------------------"<<endl;
//     }
//     cout<<"Total Payroll: $"<<totalPayroll<<endl;

//     for(int i=0;i<3;i++)
//         delete arr[i];
// }

// #include<iostream>
// using namespace std;
// class Product{
//     string name;
//     float price;
//     int quantity;
// public:
//     Product(){}
//     Product(string n,float p,int q):name(n),price(p),quantity(q){}
//     float getPrice(){return price;}
//     void displayP(){cout<<"Name: "<<name<<"\tPrice: "<<price<<endl;}
// };
// class Invoice{
//     Product arr[5];
//     int pcount;
// public:
//     Invoice():pcount(0){}
//     float calcSub(){ float subt=0; for(int i=0;i<pcount;i++){subt+=arr[i].getPrice(); }return subt; }
//     void DisplayI(){for(int i=0;i<pcount;i++){arr[i].displayP();}}
// };
// class Checkout{
//     Invoice arr[4];
//     invoicecount;
// public:
//     Invoice():invoicecount(0){}
//     float grandTot(){ float tot=0; for(int i=0;i<invoicecount;i++){tot+=arr[i].calcSub();} return tot;}
//     void displayBill(){
//         for(int i=0;i<invoicecount;i++){arr[i].DisplayI();}
//         cout<<"Grand Total: "<<grandTot()<<endl;
//     }
// };
// int main(){}

// #include<iostream>
// using namespace std;
// class Course{
//     const string code;
//     int crdthrs;
//     string name;
//     int students;
//     static int totcourses;
//     static int totstudents;
// public:
//     Course(string c,int chours,string n,int s):code(c),crdthrs(chours),name(n),students(s){totstudents+=s;totcourses++;}
//     bool checkFull()const{ if(totstudents>=30)return 1; else return 0;}
//     static displayStat(){cout<<"Total Courses: "<<totcourses<<"\tTotal Students: "<<totstudents<<endl;}
// };
// int Course::totcourses=0;
// int Course::totstudents=0;
// int main(){
//     Course arr[4]={Course("S1002",4,"OOP",28),Course("S1043",4,"MVC",28),Course("S001",4,"CCE",28),Course("CS3001",4,"PF",28)};
// }

#include<iostream>
using namespace std;

class MedicalStaff {
protected:
    string name;
    const int ID;
    float salary;
public:
    MedicalStaff() : ID(0), salary(0) {}
    MedicalStaff(string n, int id, float s) : name(n), ID(id), salary(s) {}
    virtual float calcPay() { return salary; }
    virtual void displayStaff() {
        cout << "Staff: " << name << " ID: " << ID 
             << " Pay: $" << calcPay() << endl;
    }
    virtual ~MedicalStaff() {}
};

class Doctor : public MedicalStaff {
    string specialization;
    int patients;
public:
    Doctor() : patients(0) {}
    Doctor(string n, int id, float s, string sp, int p)
        : MedicalStaff(n, id, s), specialization(sp), patients(p) {}
    float calcPay() override {
        return salary + patients * 200;
    }
    void displayStaff() override {
        cout << "Doctor: " << name << " Specialization: " << specialization
             << " Patients: " << patients
             << " Final Pay: $" << calcPay() << endl;
    }
};

class Nurse : public MedicalStaff {
    int shiftHrs;
public:
    Nurse() : shiftHrs(0) {}
    Nurse(string n, int id, float s, int sh)
        : MedicalStaff(n, id, s), shiftHrs(sh) {}
    float calcPay() override {
        return salary + shiftHrs * 50;
    }
    void displayStaff() override {
        cout << "Nurse: " << name << " Shift Hours: " << shiftHrs
             << " Final Pay: $" << calcPay() << endl;
    }
};

class Insurance {
protected:
    int coveragePercent;
public:
    Insurance(int c) : coveragePercent(c) {}
    float apply(float bill) {
        return bill - bill * (coveragePercent / 100.0f);  // fixed int division
    }
};

class Medicine {
    string name;
    float cost;
public:
    Medicine() : cost(0) {}
    Medicine(string n, float c) : name(n), cost(c) {}  // fixed constructor name
    float getCost() const { return cost; }
    void displayM() const {
        cout << "  Medicine: " << name << " Cost: $" << cost << endl;
    }
};

class Patient {
    const int ID;
    string name;
    Medicine arr[5];
    int count;
    Doctor* d;
    static int totalPatients;
public:
    Patient() : ID(0), count(0), d(nullptr) {}
    Patient(int i, string n, Doctor* p) : ID(i), name(n), count(0), d(p) {
        totalPatients++;
    }
    void addMedicine(Medicine m) {
        if(count < 5) arr[count++] = m;
    }
    float calculateBill() const {
        float bill = 0;
        for(int i = 0; i < count; i++)
            bill += arr[i].getCost();
        return bill;
    }
    void displayInfo() const {
        cout << "Patient ID: " << ID << " Name: " << name << endl;
        for(int i = 0; i < count; i++)
            arr[i].displayM();
    }
    static void displayTotal() {
        cout << "Total Patients Admitted: " << totalPatients << endl;
    }
    friend ostream& operator<<(ostream& out, const Patient& p) {
        out << "Patient: " << p.name << " Bill: $" << p.calculateBill();
        return out;
    }
};
int Patient::totalPatients = 0;

class EmergencyWard : public Insurance {
    Patient arr[6]; int pcount;
    MedicalStaff* brr[4]; int mcount;
public:
    EmergencyWard(int coverage) : Insurance(coverage), pcount(0), mcount(0) {}
    void addPatient(Patient p) {
        if(pcount < 6) arr[pcount++] = p;
    }
    void addStaff(MedicalStaff* m) {
        if(mcount < 4) brr[mcount++] = m;
    }
    void display() {
        cout << "=== PATIENTS ===" << endl;
        float maxBill = arr[0].calculateBill();
        int maxIndex = 0;
        for(int i = 0; i < pcount; i++) {
            arr[i].displayInfo();
            cout << "Bill: $" << arr[i].calculateBill()
                 << " After Insurance: $" << apply(arr[i].calculateBill()) << endl;
            cout << arr[i] << endl;  // operator<< 
            if(arr[i].calculateBill() > maxBill) {
                maxBill = arr[i].calculateBill();
                maxIndex = i;
            }
            cout << "-------------------" << endl;
        }
        cout << "Highest Bill: Patient " << maxIndex + 1 
             << " $" << maxBill << endl;
        Patient::displayTotal();

        cout << "\n=== STAFF PAYROLL ===" << endl;
        float totalPayroll = 0;
        for(int i = 0; i < mcount; i++) {
            brr[i]->displayStaff();  // runtime polymorphism
            totalPayroll += brr[i]->calcPay();
        }
        cout << "Total Ward Payroll: $" << totalPayroll << endl;
    }
};

int main() {
    Doctor d1("Ali", 1203, 120000, "Cardiologist", 50);
    Doctor d2("Tahir", 1204, 110000, "Cardiologist", 40);
    Nurse n1("Sara", 1205, 60000, 8);

    Patient p1(1, "Ahmed", &d1);
    p1.addMedicine(Medicine("Panadol", 500));
    p1.addMedicine(Medicine("Aspirin", 300));

    Patient p2(2, "Hina", &d2);
    p2.addMedicine(Medicine("Antibiotic", 1200));
    p2.addMedicine(Medicine("Painkiller", 800));

    Patient p3(3, "Omar", &d1);
    p3.addMedicine(Medicine("Insulin", 2000));

    EmergencyWard ward(20);  // 20% insurance coverage
    ward.addPatient(p1);
    ward.addPatient(p2);
    ward.addPatient(p3);

    ward.addStaff(&d1);
    ward.addStaff(&d2);
    ward.addStaff(&n1);

    ward.display();
    return 0;
}