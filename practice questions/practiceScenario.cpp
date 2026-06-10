// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// class Block;
// class Cell;
// class PrisonGuard;

// //================ STAFF =================

// class Staff
// {
// protected:
//     int id;
//     string fullName;
//     double salary;
//     string address;
//     int experience;

//     static int nextID;

// public:
//     Staff(string n="", double s=0,
//           string a="", int e=0)
//     {
//         id = ++nextID;
//         fullName = n;
//         salary = s;
//         address = a;
//         experience = e;
//     }

//     virtual void show_details() = 0;

//     int getExperience() const
//     {
//         return experience;
//     }

//     virtual ~Staff(){}
// };

// int Staff::nextID = 1000;

// //================ CELL =================

// class Cell
// {
//     int cell_ID;
//     static int nextID;

// public:
//     Cell()
//     {
//         cell_ID = ++nextID;
//     }

//     int getCellID() const
//     {
//         return cell_ID;
//     }
// };

// int Cell::nextID = 500;

// //================ PRISONER =================

// class Prisoner
// {
//     int inmate_ID;
//     string fullName;
//     int age;
//     string city;
//     string crime;
//     string sentence_type;

//     Block* block_lockedup_in;
//     Cell* cell_lockedup_in;

//     static int nextID;
//     static int totalPrisoners;

// public:

//     Prisoner(string n="", int a=0,
//              string c="", string cr="",
//              string st="")
//     {
//         inmate_ID = ++nextID;

//         fullName = n;
//         age = a;
//         city = c;
//         crime = cr;
//         sentence_type = st;

//         block_lockedup_in = NULL;
//         cell_lockedup_in = NULL;

//         totalPrisoners++;
//     }

//     // ONLY THESE ARE ALLOWED

//     void assignBlock(Block* b)
//     {
//         block_lockedup_in = b;
//     }

//     void assignCell(Cell* c)
//     {
//         cell_lockedup_in = c;
//     }

//     int getID() const
//     {
//         return inmate_ID;
//     }

//     string getName() const
//     {
//         return fullName;
//     }

//     static int getTotalPrisoners()
//     {
//         return totalPrisoners;
//     }

//     void display()
//     {
//         cout<<"ID: "<<inmate_ID<<endl;
//         cout<<"Name: "<<fullName<<endl;
//         cout<<"Age: "<<age<<endl;
//         cout<<"City: "<<city<<endl;
//         cout<<"Crime: "<<crime<<endl;
//         cout<<"Sentence: "<<sentence_type<<endl;
//     }
// };

// int Prisoner::nextID = 2000;
// int Prisoner::totalPrisoners = 0;

// //================ ADMIN =================

// class AdministrativePersonnel : public Staff
// {
//     string department;

// public:

//     AdministrativePersonnel(
//         string n,
//         double s,
//         string a,
//         int e,
//         string d)
//         : Staff(n,s,a,e)
//     {
//         department = d;
//     }

//     void show_details()
//     {
//         cout<<"Administrative Personnel"<<endl;
//         cout<<"ID: "<<id<<endl;
//         cout<<"Name: "<<fullName<<endl;
//         cout<<"Department: "<<department<<endl;
//         cout<<"Experience: "<<experience<<endl;
//     }
// };

// //================ GUARD =================

// class PrisonGuard : public Staff
// {
//     Block* block_working_in;

// public:

//     PrisonGuard(
//         string n="",
//         double s=0,
//         string a="",
//         int e=0)
//         : Staff(n,s,a,e)
//     {
//         block_working_in = NULL;
//     }

//     void assignBlock(Block* b)
//     {
//         block_working_in = b;
//     }

//     void show_details()
//     {
//         cout<<"Prison Guard"<<endl;
//         cout<<"ID: "<<id<<endl;
//         cout<<"Name: "<<fullName<<endl;
//         cout<<"Experience: "<<experience<<endl;
//     }

//     void viewPrisonerInfo(Prisoner& p)
//     {
//         p.display();
//     }
// };

// //================ BLOCK =================

