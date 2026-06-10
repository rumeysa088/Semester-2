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
    while (!(cin >> id)) { // If input is NOT an integer
        cout << "Invalid ID. Please enter a number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(1000, '\n'); // Discard the bad input
    }
    cin.ignore(1000, '\n'); // Clear buffer for name

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter GPA: ";
    while (!(cin >> gpa)) { // If input is NOT a float
        cout << "Invalid GPA. Please enter a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n'); // CRITICAL: Clear buffer for the next loop iteration
    cout << "--------------------" << endl;
}


    void writeToFile() {
        ofstream file("student.txt", ios::app);
        if (file.is_open()) {
            // We put name at the END to make reading easier
            file << id << " " << gpa << " " << name << endl;
            file.close();
        } 
    }

    void readFromFile() {
        ifstream file("student.txt");
        if (!file) {
            cout << "No records found!" << endl;
            return; 
        }
        cout << "\n--- All Student Records ---\n";
        
        // Read ID and GPA first, then the rest of the line as the Name
        while (file >> id >> gpa) {
            file.ignore(); // Ignore the space before the name
            getline(file, name); 
            cout << "ID: " << id << " | GPA: " << gpa << " | Name: " << name << endl;
        }
        file.close(); 
    }
};

int main() {
    Student s;
    for (int i = 1; i <= 5; i++) {
        cout << "Recording Student #" << i << ":" << endl;
        s.input();       
        s.writeToFile();  
    }
    s.readFromFile();
    return 0;
}
