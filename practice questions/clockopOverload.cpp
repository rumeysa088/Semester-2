// #include<iostream>
// using namespace std;

// class Clock {
//     int hours, minutes, seconds;

// public:
//     Clock() {}
//     Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

//     void display() {
//         cout << "\n" << hours << ":" << minutes << ":" << seconds << endl;
//     }

//     // Addition operator
//     Clock operator+(const Clock& c) {
//         Clock temp;

//         temp.seconds = seconds + c.seconds;
//         temp.minutes = minutes + c.minutes + temp.seconds / 60;
//         temp.seconds %= 60;

//         temp.hours = hours + c.hours + temp.minutes / 60;
//         temp.minutes %= 60;

//         temp.hours %= 24;

//         return temp;
//     }

//     // Proper > operator
//     bool operator>(const Clock& c) {
//         if (hours != c.hours) return hours > c.hours;
//         if (minutes != c.minutes) return minutes > c.minutes;
//         return seconds > c.seconds;
//     }
// };

// int main() {
//     Clock c1(21,30,5);
//     Clock c2(12,50,0);

//     Clock c3 = c1 + c2;
//     c3.display();

//     if (c2 > c1)
//         cout << "\nc2 is greater\n";
//     else
//         cout << "\nc1 is greater\n";
// }
#include <iostream>
using namespace std;

class Meal {
private:
    string entreeName;
    int calorieCount;

public:
    Meal(string name = "Unknown", int calories = 0) {
        entreeName = name;
        calorieCount = calories;
    }
    void display() {
        cout << "Meal: " << entreeName 
             << ", Calories: " << calorieCount << endl;
    }
    Meal operator +(Meal& obj){
        Meal temp;
        temp.entreeName="Daily Total";
        temp.calorieCount=calorieCount+obj.calorieCount;
        return temp;
    }
};

int main() {
    Meal breakfast("Pancakes",200); Meal lunch("Biryani",300); Meal dinner("Chicken Roast",250);
    Meal m=breakfast+lunch+dinner;
    m.display();
    return 0;
}