// class Block
// {
//     int prisonerCount;
//     int cellCount;
//     double budget;

//     PrisonGuard* incharge;

// public:

//     Block(int p=0,
//           int c=0,
//           double b=0)
//     {
//         prisonerCount = p;
//         cellCount = c;
//         budget = b;
//         incharge = NULL;
//     }

//     void setIncharge(PrisonGuard* g)
//     {
//         incharge = g;
//     }
// };

// //================ SUPERINTENDENT =================

// class Superintendent
// {
//     string fullName;

// public:

//     Superintendent(string n="")
//     {
//         fullName = n;
//     }

//     void assignGuardToBlock(
//         PrisonGuard& g,
//         Block* b)
//     {
//         g.assignBlock(b);
//     }

//     void changeBlockIncharge(
//         Block& b,
//         PrisonGuard* g)
//     {
//         b.setIncharge(g);
//     }

//     void terminateGuard(
//         PrisonGuard& g)
//     {
//         cout<<"Guard terminated."<<endl;
//     }

//     void terminateAdministrativePersonnel(
//         AdministrativePersonnel& a)
//     {
//         cout<<"Administrative Personnel terminated."
//             <<endl;
//     }

//     // POINT H

//     void movePrisonerToBlock(
//         Prisoner& p,
//         Block* b)
//     {
//         p.assignBlock(b);
//     }

//     void movePrisonerToCell(
//         Prisoner& p,
//         Cell* c)
//     {
//         p.assignCell(c);
//     }

//     // POINT J

//     void admit_prisoner(
//         Prisoner& p,
//         Block* b)
//     {
//         p.assignBlock(b);

//         ofstream out(
//             "prisoners.txt",
//             ios::app);

//         if(out)
//         {
//             out<<"Prisoner ID: "
//                <<p.getID()
//                <<endl;

//             out<<"Name: "
//                <<p.getName()
//                <<endl;

//             out<<"------------------"
//                <<endl;
//         }

//         out.close();
//     }
// };

// //================ AUDITOR =================

// class Auditor
// {
// public:

//     void viewTotalPrisoners()
//     {
//         cout<<"Total Prisoners = "
//             <<Prisoner::getTotalPrisoners()
//             <<endl;
//     }
// };

// //================ GLOBAL FUNCTION =================

// void compare_guards(
//     Staff& s1,
//     Staff& s2)
// {
//     if(s1.getExperience() >
//        s2.getExperience())
//     {
//         cout<<"More Experienced:"<<endl;
//         s1.show_details();
//     }
//     else if(s2.getExperience() >
//             s1.getExperience())
//     {
//         cout<<"More Experienced:"<<endl;
//         s2.show_details();
//     }
// }

// //================ MAIN =================

// int main()
// {
//     Block b1(50,20,100000);

//     PrisonGuard g1(
//         "Ali",
//         50000,
//         "Karachi",
//         8);

//     PrisonGuard g2(
//         "Ahmed",
//         60000,
//         "Lahore",
//         12);

//     AdministrativePersonnel a1(
//         "Sara",
//         70000,
//         "Karachi",
//         10,
//         "Healthcare");

//     Superintendent sup("Kashif");

//     sup.assignGuardToBlock(g1,&b1);

//     Prisoner p1(
//         "Bilal",
//         30,
//         "Karachi",
//         "Theft",
//         "4 Years");

//     sup.admit_prisoner(
//         p1,
//         &b1);

//     Auditor aud;
//     aud.viewTotalPrisoners();

//     compare_guards(g1,g2);

//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Cybernode{
//     virtual void scanNetwork() = 0;
//     virtual void deployCountermeasure() = 0;
//     virtual void exportLogs() = 0;
// };
// class Defensenode:public Cybernode{
//     void scanNetwork(){}
//     void deployCountermeasure(){}
//     void exportLogs(){}
// };
// class ThreatDataModule{
//     int threatID;
//     string sourceIP;
//     int severityLevel;
//     char signature[10];
//     bool isFlagged;
// public:
//     ThreatDataModule(/*bla bla bla*/,char arr[10]){
//         strcpy(signature,arr);
//         for(int i=0;arr[i]!='\0';i++){
//             signature[i]=signature[i]+3;
//         }
//     }
//     void display(bool decrypt){
//         /*display*/
//         for(int i=0;arr[i]!='\0';i++){
//             cout<<char(signature[i]-3);
//         }
//     }
//     void markFlag(){isFlagged=1;}
// };
// int main(){

