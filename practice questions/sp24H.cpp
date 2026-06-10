#include<iostream>
using namespace std;

// ---------------- BASE CLASS ----------------
class Ship {
protected:
    string name;
    string yearBuilt;
    int length;
    int capacity;

public:
    Ship(string n, string yb, int l, int c)
        : name(n), yearBuilt(yb), length(l), capacity(c) {}

    virtual void display() {
        cout << "Name: " << name
             << "\nYear Built: " << yearBuilt
             << "\nLength: " << length
             << "\nCapacity: " << capacity << endl;
    }
};

// ---------------- NAVAL VESSEL ----------------
class NavalVessel : public Ship {
    string shipClass;
    int missiles;
    int armament;

public:
    NavalVessel(string n, string yb, int l, int c,
                string sc, int m, int a)
        : Ship(n, yb, l, c) {
        shipClass = sc;
        missiles = m;
        armament = a;
    }

    void deployTorpedoes(int num) {
        missiles = num;
    }

    void fireMissiles() {
        if (missiles > 0)
            missiles--;
    }

    void display() override {
        Ship::display();
        cout << "Class: " << shipClass
             << "\nMissiles: " << missiles
             << "\nArmament: " << armament << endl;
    }
};

// ---------------- CARGO SHIP ----------------
class CargoShip : public Ship {
    string cargoType;
    string container;

public:
    CargoShip(string n, string yb, int l, int c,
              string ct)
        : Ship(n, yb, l, c) {
        cargoType = ct;
        container = "vacant";
    }

    void loadCargo(string cont) {
        container = cont;
    }

    void unloadCargo() {
        container = "vacant";
    }

    void display() override {
        Ship::display();
        cout << "Cargo Type: " << cargoType
             << "\nContainer: " << container << endl;
    }
};

// ---------------- CRUISE SHIP ----------------
class CruiseShip : public Ship {
    int passengerCapacity;
    string destination;

public:
    CruiseShip(string n, string yb, int l, int c,
               int pc, string d)
        : Ship(n, yb, l, c) {
        passengerCapacity = pc;
        destination = d;
    }

    void bookCabin(int passengers) {
        if (passengers <= passengerCapacity) {
            cout << "Cabin booked for " << passengers << " passengers\n";
            passengerCapacity -= passengers;
        } else {
            cout << "Not enough capacity!\n";
        }
    }

    void updateCapacity(int newCap) {
        if (newCap > passengerCapacity)
            passengerCapacity = newCap;
    }

    void display() override {
        Ship::display();
        cout << "Passenger Capacity: " << passengerCapacity
             << "\nDestination: " << destination << endl;
    }
};

// ---------------- MAIN ----------------
int main() {

    Ship* ships[3];

    ships[0] = new NavalVessel("Destroyer", "2005", 300, 1000, "A-Class", 10, 500);
    ships[1] = new CargoShip("CargoX", "2010", 500, 2000, "Containers");
    ships[2] = new CruiseShip("Titanic-2", "2020", 800, 3000, 500, "Maldives");

    cout << "---- SHIP DETAILS ----\n\n";

    for (int i = 0; i < 3; i++) {
        ships[i]->display();   // runtime polymorphism
        cout << "---------------------\n";
    }

    return 0;
 }
