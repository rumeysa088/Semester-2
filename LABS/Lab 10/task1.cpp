#include <iostream>
using namespace std;
template <typename T>
T getSum(T a, T b) {
    return a + b;
}
template <typename T>
T getDifference(T a, T b) {
    return a - b;
}
template <typename T>
T getProduct(T a, T b) {
    return a * b;
}
int main() {
    double num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Sum: " << getSum(num1, num2) << endl;
    cout << "Difference: " << getDifference(num1, num2) << endl;
    cout << "Product: " << getProduct(num1, num2) << endl;

    return 0;
}
