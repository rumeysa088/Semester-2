#include <iostream>
using namespace std;
class Notification {
protected:
    string recipient;
public:
    Notification(string res) : recipient(res) {}
    virtual void sendNotification(string message) = 0;
    virtual ~Notification() {} 
};
class SMSNotification : public Notification {
public:
    SMSNotification(string res) : Notification(res) {}
    void sendNotification(string message) override {
        cout << "SMS Notification" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: " << message << endl;
        cout << "Status: Sent Successfully" << endl;
    }
};
class EmailNotification : public Notification {
public:
    EmailNotification(string res) : Notification(res) {}
    void sendNotification(string message) override {
        cout << "\nEmail Notification" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: " << message << endl;
        cout << "Status: Sent Successfully" << endl;
    }
};
class PushNotification : public Notification {
public:
    PushNotification(string res) : Notification(res) {}
    void sendNotification(string message) override {
        cout << "\nPush Notification" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: " << message << endl;
        cout << "Status: Sent Successfully" << endl;
    }
};
int main() {
    SMSNotification sms("03001234567");
    sms.sendNotification("Your OTP is 1234");
    return 0;
}