#include<iostream>
#include<string>
using namespace std; //student-furniture association  furniture-room comp here student-room aggregtion here
class Student{
    int ID;
    string name;
    string department;
public:
    Student(int i,string n,string d){ID=i;name=n;department=d;}
    Student(){}
    void display(){cout<<"ID: "<<ID<<" Name: "<<name<<" Department: "<<department<<endl;}
    int getID(){ return ID;}
};
class Furniture{
    string type;
    int quantity;
public:
    Furniture(){}
    Furniture(string t,int q):type(t),quantity(q){}
    void display(){cout<<"Type: "<<type<<" Quantity: "<<quantity<<endl;}
};
class Rooms{
    int roomNumber;
    const int maxCap=4;
    int studentcount=0;
    Student* arr[4];
    Furniture f;
public:
     Rooms(){}
     Rooms(int n,string t,int q):f(t,q){ roomNumber=n;} 
    void addStudent(Student* s){
      if(studentcount<maxCap){
        arr[studentcount++]=s;
      }
    }
    void deleteStudent(int studentID){ int index;
       for(int i=0;i<studentcount;i++){
        if(arr[i]->getID()==studentID){index=i;break;}
       }
       for(int i=index;i<studentcount-1;i++){
         arr[i]=arr[i+1];
       }
    }
    void display(){
        cout<<"Room no: "<<roomNumber<<"Student count: "<<studentcount<<endl;
        for(int i=0;i<studentcount;i++){
            arr[i]->display();
        }
        f.display();
    }
};
int main(){
    Student s1(1,"rumaisa","CS"),s2(2,"ali","business"),s3(3,"ayesha","arts"),s4(4,"bilal","math");
    Rooms r1(1,"Sofa",1);
    r1.addStudent(&s1);r1.addStudent(&s2);r1.addStudent(&s3);r1.addStudent(&s4);
    r1.display();
}

#include <iostream>
#include <string>
using namespace std;

/* ---------- Student Class (Aggregation) ---------- */
class Student {
    int ID;
    string name;
    string department;

public:
    Student(int i, string n, string d)
        : ID(i), name(n), department(d) {}

    int getID() const { return ID; }

    void display() const {
        cout << "ID: " << ID
             << ", Name: " << name
             << ", Dept: " << department << endl;
    }
};

/* ---------- Furniture Class (Composition) ---------- */
class Furniture {
    string type;
    int quantity;

public:
    Furniture(string t = "Bed", int q = 1)
        : type(t), quantity(q) {}

    void display() const {
        cout << "Furniture: " << type
             << ", Quantity: " << quantity << endl;
    }
};

/* ---------- Room Class ---------- */
class Room {
    int roomNumber;
    const int maxCapacity = 4;
    int studentCount = 0;

    Student* students[4];   // Aggregation (pointers to external students)
    Furniture furniture;    // Composition (belongs to room)

public:

    // Furniture automatically created with room
    Room(int number)
        : roomNumber(number), furniture("Bed", 4) {}

    /* Add student by reference (as required) */
    void addStudent(Student &s) {

        if (studentCount < maxCapacity) {
            students[studentCount++] = &s;
        }
        else {
            cout << "Room is full!\n";
        }
    }

    /* Remove student by ID */
    void removeStudent(int studentID) {

        int index = -1;

        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == studentID) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }

        // Shift left
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }

        studentCount--;
    }

    /* Display all room info */
    void displayRoomInfo() const {

        cout << "\n=== Room Information ===\n";
        cout << "Room Number: " << roomNumber << endl;
        cout << "Occupancy: " << studentCount
             << "/" << maxCapacity << endl;

        cout << "\nStudents in Room:\n";
        if (studentCount == 0)
            cout << "No students assigned.\n";
        else
            for (int i = 0; i < studentCount; i++)
                students[i]->display();

        cout << "\nFurniture Details:\n";
        furniture.display();
    }
};

/* ---------- Main Function ---------- */
int main() {

    // 1. Create students (independent objects)
    Student s1(1, "Rumaisa", "CS");
    Student s2(2, "Ali", "Business");
    Student s3(3, "Ayesha", "Arts");
    Student s4(4, "Bilal", "Math");

    // 2. Create room (furniture auto-created)
    Room r1(101);

    // 3. Add students
    r1.addStudent(s1);
    r1.addStudent(s2);
    r1.addStudent(s3);
    r1.addStudent(s4);

    // 4. Display info
    r1.displayRoomInfo();

    // 5. Remove a student
    r1.removeStudent(2);

    cout << "\nAfter removing student with ID 2:\n";
    r1.displayRoomInfo();

    return 0;
}