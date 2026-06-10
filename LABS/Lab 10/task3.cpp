#include <iostream>
using namespace std;
int main() {
    int marks;
    cout << "Enter student marks: ";
    cin >> marks;
    try {
        if (marks < 0) {
            throw "Error: Marks are below 0!";
        }
        if (marks > 100) {
            throw "Error: Marks are above 100!";
        }
        cout << "Valid marks: " << marks << endl;
        if (marks >= 50) {
            cout << "Grade: Pass" << endl;
        } else {
            cout << "Grade: Fail" << endl;
        }
    } 
    catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}