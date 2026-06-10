#include <iostream>
#include <fstream>
#include <cstring> 
using namespace std;
class Student {
public:
    int id;
    char name[50];
    void setData(int i, const char* n) {
        id = i;
        strncpy(name, n, 49);
        name[49] = '\0'; 
    }
};
int main() {
    Student s[3];
    s[0].setData(101, "Ali");
    s[1].setData(102, "Sara");
    s[2].setData(103, "Zayn");
    ofstream file("student.dat", ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        file.write((char*)&s[i], sizeof(s[i]));
    }
    file.close();
    cout << "Multiple binary records written successfully." << endl;
    return 0;
}
