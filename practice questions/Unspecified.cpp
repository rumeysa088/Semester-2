// #include<iostream>
// using namespace std;
// class Superman{
//     const int power;
//     const int health;
// public:
//     Superman(int p,int h):power(p),health(h){}
//     void display() const{
//         cout<<"Health: "<<health<<"\nPower: "<<power<<endl;
//     }
//     void setHealth(int newHealth){health=newHealth;}
//     void setPower(int newPower){power=newPower;}
// };
// int main(){

// }

#include<iostream>
using namespace std;
class Room{
    string item;
public:
    Room(string i=""){item=i;}
    bool hasRelation(Room* r1,int s1,Room* r2,int s2){
        bool found=0;
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
                if((*(r1+i)).item==(*(r2+j)).item){found=1;break;}
            }
            if(found==0)return 0;
        } return 1;
    }
};
int main(){
      Room room1[2] = {Room("Chair"), Room("Table")};

    Room room2[4] = {Room("Lamp"), Room("Chair"), Room("Table"), Room("TV")};

    Room r;

    if(r.hasRelation(room1,2,room2,4))
        cout<<"Has relation exists"<<endl;
    else
        cout<<"Has relation does not exist"<<endl;
}

#include<iostream>
using namespace std;

class Victim{
protected:
    string name;
    string history;
    string role;

public:
    void setVictim(string n,string h,string r){
        name=n;
        history=h;
        role=r;
    }
};

class Lawyer{
protected:
    int licenseNumber;
    string specialization;
    int YOP;
    string victimEvidence;

public:
    void setLawyer(int l,string s,int y,string e){
        licenseNumber=l;
        specialization=s;
        YOP=y;
        victimEvidence=e;
    }
};

class Judge{
protected:
    int judicialID;
    int YOE;
    string specializationJ;

public:
    void setJudge(int id,int y,string s){
        judicialID=id;
        YOE=y;
        specializationJ=s;
    }

    string giveDecision(string evidence,string history){
        if(evidence=="strong")
            return "Guilty";
        else
            return "Not Guilty";
    }
};

class Admin:public Victim,public Lawyer,public Judge{
    int roomNumber;
    int capacity;
    string availabilitySchedule;

public:
    void setAdmin(int r,int c,string a){
        roomNumber=r;
        capacity=c;
        availabilitySchedule=a;
    }

    void displayAdmin(){
        cout<<"Courtroom: "<<roomNumber<<endl;
        cout<<"Victim Name: "<<name<<endl;
        cout<<"Victim History: "<<history<<endl;
        cout<<"Lawyer Evidence: "<<victimEvidence<<endl;

        cout<<"Judge Decision: "<<giveDecision(victimEvidence,history)<<endl;
    }
};


int main(){

    Admin a;

    a.setVictim("Ali","previous theft","accused");
    a.setLawyer(1234,"criminal",10,"strong");
    a.setJudge(5001,15,"criminal");
    a.setAdmin(12,50,"Monday");

    a.displayAdmin();

}