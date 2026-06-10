#include <iostream>
#include <fstream>
using namespace std;
int main() {
    try {
        ifstream file("data.txt");
        if (!file) {
            throw "Error: File does not exist!";
        }
        cout << "File opened successfully." << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}