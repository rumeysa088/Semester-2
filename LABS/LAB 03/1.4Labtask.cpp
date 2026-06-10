#include <iostream>
#include<string>
using namespace std;

class Teacher {
public:
    string name;
    string subject;

    void display() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Teacher t1, t2;

    t1.name = "Ali";
    t1.subject = "Mathematics";

    t2.name = "Sara";
    t2.subject = "Physics";

    t1.display();
    t2.display();

    return 0;
}
