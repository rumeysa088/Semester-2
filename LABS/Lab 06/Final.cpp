#include<iostream>
#include<string>
using namespace std;
class Person {
public:
    string name;                
protected:
    int age;                    
private:
    int privateID;              
public:
    Person(string n="", int a=0, int id=0) : name(n), age(a), privateID(id) {}
    void showPublic() { cout << "Name: " << name << endl; }
    void showProtected() { cout << "Age: " << age << endl; }
    void showPrivate() { cout << "ID: " << privateID << endl; }
};
class Teacher : virtual public Person {
public:
    Teacher() {}
    void teach() { cout << name << " is teaching." << endl; }
};
class Student : virtual public Person {
public:
    Student() {}
    void study() { cout << name << " is studying." << endl; }
};
class TeachingAssistant : public Teacher, public Student {
public:
    TeachingAssistant() {}
    void assist() { cout << name << " is assisting in class." << endl; }
};
class ExamAssistant : public TeachingAssistant {
public:
    ExamAssistant(string n, int a, int id): Person(n, a, id) {}
    void conductExam() { cout << name << " is conducting an exam." << endl; }
};
int main() {
    ExamAssistant ta("Ali", 22, 1001);
    cout << "Access Base Class Members" << endl;
    ta.showPublic();    
    ta.showProtected(); 
    ta.showPrivate();   
    cout << "\nAccess Derived Class Functions" << endl;
    ta.teach();      
    ta.study();       
    ta.assist();      
    ta.conductExam(); 

    return 0;
}