// }
// #include<iostream>
// using namespace std;

// template <class T>
// class QuantumAsset {
//     int assetID;
//     T assetValue;
//     T volatility;
//     int riskScore;

// public:
//     // Parameterized constructor with validation
//     QuantumAsset(int id, T value, T vol, int risk) {
//         assetID = id;
//         assetValue = value;
//         riskScore = risk;

//         if (vol > 0)
//             volatility = vol;
//         else
//             volatility = 1; // fallback (FAST-safe logic)
//     }

//     // operator >
//     bool operator>(const QuantumAsset<T>& a) {
//         return riskScore > a.riskScore;
//     }

//     // operator +
//     QuantumAsset<T> operator+(const QuantumAsset<T>& a) {
//         QuantumAsset<T> temp(assetID,
//                             assetValue + a.assetValue,
//                             (volatility + a.volatility) / 2,
//                             riskScore + a.riskScore);
//         return temp;
//     }

//     // friend class for engine access (optional FAST style)
//     template<class U>
//     friend class AssetEngine;

//     void display() {
//         cout << "Asset ID: " << assetID << endl;
//         cout << "Value: " << assetValue << endl;
//         cout << "Volatility: " << volatility << endl;
//         cout << "Risk Score: " << riskScore << endl;
//         cout << "----------------------" << endl;
//     }
// };

// // ---------------- ENGINE ----------------

// template <class T>
// class AssetEngine {
// public:

//     T predictValue(QuantumAsset<T> a, QuantumAsset<T> b) {
//         return (a.assetValue + b.assetValue) / 2;
//     }

//     QuantumAsset<T> compareRisk(QuantumAsset<T> a, QuantumAsset<T> b) {
//         return (a.riskScore > b.riskScore) ? a : b;
//     }

//     void printAsset(QuantumAsset<T> a) {
//         a.display();
//     }
// };

// // ---------------- MAIN ----------------

// int main() {

//     QuantumAsset<double> a1(1, 100.5, 2.0, 7);
//     QuantumAsset<double> a2(2, 200.0, 3.0, 9);

//     AssetEngine<double> engine;

//     cout << "Asset 1:\n";
//     engine.printAsset(a1);

//     cout << "Asset 2:\n";
//     engine.printAsset(a2);

//     cout << "Higher Risk Asset:\n";
//     engine.printAsset(engine.compareRisk(a1, a2));

//     cout << "Predicted Value: "
//          << engine.predictValue(a1, a2)
//          << endl;

//     QuantumAsset<double> merged = a1 + a2;

//     cout << "Merged Asset:\n";
//     merged.display();

//     if (a1 > a2)
//         cout << "Asset 1 has higher risk\n";
//     else
//         cout << "Asset 2 has higher risk\n";

//     return 0;
// }
// #include<iostream>
// using namespace std;

// // ---------------- BASE CLASS ----------------
// class DefensiveNode {

// protected:
//     int nodeID;
//     char regionCode[10];
//     double bandwidthCapacity;
//     double currentTrafficLoad;

// public:

//     friend class CentralCommandMetrics;

//     DefensiveNode(int id, const char* region, double capacity, double load) {
//         nodeID = id;

//         for (int i = 0; i < 10; i++)
//             regionCode[i] = region[i];

//         bandwidthCapacity = capacity;

//         if (load < 0)
//             currentTrafficLoad = 0;
//         else if (load > capacity)
//             currentTrafficLoad = capacity;
//         else
//             currentTrafficLoad = load;
//     }

//     virtual bool routeTraffic(double incomingLoad) = 0;

