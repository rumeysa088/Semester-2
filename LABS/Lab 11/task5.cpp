#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string filename = "students.txt";
    try {
        ofstream outFile(filename);
        if (!outFile) {
            throw "Error: Failed to create file for writing!";
        }
        outFile << 101 << " Ali" << endl;
        outFile << 102 << " Sara" << endl;
        outFile.close();
        ifstream inFile(filename);
        if (!inFile) {
            throw "Error: File not found for reading!";
        }
        int id;
        string name;
        cout << "Reading data from file..." << endl;
        while (inFile >> id >> name) {
            cout << "ID: " << id << ", Name: " << name << endl;
        }
        if (!inFile.eof() && inFile.fail()) {
            throw "Error: Corrupted data format found in file!";
        }
        inFile.close();
    }
    catch (const char* errorMsg) {
        cout << "EXCEPTION CAUGHT: " << errorMsg << endl;
    }
    return 0;
}
