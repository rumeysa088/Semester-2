#include<iostream>
using namespace std;
template <typename T>

T getMin(T a,T b){ if(a<b)return a; else{return b;}}
int main(){

    cout << "Minimum (Integer): " << getMin(10, 20) << endl;
    cout << "Minimum (Float): " << getMin(5.5, 2.3) << endl;
    cout << "Minimum (Char): " << getMin('A', 'Z') << endl;
    return 0;
}