//     virtual void displayStatus() const {
//         cout << "Node ID: " << nodeID << endl;
//         cout << "Region: " << regionCode << endl;

//         double saturation = (currentTrafficLoad / bandwidthCapacity) * 100;
//         cout << "Saturation: " << saturation << "%" << endl;
//     }
// };

// // ---------------- QUANTUM SCRUBBER NODE ----------------
// class QuantumScrubberNode : public DefensiveNode {

// protected:
//     int cleanCyclesPassed;
//     double filtrationEfficiency;

// public:

//     QuantumScrubberNode(int id, const char* region, double cap,
//                         double load, int cycles, double efficiency)
//         : DefensiveNode(id, region, cap, load) {

//         cleanCyclesPassed = cycles;
//         filtrationEfficiency = efficiency;
//     }

//     bool routeTraffic(double incomingLoad) override {

//         double effectiveLoad = incomingLoad * (1.0 - filtrationEfficiency);
//         double newLoad = currentTrafficLoad + effectiveLoad;

//         if (newLoad <= bandwidthCapacity) {
//             currentTrafficLoad = newLoad;
//             cleanCyclesPassed++;
//             return true;
//         }
//         else {
//             cout << "Node Saturation Warning" << endl;
//             return false;
//         }
//     }

//     void displayStatus() const override {
//         DefensiveNode::displayStatus();
//         cout << "Clean Cycles: " << cleanCyclesPassed << endl;
//         cout << "Efficiency: " << filtrationEfficiency << endl;
//     }
// };

// // ---------------- DEEP INSPECTION NODE ----------------
// class DeepInspectionNode : public QuantumScrubberNode {

//     double deepInspectionThrottlingFactor;

// public:

//     DeepInspectionNode(int id, const char* region, double cap,
//                        double load, int cycles, double efficiency,
//                        double throttle)
//         : QuantumScrubberNode(id, region, cap, load, cycles, efficiency) {

//         deepInspectionThrottlingFactor = throttle;
//     }

//     bool routeTraffic(double incomingLoad) override {

//         if (incomingLoad > deepInspectionThrottlingFactor * bandwidthCapacity) {
//             cout << "Threat Throttled: Payload too large for deep inspection!" << endl;
//             return false;
//         }

//         if (QuantumScrubberNode::routeTraffic(incomingLoad)) {
//             currentTrafficLoad += 2.5; // safety overhead
//             return true;
//         }

//         return false;
//     }
// };

// // ---------------- FRIEND CLASS ----------------
// class CentralCommandMetrics {

// public:

//     void rebalanceLoad(DefensiveNode& a, DefensiveNode& b) {

//         double totalLoad = a.currentTrafficLoad + b.currentTrafficLoad;
//         double half = totalLoad / 2;

//         double newLoadA = half;
//         double newLoadB = half;

//         if (newLoadA > a.bandwidthCapacity || newLoadB > b.bandwidthCapacity) {
//             cout << "Rebalancing aborted: Destructive load mismatch" << endl;
//             return;
//         }

//         a.currentTrafficLoad = newLoadA;
//         b.currentTrafficLoad = newLoadB;
//     }
// };

// #include<iostream>
// using namespace std;
// const int ROWS=2;
// const int COLS=2;
// template<class T,COL,ROWS,int>
// class DataMatrix{
//     T grid[ROWS][COLS];
// public:
//     DataMatrix()<int>{ }
//     DataMatrix()<float>{}
//     DataMatrix(T arr[ROWS][COLS]){ for(int i=0;i<ROWS;i++){ for(int j=0;j<COLS;j++){grid[i][j]=arr[i][j];}}}
//     DataMatrix<T> operator+(DataMatrix<T> a){
//         DataMatrix<T> temp;
//         for(int i=0;i<ROWS;i++){ 
//             for(int j=0;j<COLS;j++){
//                 temp.grid[i][j]=grid[i][j]+a.grid[i][j];
//             }
//         } return DataMatrix<T>;
//     }
//     DataMatrix<T> operator*(DataMatrix<T, R1,C1> a){
//         DataMatrix<T,ROWS,C1> temp={0};
//         if(C==R1){
//         for(int i=0;i<ROWS;i++){ 
//             for(int j=0;j<C1;j++){
//                 for(int k=0;k<COLs;k++){
//                     temp.grid[i][j]+=grid[i][k]*a.grid[k][i];
//                 }
//             }
//         } }return DataMatrix<T,ROWS,C1>;
//     }
//     friend DataMatrix<T> operator*(DataMatrix<T> a,DataMatrix<T> b);

