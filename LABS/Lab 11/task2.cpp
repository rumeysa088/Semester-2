#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream file("Ex2.txt"); 
    string line;
    int lineCount = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            lineCount++;
        }
        file.close();
        cout << "Total number of lines: " << lineCount << endl;
    } else {
        cout << "Error: Could not open file." << endl;
    }
    return 0;
}