#include<iostream>
#include<stdexcept>
using namespace std;
class LoanManager;
class Loan {
protected:
    float loanAmount;
    float interestRate;
    int duration; // months
public:
    Loan(float l, float i, int d) {
        if (l <= 0) throw "Invalid Loan Amount!";
        if (i < 0 || i > 100) throw "Invalid Interest Rate!";
        if (d <= 0) throw "Invalid Duration!";
        loanAmount = l;
        interestRate = i;
        duration = d;
    }
    virtual double calculateMonthlyPayment() const = 0;
    virtual void display() const = 0;
    friend class LoanManager;
    friend double calculateTotalInterestPaid(const Loan& l);
};
class CarLoan : public Loan {
public:
    CarLoan(float l, float i, int d) : Loan(l, i, d) {}
    double calculateMonthlyPayment() const override {
        return (loanAmount + (loanAmount * interestRate / 100)) / duration;
    }
    void display() const override {
        cout << "Car Loan\nAmount: " << loanAmount
             << "\nRate: " << interestRate
             << "\nDuration: " << duration << endl;
    }
};
class HomeLoan : public Loan {
public:
    HomeLoan(float l, float i, int d) : Loan(l, i, d) {}
    double calculateMonthlyPayment() const override {
        return (loanAmount + (loanAmount * interestRate / 100)) / duration;
    }
    void display() const override {
        cout << "Home Loan\nAmount: " << loanAmount
             << "\nRate: " << interestRate
             << "\nDuration: " << duration << endl;
    }
};
class BusinessLoan : public Loan {
public:
    BusinessLoan(float l, float i, int d) : Loan(l, i, d) {}
    double calculateMonthlyPayment() const override {
        return (loanAmount + (loanAmount * interestRate / 100)) / duration;
    }
    void display() const override {
        cout << "Business Loan\nAmount: " << loanAmount
             << "\nRate: " << interestRate
             << "\nDuration: " << duration << endl;
    }
};
class LoanManager {
public:
    void approveLoan(Loan* l) {
        cout << "Loan Approved!\n";
    }
    double calcTotalInterest(Loan* l) {
        return (l->loanAmount * l->interestRate) / 100;
    }
};
double calculateTotalInterestPaid(const Loan& l) {
    return (l.loanAmount * l.interestRate) / 100;
}
int main() {
    try {
        Loan* loans[3];
        loans[0] = new CarLoan(10000, 5, 12);
        loans[1] = new HomeLoan(50000, 7, 24);
        loans[2] = new BusinessLoan(80000, 10, 36);
        LoanManager manager;
        for (int i = 0; i < 3; i++) {
            loans[i]->display();
            cout << "Monthly Payment: "
                 << loans[i]->calculateMonthlyPayment() << endl;
            cout << "Total Interest (friend func): "
                 << calculateTotalInterestPaid(*loans[i]) << endl;
            cout << "----------------------\n";
        }
    } catch (const char* e) {
        cout << "Exception: " << e << endl;
    }


    return 0;
}
#include<iostream>
using namespace std;
class Plant {
protected:
    string name;
    string type;
    float price;
public:
    Plant(string n, string t, float p) {
        if (n == "") throw "Invalid Plant Name!";
        if (p < 0) throw "Invalid Price!";
        name = n;
        type = t;
        price = p;
    }
    virtual float calculateCost() const = 0;  
    virtual void display() const = 0;
    virtual ~Plant() {}
    friend ostream& operator<<(ostream& out, const Plant& p);
};
ostream& operator<<(ostream& out, const Plant& p) {
    p.display();
    return out;
}
class CompanyLawnPlant : public Plant {
    int quantity;
    int maintenanceLevel;
public:
    CompanyLawnPlant(string n, string t, float p, int q, int m)
        : Plant(n, t, p) {
        if (q < 0) throw "Invalid Quantity!";
        quantity = q;
        maintenanceLevel = m;
    }
    float calculateCost() const override {
        return quantity * price + maintenanceLevel * 10;
    }
    void display() const override {
        cout << "Name: " << name
             << "\nType: " << type
             << "\nQuantity: " << quantity
             << "\nPrice: $" << price << endl;
    }
};
class FamilyParkPlant : public Plant {
    int quantity;
    int maintenanceLevel;
public:
    FamilyParkPlant(string n, string t, float p, int q, int m)
        : Plant(n, t, p) {
        if (q < 0) throw "Invalid Quantity!";
        quantity = q;
        maintenanceLevel = m;
    }
    float calculateCost() const override {
        return quantity * price + maintenanceLevel * 5;
    }
    void display() const override {
        cout << "Name: " << name
             << "\nType: " << type
             << "\nQuantity: " << quantity
             << "\nPrice: $" << price << endl;
    }
};
class Project {
    string projectName;
    Plant* plants[10];
    int count;
    float totalCost;
public:
    Project(string n) {
        projectName = n;
        count = 0;
        totalCost = 0;
    }
    Project& operator+(Plant* p) {
        if (count < 10) {
            plants[count++] = p;
            totalCost += p->calculateCost();
        }
        return *this;
    }
    void display() {
        cout << "\nPlants for " << projectName << ":\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ".\n";
            cout << *plants[i] << endl;
        }
        cout << "Total Cost: $" << totalCost << endl;
    }
};
int main() {
    try {
        Project company("Company Lawn");
        Project park("Family Park");
        Plant* p1 = new CompanyLawnPlant("Marigold", "Flower", 2.5, 100, 2);
        Plant* p2 = new CompanyLawnPlant("Oak Tree", "Tree", 30, 10, 5);
        Plant* p3 = new FamilyParkPlant("Rose Bush", "Shrub", 5, 50, 3);
        Plant* p4 = new FamilyParkPlant("Maple Tree", "Tree", 40, 20, 4);
        company + p1;
        company + p2;
        park + p3;
        park + p4;
        company.display();
        park.display();
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
    return 0;
}

#include<iostream>
using namespace std;

// ---------------- TEMPLATE BASE CLASS ----------------
template <class T>
class Plant {
protected:
    string name;
    string type;
    T price;

public:
    Plant(string n, string t, T p) {
        if (n == "") throw "Invalid Name!";
        if (p < 0) throw "Invalid Price!";
        name = n;
        type = t;
        price = p;
    }

    virtual T calculateCost() const = 0;
    virtual void display() const = 0;

    virtual ~Plant() {}

    template <class U>
    friend ostream& operator<<(ostream& out, const Plant<U>& p);
};

// ----------- << OPERATOR (TEMPLATE FRIEND) -----------
template <class U>
ostream& operator<<(ostream& out, const Plant<U>& p) {
    p.display();
    return out;
}

// ---------------- COMPANY LAWN ----------------
template <class T>
class CompanyLawnPlant : public Plant<T> {
    int quantity;
    int maintenance;

public:
    CompanyLawnPlant(string n, string t, T p, int q, int m)
        : Plant<T>(n, t, p) {
        if (q < 0) throw "Invalid Quantity!";
        quantity = q;
        maintenance = m;
    }

    T calculateCost() const override {
        return quantity * this->price + maintenance * 10;
    }

    void display() const override {
        cout << "Name: " << this->name
             << "\nType: " << this->type
             << "\nQuantity: " << quantity
             << "\nPrice: $" << this->price << endl;
    }
};

// ---------------- FAMILY PARK ----------------
template <class T>
class FamilyParkPlant : public Plant<T> {
    int quantity;
    int maintenance;

public:
    FamilyParkPlant(string n, string t, T p, int q, int m)
        : Plant<T>(n, t, p) {
        if (q < 0) throw "Invalid Quantity!";
        quantity = q;
        maintenance = m;
    }

    T calculateCost() const override {
        return quantity * this->price + maintenance * 5;
    }

    void display() const override {
        cout << "Name: " << this->name
             << "\nType: " << this->type
             << "\nQuantity: " << quantity
             << "\nPrice: $" << this->price << endl;
    }
};

// ---------------- PROJECT TEMPLATE ----------------
template <class T>
class Project {
    string projectName;
    Plant<T>* plants[10];
    int count;
    T totalCost;
public:
    Project(string n) {
        projectName = n;
        count = 0;
        totalCost = 0;
    }
    // + operator
    Project& operator+(Plant<T>* p) {
        if (count < 10) {
            plants[count++] = p;
            totalCost += p->calculateCost();
        }
        return *this;
    }
    void display() const {
        cout << "\nPlants for " << projectName << ":\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ".\n";
            cout << *plants[i] << endl;
        }
        cout << "Total Cost: $" << totalCost << endl;
    }
};

// ---------------- MAIN ----------------
int main() {
    try {
        Project<float> company("Company Lawn");
        Project<float> park("Family Park");
        Plant<float>* p1 = new CompanyLawnPlant<float>("Marigold", "Flower", 2.5, 100, 2);
        Plant<float>* p2 = new CompanyLawnPlant<float>("Oak Tree", "Tree", 30, 10, 5);

        Plant<float>* p3 = new FamilyParkPlant<float>("Rose Bush", "Shrub", 5, 50, 3);
        Plant<float>* p4 = new FamilyParkPlant<float>("Maple Tree", "Tree", 40, 20, 4);
        company + p1;
        company + p2;
        park + p3;
        park + p4;
        company.display();
        park.display();

    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
    return 0;
}