// };
// DataMatrix<T> operator*(DataMatrix<T> a,DataMatrix<T> b){
//     DataMatrix<T> temp;
//         for(int i=0;i<ROWS;i++){ 
//             for(int j=0;j<COLS;j++){
//                 temp.grid[i][j]=b.grid[i][j]*a.grid[i][j];
//             }
//         } return DataMatrix<T>;
// }
// class PortfolioAnalyzer{
// public:
//     template <typename T, int R, int C> 
//     double aggregateGrossValue(const DataMatrix<T,R,C>& matrix){ double sum=0.0;
//         for(int i=0;i<ROWS;i++){
//             for(int j=0;j<COLS;j++){
//                 sum+=matrix.grid[i][j];
//             }
//         } return sum;
//     }
// };
// int main(){}

// #include<iostream>
// using namespace std;
// class SignalLostError:public exception{
// public:
//     const char* what() const noexcept override{
//         return "oribtal connection severed";
//     }
// };
// class Satellite{
//     string designation;
// public:
//     virtual void checkSignal(float x)=0;
// };
// class RelaySatellite:public Satellite{
// public:
//     void checkSignal(float x){
//         if(x<10.0)throw SignalLostError();
//     }
// };
// class SpySatellite:public Satellite{
// public:
//     void checkSignal(float x){
        
//     }
// };
// class  GroundStationEntity{
// public:
//     void scanSky(Satellite* arr,int size){
//         for(int i=0;i<size;i++){
//           try { arr[i]->checkSignal()}
//           catch( SignalLostError& e){ cout<<e.what();}
//         }
//     }
// };
// int main(){}

// #include<iostream>
// using namespace std;
// class RecoveryException: public exception{
//     int sourceRecordID;
//     char errorLog[100];
// public:
//     RecoveryException(char e[100]){ strcpy(errorLog,e);}
//     const char* what() const noexcept override{
//         char str[200]=char(sourceRecordID)+errorLog[100];
//         return str;
//     }
// };
// class CorruptRecordException:public RecoveryException{

// };
// int main(){

// }

// #include<iostream>
// using namespace std;
// class ArchiveCreationException:public exception{
// public:
//     const char* what() const noexcept override{
//         return "Unable to create transaction archive!";
//     }
// };
// class FraudNotFoundException:public exception{
// public:
//     const char* what() const noexcept override{
//         return "No fraudulent transactions detected.";
//     }
// };
// class NoAuditUpdatesException:public exception{
// public:
//     const char* what() const noexcept override{
//         return "No records modified.";
//     }
// };
// class TransactionRecord{
//     int transactionID;
//     char accountNumber[20];
//     double amount ;
//     char transactionType[15];
//     bool isFlagged;
// public:
//     TransactionRecord(){}
//     void input(){}
//     void display(){}
//     void markFlagged(){ isFlagged=1;}
//     bool isSuspicious(){ return (amount>500000)}
//     void write(){ TransactionRecord t;
//         ofstream out("transactions.dat",ios::app);
//         if(out){
//             out.write((char*)&t,sizeof(t));
//         }
//         else{ throw ArchiveCreationException();}
//         out.close();
//     }
//     void read(){ TransactionRecord t;TransactionRecord v;
//         ifstream in("transactions.dat");
//         if(in){
//             while(in.read((char*)&t,sizeof(t))){
//                 if(t.isSuspicious()){
//                     ofstream out("fraud_report.dat",ios::app);
//                     if(out){
//                         out.write((char*)&t,sizeof(t));
//                     }
//                     out.close();
//                 }
//                 else{ throw FraudNotFoundException();}
//             }

