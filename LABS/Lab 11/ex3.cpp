#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
class Student {
private:
    int id;
    string name;
    float gpa;
public:
    void input() {
        cout << "Enter ID: ";
        cin >> id; 
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name); 
        cout << "Enter GPA: ";
        cin >> gpa;
        cout << "--------------------" << endl; }
    void writeToFile() {
        ofstream file("student.txt", ios::app);
        if (file.is_open()) {
            file << id << " " << name << " " << gpa << endl;
            file.close();} }
};
int main() {
    Student s;
    for (int i = 1; i <= 5; i++) {
        cout << "Recording Student #" << i << ":" << endl;
        s.input();       
        s.writeToFile(); 
    }
    cout << "All 5 student records have been saved to student.txt!" << endl;
    return 0;
}