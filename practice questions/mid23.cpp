// #include<iostream>
// #include<string>
// using namespace std;
// class Robot{
//     int x;
//     int y;
// public:
//     Robot(){};
//     Robot(int x,int y){ this->x=x; this->y=y;}
//     Robot(const Robot& r){
//         x=r.y;
//         y=r.x;
//     }
//     void moveleft(int d){x-=d;}
//     void moveright(int d){x+=d;}
//     void moveforward(int d){y+=d;}
//     void movebackward(int d){y-=d;}
//     void commands(string act,int d){
//         int size=act.size();
//         for(int i=0;i<size;i++){
//             if(act[i]=='L'){moveleft(d);}
//             if(act[i]=='R'){moveright(d);}
//             if(act[i]=='F'){moveforward(d);}
//             if(act[i]=='B'){movebackward(d);}
//         }
//     }
// };
// int main(){

// }
// #include <iostream>
// #include <string>
// using namespace std;

// class Robot {
// private:
//     int x;
//     int y;

// public:
//     // Default constructor
//     Robot(int x = 0, int y = 0) {
//         this->x = x;
//         this->y = y;
//     }

//     // Copy constructor — creates opposite image
//     Robot(const Robot& r) {
//         x = r.y;
//         y = r.x;
//     }

//     // Accessor functions
//     int getX() { return x; }
//     int getY() { return y; }

//     // Mutator functions
//     void setX(int val) { x = val; }
//     void setY(int val) { y = val; }

//     // Movement functions
//     void moveLeft(int d) { x -= d; }
//     void moveRight(int d) { x += d; }
//     void moveForward(int d) { y += d; }
//     void moveBackward(int d) { y -= d; }

//     // Commands function
//     void commands(string act, int d) {
//         for (size_t i = 0; i < act.size(); i++) {
//             char c = act[i];
//             if (c == 'L') moveLeft(d);
//             else if (c == 'R') moveRight(d);
//             else if (c == 'F') moveForward(d);
//             else if (c == 'B') moveBackward(d);
//         }
//     }

//     // Display current position
//     void displayPosition() {
//         cout << "Robot position: (" << x << ", " << y << ")" << endl;
//     }
// };

// int main() {
//     // Create robot at default position
//     Robot r1;  // x=0, y=0

//     // Move robot with command string
//     r1.commands("RRLF", 2); // R,R,L,F each moves 2 units
//     r1.displayPosition();   // Expected: (2,2)

//     // Copy robot using copy constructor (opposite image)
//     Robot r2 = r1;
//     r2.displayPosition();   // x and y swapped

//     return 0;
// }


// #include<iostream>
// using namespace std;
// class Staff{
//     int staffID;
//     float salary;
//     string employeeType;
//     static int totalSalaries;
// public:
// Staff(int id,float sal,string type):staffID(id),salary(sal),employeeType(type){}
//     double Animate(double currentCost){ return currentCost+=10000;}
//     void TrackProject(double currentCost){ if(currentCost>2000000)cout<<"Warning that cost is exceeding budget"<<endl;}
// };
// int Staff::totalSalaries=0;
// class MovieProject{
//     int movieID;
//     string title;
//     static int totalBudget;
//     double currentCost;
//     Staff lead;
//     Staff animator;
// public:
//     MovieProject(){}
//     MovieProject(int id,string t,int b,int c,int leadid,float lsalary,int aid,float asalary):movieID(id),title(t),totalBudget(b),currentCost(c),lead(leadid,lsalary,"ProjectLead"),animator(aid,asalary,"ChiefAnimator"){}
//     void Production(){
//         currentCost=animator.Animate(currentCost);
//         lead.TrackProject(currentCost);
//         cout<<"Task in production"<<endl;
//     }
// };
// int MovieProject::totalBudget=0;

// int main(){

// }

#include <iostream>
#include <string>
using namespace std;

class Staff {
    int staffID;
    double salary;
    string employeeType;   // "ProjectLead" or "ChiefAnimator"
    static double totalSalaries;

public:
    Staff() {}

    Staff(int id, double sal, string type)
        : staffID(id), salary(sal), employeeType(type)
    {
        totalSalaries += salary;   // update global salary
    }

    double Animate(double currentCost) {
        if (employeeType == "ChiefAnimator") {
            currentCost += 10000;
        }
        return currentCost;
    }

    void TrackProject(double currentCost) {
        if (employeeType == "ProjectLead") {
            if (currentCost > 200000) {
                cout << "Warning: Cost is exceeding budget!" << endl;
            }
        }
    }

    static double getTotalSalaries() {
        return totalSalaries;
    }
};

double Staff::totalSalaries = 0;


class MovieProject {
    int movieID;
    string title;
    double totalBudget;
    double currentCost;

    Staff lead;       // Project Lead
    Staff animator;   // Chief Animator

    static double allMoviesBudget;

public:
    MovieProject(int id, string t, double budget, double cost,
                 int leadID, double leadSal,
                 int animID, double animSal)
        : movieID(id),
          title(t),
          totalBudget(budget),
          currentCost(cost),
          lead(leadID, leadSal, "ProjectLead"),
          animator(animID, animSal, "ChiefAnimator")
    {
        allMoviesBudget += totalBudget;   // update global movie budget
    }

    void Production() {
        currentCost = animator.Animate(currentCost);
        lead.TrackProject(currentCost);

        cout << "Movie \"" << title << "\" is in production." << endl;
        cout << "Current Cost: " << currentCost << endl;
    }

    static double getAllMoviesBudget() {
        return allMoviesBudget;
    }
};

double MovieProject::allMoviesBudget = 0;


int main() {

    MovieProject m1(1, "Dragon Quest", 300000, 150000,
                    101, 50000,
                    201, 40000);

    m1.Production();

    cout << "\nTotal Salaries of Staff: "
         << Staff::getTotalSalaries() << endl;

    cout << "Total Budget of All Movies: "
         << MovieProject::getAllMoviesBudget() << endl;

    return 0;
}