#include <iostream>
#include <fstream> 
using namespace std;
int main() {
    ofstream file;
    file.open("Ex2.txt");
    if (!file) {
        cout << "Could not open file for writing!" << endl;
        return 1;}
    for (int i = 0; i < 10; i++) {
        file << i << " ";  }
    file.close();
    ifstream in;
    in.open("Ex2.txt");
    if (!in) {
        cout << "Could not open file for reading!" << endl;
        return 1;  }
    int num;
    while (in >> num) { 
        if (num % 2 == 0) {
            cout << " " <<num;
        }}
    in.close(); 
    return 0;
}
