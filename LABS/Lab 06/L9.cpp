#include<iostream>
using namespace std;
class Machine {
public:
    void show() { cout << "Machine" << endl; }
};
class Printer : virtual public Machine {
public:
    Machine* getBasePtr() { return this; } 
};
class Scanner : virtual public Machine {
public:
    Machine* getBasePtr() { return this; } 
};
class AllInOne : public Printer, public Scanner {
public:
    Machine* getBasePtr() { return this; } 
};
int main() {
    AllInOne obj;
    obj.show(); // No ambiguity
    cout << "Printer->Machine: " << obj.Printer::getBasePtr() << endl;
    cout << "Scanner->Machine: " << obj.Scanner::getBasePtr() << endl;
    cout << "AllInOne->Machine: " << obj.getBasePtr() << endl;
    return 0;
}