#include<iostream>
using namespace std;
class Machine {
public:
    void show() { cout << "Machine" << endl; }
};
class Printer : public Machine {
};
class Scanner : public Machine {
};
class AllInOne : public Printer, public Scanner {
};
int main() {
    AllInOne obj;
    // obj.show(); //  Ambiguous: compiler doesn't know which
    //  Machine::show() to call
    obj.Printer::show();  // Works: call Printer's path
    obj.Scanner::show();  // Works: call Scanner's path
    return 0;
}