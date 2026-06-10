// #include<iostream>
// #include<string>
// using namespace std;
// class Patient{
//     public:
//     const int patientID;
//     string name;
//     Patient(int id=0):patientID(id){}
//     Patient(int id,string n):patientID(id){name=n;}
// };
// class Hospital{
//     Patient arr[10];
//     static int totalPatients;
// public: 
//     Hospital(){}
//     void addPatient(int id,string n){
//         arr[totalPatients].patientID=id;
//         arr[totalPatients].name=n;
//         totalPatients++;
//     }
//     void display(){
//         for(int i=0;i<totalPatients;i++){
//         cout<<"Patient ID: "<<arr[i].patientID
//         <<"Name: "<<arr[i].name<<"---------------------"<<endl;
//         }
//     }
// };
// int Hospital::totalPatients=0;
// int main(){
//     Hospital h;
//     h.addPatient(101,"Ali");
//     h.addPatient(102,"Sara");
//     h.addPatient(103,"Ahmed");
// }

#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    const int patientID;
    string name;
    Patient(int id, string n) : patientID(id), name(n) { }
};
class Hospital {
    Patient* arr[10];         
    static int totalPatients;
public:
    Hospital() { }
    void addPatient(int id, string n) {
        arr[totalPatients] = new Patient(id, n); 
        totalPatients++;
    }
    void display() {
        for (int i = 0; i < totalPatients; i++) {
            cout << "Patient ID: " << arr[i]->patientID
                 << "\nName: " << arr[i]->name
                 << "\n---------------------" << endl;
        }
    }
};
int Hospital::totalPatients = 0;
int main() {
    Hospital h;
    h.addPatient(101, "Ali");
    h.addPatient(102, "Sara");
    h.addPatient(103, "Ahmed");
    h.display();
}