//         }
//         else{ throw ArchiveCreationException();}
//         in.close();
//         ifstream in("transactions.dat");
//         if(in){
//             while(in.read((char*)&t,sizeof(t))){
//                 if(t.isSuspicious()){
//                     ofstream out("transaction.dat",ios::app);
//                     if(out){ 
//                         long pos=out.tellp();
//                         pos=pos-sizeof(t);
//                         out.seekp(pos); t.markFlagged();
//                         out.write((char*)&t,sizeof(t));
//                     }
//                     out.close();
//                 }
//                 else throw NoAuditUpdatesException();
//             }
//         }in.close();
//     }
// };
// int main(){

// }

// #include<iostream>
// using namespace std;
// class SurveillanceUnit{
// protected:
//    int unitID;
//    string unitName;
// public:
//     virtual int scanSector(int grid[20][20]) = 0;
//     int operator+(SurveillanceUnit& s){
//         return s.scanSector();
//     }
// };
// class RadarUnit:public SurveillanceUnit{ 
// public:
//     int scanSector(int grid[20][20]){ int count=0;
//         for(int i=0;i<20;i++){
//             for(int j=0;j<20;j++){
//                 if(arr[i][j]==2)count++;
//             }
//         } return count;
//     }
// };
// class JammerUnit:public SurveillanceUnit{
// public:
//     int scanSector(int grid[20][20]){ int count=0;
//         for(int i=0;i<20;i++){
//             for(int j=0;j<20;j++){
//                 if(arr[i][j]==3)count++;
//             }
//         } return count;
//     }
// };
// class ReconUnit:public SurveillanceUnit{
// public:
//     int scanSector(int grid[20][20]){ int count=0;
//         for(int i=0;i<20;i++){
//             for(int j=0;j<20;j++){
//                 if(arr[i][j]==1){ if(arr[i][j+1]==2||arr[i][j-1]==2||arr[i+1][j]==2||arr[i-1][j]==2)count++;}
//             }
//         } return count;
//     }
// };
// int main(){

// }
#include<iostream>
#include<string>
using namespace std;

class FleetManager;

//================ ABSTRACT BASE CLASS =================

class Drone
{
protected:
    int droneID;
    string modelName;
    int batteryLevel;
    string currentLocation;

    static int nextID;

public:

    Drone(string m,int b,string loc)
        : modelName(m), batteryLevel(b), currentLocation(loc)
    {
        droneID = nextID++;
    }

    virtual ~Drone(){}

    virtual void deliverPackage() = 0;

    virtual void displayDetails()
    {
        cout<<"ID: "<<droneID
            <<"\nModel: "<<modelName
            <<"\nBattery: "<<batteryLevel
            <<"\nLocation: "<<currentLocation<<endl;
    }

    int getBattery() const
    {
        return batteryLevel;
    }

    bool operator<(const Drone& d)
    {
        return batteryLevel < d.batteryLevel;
    }

    bool operator>(const Drone& d)
    {
        return batteryLevel > d.batteryLevel;
    }

    bool operator==(const Drone& d)
    {
        return batteryLevel == d.batteryLevel;
    }

    friend void compareDrones(Drone&,Drone&);
    friend class FleetManager;
};

int Drone::nextID = 1000;

//================ DELIVERY DRONE =================

class DeliveryDrone : public Drone
{
    float payloadCapacity;

public:

    DeliveryDrone(string m,int b,string loc,float p)
        : Drone(m,b,loc)
    {
        payloadCapacity = p;
    }

    void deliverPackage() override
    {
        cout<<"Delivery Drone delivering package.\n";
    }

    void displayDetails() override
    {
        Drone::displayDetails();
        cout<<"Payload Capacity: "<<payloadCapacity<<"\n\n";
    }
};

//================ MEDICAL DRONE =================

class MedicalDrone : public Drone
{
    int emergencyLevel;

public:

    MedicalDrone(string m,int b,string loc,int e)
        : Drone(m,b,loc)
    {
        emergencyLevel = e;
    }

