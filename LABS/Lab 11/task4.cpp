#include <iostream>
#include <fstream>
using namespace std;
class Student {
public:
    int id;
    char name[50];
};
int main() {
    Student s; 
    ifstream file("student.dat", ios::binary);
    if (!file) {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }
    cout << "--- Student Records from Binary File ---" << endl;
    while (file.read((char*)&s, sizeof(s))) {
        cout << "ID: " << s.id << " | Name: " << s.name << endl;
    }
    file.close();
    return 0;
}
