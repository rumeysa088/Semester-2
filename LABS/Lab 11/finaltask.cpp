#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student {
public:
    int id;
    string name;
    void input() {
        cout << "Enter ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);  }
    void display() {
        cout << "ID: " << id << " | Name: " << name << endl;   }
};
void addStudent() {
    Student s;
    s.input();
    ofstream file("data.txt", ios::app);
    if (!file) throw "Error: Could not open file for writing!";
    file << s.id << " " << s.name << endl;
    file.close();
    cout << "Record saved successfully!\n";
}
void viewStudents() {
    Student s;
    ifstream file("data.txt");
    if (!file) throw "Error: File not found!";
    cout << "\n--- Student List ---\n";
    while (file >> s.id >> s.name) {
        s.display();    }
    file.close();
}
void searchStudent() {
    int searchId;
    cout << "Enter ID to search: "; cin >> searchId;
    ifstream file("data.txt");
    if (!file) throw "Error: File not found!";
    Student s;
    bool found = false;
    while (file >> s.id >> s.name) {
        if (s.id == searchId) {
            cout << "Record Found: ";
            s.display();
            found = true;
            break;  }
    }
    if (!found) cout << "Student ID not found.\n";
    file.close();
}
int main() {
    int choice;
    while (true) {
        try {
            cout << "\n1. Add Student\n2. View All\n3. Search\n4. Exit\nChoice: ";
            cin >> choice;
            if (choice == 1) addStudent();
            else if (choice == 2) viewStudents();
            else if (choice == 3) searchStudent();
            else if (choice == 4) break;
            else cout << "Invalid choice!\n";
        }
        catch (const char* msg) {
            cout << "EXCEPTION: " << msg << endl;   }
    }
    return 0;
}
