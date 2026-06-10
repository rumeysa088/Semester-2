#include <iostream>
using namespace std;
template <class T>
class Calculator {
private:
    T num1, num2;
public:
    void run() {
        try {
            cout << "Enter two numbers: ";
            if (!(cin >> num1 >> num2)) {
                throw "Error: Invalid Input! Please enter numbers only.";
            }
            cout << "Addition: " << num1 + num2 << endl;
            cout << "Subtraction: " << num1 - num2 << endl;
            cout << "Multiplication: " << num1 * num2 << endl;
            if (num2 == 0) {
                throw "Error: Division by zero is not allowed!";
            }
            cout << "Division: " << num1 / num2 << endl;
        } 
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};
int main() {
    Calculator<double> myCalc;
    myCalc.run();
    return 0;
}