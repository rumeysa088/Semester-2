#include <iostream>
using namespace std;
template <typename T>
class GenericArray {
private:
    T arr[100]; 
    int size;   
public:
    GenericArray() {
        size = 0;}
    void add(T val) {
        if (size < 100) {
            arr[size] = val;
            size++;}
    }
    void display() {
        cout << "Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";}
        cout << endl;}
    T findMax() {
        T maxVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i]; }
        }
        return maxVal; }
};
int main() {
    GenericArray<int> obj;
    obj.add(10);
    obj.add(50);
    obj.add(30);
    obj.display();
    cout << "Max value: " << obj.findMax() << endl;
    return 0;
}