    void deliverPackage() override
    {
        cout<<"Medical Drone delivering emergency supplies.\n";
    }

    void displayDetails() override
    {
        Drone::displayDetails();
        cout<<"Emergency Level: "<<emergencyLevel<<"\n\n";
    }
};

//================ SURVEILLANCE DRONE =================

class SurveillanceDrone : public Drone
{
    float cameraRange;

public:

    SurveillanceDrone(string m,int b,string loc,float r)
        : Drone(m,b,loc)
    {
        cameraRange = r;
    }

    void deliverPackage() override
    {
        cout<<"Surveillance Drone monitoring area.\n";
    }

    void displayDetails() override
    {
        Drone::displayDetails();
        cout<<"Camera Range: "<<cameraRange<<"\n\n";
    }
};

//================ FRIEND FUNCTION =================

void compareDrones(Drone& a, Drone& b)
{
    if(a > b)
    {
        cout<<"Drone A has more battery.\n";
    }
    else if(b > a)
    {
        cout<<"Drone B has more battery.\n";
    }
    else
    {
        cout<<"Both drones have equal battery.\n";
    }
}

//================ TEMPLATE CLASS =================

template<class T>
class DroneFleet
{
    T* arr;
    int count;

public:

    DroneFleet()
    {
        arr = new T[10];
        count = 0;
    }

    ~DroneFleet()
    {
        delete[] arr;
    }

    void addDrone(const T& d)
    {
        if(count < 10)
        {
            arr[count++] = d;
        }
    }

    void removeDrone(const T& d)
    {
        int index = -1;

        for(int i=0;i<count;i++)
        {
            if(arr[i] == d)
            {
                index = i;
                break;
            }
        }

        if(index != -1)
        {
            for(int i=index;i<count-1;i++)
            {
                arr[i] = arr[i+1];
            }

            count--;
        }
    }

    bool contains(const T& d)
    {
        for(int i=0;i<count;i++)
        {
            if(arr[i] == d)
            {
                return true;
            }
        }

        return false;
    }
};

//================ FRIEND CLASS =================

class FleetManager
{
public:

    void assignLocation(Drone& d,string newLoc)
    {
        d.currentLocation = newLoc;
    }

    void changeBattery(Drone& d,int battery)
    {
        d.batteryLevel = battery;
    }

    void displayFleetReport(Drone* fleet[],int size)
    {
        cout<<"\n===== FLEET REPORT =====\n";

        for(int i=0;i<size;i++)
        {
            fleet[i]->displayDetails();
        }
    }
};

//================ COMPOSITION =================

class Mission
{
    string missionName;
    Drone* assignedDrone;

public:

    Mission(string name, Drone* d)
    {
        missionName = name;
        assignedDrone = d;
    }

    void startMission()
    {
        cout<<"\nMission: "<<missionName<<endl;
        assignedDrone->deliverPackage();
    }
};

//================ GENERIC FUNCTION =================

template<typename T>
void printInfo(T value)
{
    cout<<value<<endl;
}

//================ MAIN =================

int main()
{
    Drone* fleet[3];

    fleet[0] =
        new DeliveryDrone("D100",90,"Karachi",50);

    fleet[1] =
        new MedicalDrone("M200",75,"Lahore",5);

    fleet[2] =
        new SurveillanceDrone("S300",85,"Islamabad",120);

    cout<<"=== POLYMORPHISM ===\n";

    for(int i=0;i<3;i++)
    {
        fleet[i]->deliverPackage();
        fleet[i]->displayDetails();
    }

    compareDrones(*fleet[0],*fleet[1]);

    FleetManager manager;

    manager.assignLocation(*fleet[0],"Multan");

    manager.changeBattery(*fleet[1],95);

    manager.displayFleetReport(fleet,3);

    Mission m1("Medicine Delivery",fleet[1]);

    m1.startMission();

    printInfo(100);
    printInfo("FAST OOP");

    for(int i=0;i<3;i++)
    {
        delete fleet[i];
    }

    return 0;
}