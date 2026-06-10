#include <iostream>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int id;
    float salary;
public:
    Employee() {}
    Employee(string n, int i, float s) : name(n), id(i), salary(s) {}
};

// Analyst class
class Analyst : virtual public Employee {
protected:
    string specialization;
    string certifications[5];  // Array for up to 5 certifications
    int certCount;
public:
    Analyst() { certCount = 0; }
    Analyst(string spec, bool ia) : specialization(spec), certCount(0) { 
        // specialization validation
        if(spec != "Network" && spec != "Incident Response" && spec != "Threat Intelligence")
            specialization = "Unknown";
    }

    void addCertification(string c) {
        if(certCount < 5) certifications[certCount++] = c;
    }

    void displayCertifications() {
        if(certCount == 0)
            cout << "Not Certified!" << endl;
        else if(certCount == 1)
            cout << "Certification: " << certifications[0] << endl;
        else {
            cout << "Certifications: ";
            for(int i = 0; i < certCount; i++)
                cout << certifications[i] << " ";
            cout << endl;
        }
    }
};

// Engineer class
class Engineer : virtual public Employee {
protected:
    bool isAssigned;
    bool isExpert;
    string* projects;  // dynamically allocated array
    int pcount;
    int capacity;
public:
    Engineer() { isAssigned = false; isExpert = false; pcount = 0; capacity = 5; projects = new string[capacity]; }
    Engineer(bool e, bool a) : isExpert(e), isAssigned(a), pcount(0), capacity(5) { projects = new string[capacity]; }

    ~Engineer() { delete[] projects; } // free memory

    void assignProject(string p) {
        if(isExpert) {
            isAssigned = true;
            if(pcount < capacity) projects[pcount++] = p;
        } else {
            isAssigned = false;
            cout << "Cannot assign project. Not an expert!" << endl;
        }
    }

    void addProject(string p) {
        if(isAssigned) {
            if(pcount < capacity) projects[pcount++] = p;
        } else
            cout << "No projects to add!" << endl;
    }

    void displayProjects() {
        if(pcount == 0)
            cout << "No projects assigned." << endl;
        else {
            cout << "Projects: ";
            for(int i = 0; i < pcount; i++)
                cout << projects[i] << " ";
            cout << endl;
        }
    }
};

// LeadProfessional class
class LeadProfessional : public Engineer, public Analyst {
public:
    LeadProfessional(bool e, bool a, string spec, bool ia, string n, int i, float s)
        : Employee(n,i,s), Analyst(spec, ia), Engineer(e,a) {}

    void display() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
        displayCertifications();
        displayProjects();
    }
};

int main() {
    LeadProfessional lead(true, false, "Network", true, "Ali", 101, 5000);

    // Certifications
    lead.addCertification("CEH");
    lead.addCertification("CISSP");

    // Projects (dynamic)
    lead.assignProject("Firewall Upgrade");
    lead.addProject("Network Monitoring"); // only added if assigned

    lead.display();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// ---------------- Base Class ----------------
class Pastry {
protected:
    string name;
    string ingredients;
    double productionCost;
    double taxRate; // specific to each pastry type
public:
    Pastry() {}
    Pastry(string n, string ing, double cost, double tax)
        : name(n), ingredients(ing), productionCost(cost), taxRate(tax) {}

    virtual double totalCost() {
        return productionCost * 1.10; // 10% markup
    }

    virtual double retailPrice() {
        return totalCost() * (1 + taxRate) * 1.06; // tax + 6% GST
    }

    virtual double profit() {
        return 0.7 * (retailPrice() - totalCost()); // 70% of profit
    }

    virtual void display() {
        cout << "Pastry: " << name << ", Ingredients: " << ingredients << endl;
        cout << "Production Cost: " << productionCost << endl;
        cout << "Total Cost: " << totalCost() << endl;
        cout << "Retail Price: " << retailPrice() << endl;
        cout << "Profit: " << profit() << endl << endl;
    }

    friend double PastryCalculator(Pastry& p);
    friend class PastryReport;
};

// ---------------- Derived Classes ----------------
class SweetPastry : public Pastry {
public:
    SweetPastry(string n, string ing, double cost)
        : Pastry(n, ing, cost, 0.08) {} // 8% sales tax
};

class SavoryPastry : public Pastry {
public:
    SavoryPastry(string n, string ing, double cost)
        : Pastry(n, ing, cost, 0.05) {} // 5% sales tax
};

// ---------------- Friend Function ----------------
double PastryCalculator(Pastry& p) {
    return p.totalCost() * (1 + p.taxRate) * 1.06;
}

// ---------------- Friend Class ----------------
class PastryReport {
public:
    void generateReport(Pastry* pastries[], int size) {
        double totalProfit = 0;
        cout << "-------- Pastry Shop Report --------" << endl;
        for (int i = 0; i < size; i++) {
            cout << pastries[i]->name << ": Profit = " << pastries[i]->profit() << endl;
            totalProfit += pastries[i]->profit();
        }
        cout << "Total Profit = " << totalProfit << endl;
        cout << "-----------------------------------" << endl;
    }
};

// ---------------- PastryShop ----------------
class PastryShop {
private:
    Pastry* pastries[10]; // max 10 pastries
    int count;
public:
    PastryShop() { count = 0; }

    void addPastry(Pastry* p) {
        if (count < 10)
            pastries[count++] = p;
    }

    void showAll() {
        for (int i = 0; i < count; i++)
            pastries[i]->display();
    }

    double totalProfit() {
        double sum = 0;
        for (int i = 0; i < count; i++)
            sum += pastries[i]->profit();
        return sum;
    }

    void report() {
        PastryReport report;
        report.generateReport(pastries, count);
    }
};

// ---------------- Main ----------------
int main() {
    PastryShop shop;

    SweetPastry s1("Chocolate Cake", "Flour, Chocolate, Sugar", 50);
    SavoryPastry sv1("Cheese Croissant", "Flour, Cheese, Butter", 30);

    shop.addPastry(&s1);
    shop.addPastry(&sv1);

    cout << "----- All Pastries -----" << endl;
    shop.showAll();

    cout << "----- Total Profit -----" << endl;
    cout << shop.totalProfit() << endl;

    cout << "----- Pastry Report -----" << endl;
    shop.report();

    cout << "Total cost of Chocolate Cake using PastryCalculator: "
         << PastryCalculator(s1) << endl;

    return 0;
}