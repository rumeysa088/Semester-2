#include<iostream>
using namespace std;
class Patient{
    int patientID;
    string name;
public:
    Patient(){};
    Patient(int id,string n):patientID(id),name(n){}
    void showDetails(){
        cout<<"\nID: "<<patientID<<"\nName: "<<name<<endl;
    }
};
class Hospital{
    Patient arr[10];
    static int totalPatients;
    int maxPatients=15;
public:
    Hospital(){};
    void addPatient(int id,string n){
        if(totalPatients<maxPatients){
            arr[totalPatients++]=Patient(id,n);
        }
    }
    void display(){
        for(int i=0;i<totalPatients;i++){
            arr[i].showDetails();
        }
    }
};
int Hospital::totalPatients=0;
int main(){
   Hospital h;
   h.addPatient(101,"sara");
   h.addPatient(102,"Ali");
   h.addPatient(103,"hamza");
   h.display();
}