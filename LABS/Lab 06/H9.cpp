#include<iostream>
using namespace std;
class Device {
public:
    void showDevice() { cout << "Device" << endl; }
};
class Camera : virtual public Device {
public:
    void takePhoto() { cout << "Taking Photo" << endl; }
};
class Phone : virtual public Device {
public:
    void makeCall() { cout << "Making Call" << endl; }
};
class SmartPhone : public Camera, public Phone {
public:
    void browseInternet() { cout << "Browsing Internet" << endl; }
};
int main() {
    SmartPhone sp;
    sp.showDevice();     // from Device
    sp.takePhoto();      // from Camera
    sp.makeCall();       // from Phone
    sp.browseInternet(); // own function
    return 0;
}