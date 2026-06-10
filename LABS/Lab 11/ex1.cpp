#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
int main() {
    string name;
    int age;
    cout << "Enter name: ";
    getline(cin, name); 
    cout << "Enter Age: ";
    cin >> age;
    ofstream file;
    file.open("user.txt");
    if (!file) {
        cout << "Could not open file!" << endl;
        return 1; 
    }
    file << "Name: " << name << ", Age: " << age << endl; 
    file.close();
    cout << "Data saved successfully!";
    return 0;
}
