#include<iostream> 
#include<string>
#include "User.h"
#include "Vehicle.h"
#include "Payment.h"
using namespace std;
class Buyer;
class Seller;
class Listing;
// Car IS-A Vehicle: inherits all vehicle properties; adds door count
class Car : public Vehicle {
private:
    int numberOfDoors;
public:
    Car() {}

    Car(string t,string b,string m,int id,int p,int y,int mil,
        string c,string f,int doors)
        : Vehicle(t,b,m,id,p,y,mil,c,f), numberOfDoors(doors) {}
    void display() const override {
        cout << "Car: " << getBrand() << " " << getModel()
             << " (" << getYear() << ") Price: " << getPrice()
             << " Mileage: " << getMileage()
             << " Doors: " <<numberOfDoors<< endl;
    }
};
class LuxuryCar : public Car {
private:
    bool hasSunroof;
public:
    LuxuryCar(string t,string b,string m,int id,int p,int y,int mil,
              string c,string f,int doors,bool sunroof)
        : Car(t,b,m,id,p,y,mil,c,f,doors), hasSunroof(sunroof) {}
    void display() const override {
        cout << "Luxury Car: " << getBrand() << " " << getModel()
             << " Sunroof: " << (hasSunroof ? "Yes" : "No") << endl;}
};
class UsedCar : public Car {
public:
    UsedCar(string t,string b,string m,int id,int p,int y,int mil,
            string c,string f,int doors)
        : Car(t,b,m,id,p,y,mil,c,f,doors) {}

    void display() const override {
        cout << "Used Car: " << getBrand() << " " << getModel() << endl; }
};
// Bike IS-A Vehicle: inherits all vehicle properties; adds engine capacity
class Bike : public Vehicle {
private:
    int engineCapacity;
public:
    Bike() {}
    Bike(string t,string b,string m,int id,int p,int y,int mil,
         string c,string f,int engine)
        : Vehicle(t,b,m,id,p,y,mil,c,f), engineCapacity(engine) {}
    void display() const override {
        cout << "Bike: " << getBrand() << " " << getModel()
             << " (" << getYear() << ") Price: " << getPrice()
             << " Mileage: " << getMileage()
             << " Engine: " << engineCapacity << "cc" << endl; }
};
class ElectricBike : public Bike {
public:
    ElectricBike(string t,string b,string m,int id,int p,int y,int mil,
                 string c,string f,int engine)
        : Bike(t,b,m,id,p,y,mil,c,f,engine) {}
    void display() const override {
        cout << "Electric Bike: " << getBrand() << " " << getModel() << endl; }
};
class Brand{  //default for array use, parameterized for initialization
private:
    string brandName;
    string country;
    const int yearFounded;
    string popularModels[5]; 
    int numberOfCarsListed;
public:
    Brand():yearFounded(0), numberOfCarsListed(0){}
    Brand(string b,string c,int y,int num):brandName(b),country(c),yearFounded(y),numberOfCarsListed(num){}
    string getBrandName() const{ return brandName; }
    string getCountry() const{ return country; }
    void display() const{ cout<<brandName << " from " <<country << " founded in " <<yearFounded <<"\n"; }
    void incrementListed() { numberOfCarsListed++; }
    void decrementListed() { numberOfCarsListed--; }
    bool isPopular() const { return numberOfCarsListed > 5; }
    void addPopularModel(string model) {
        for(int i=0;i<5;i++) {
            if(popularModels[i] == "") {
                popularModels[i] = model;
                break;
            }
        }
    }
    void showPopularModels()const {
        cout << "Popular models of " << brandName << ":\n";
        for(int i=0;i<5;i++)
            if(popularModels[i] != "")
                cout << popularModels[i] << endl;
    }
};
// Seller IS-A User: inherits name, contact, address; adds vehicle listings and ratings
class Seller:public User{ // default constructor for array/pointer use, parameterized for initialization
private:
    Vehicle* cars[10]; //seller can have up to 10 cars(composition)
    int carCount;
    string ratings;
public:
    Seller():carCount(0) {}
    Seller(string n,string ci,string a,string r): User(n,ci,a), ratings(r), carCount(0) {}
    string getRatings() const{ return ratings; }
    int getCarCount() const{ return carCount; }
    void setRatings(string r) { ratings = r; }
    bool hasAvailableCars() const { return carCount > 0; }
    void addCar(Vehicle* v) {
        if(carCount < 10) {
            cars[carCount++]= v;
            cout <<"Car added to seller "<< name << endl;
        }
    }
    void removeCar(int id) {
    for (int i = 0; i < carCount; i++) {
        if (cars[i]->getID() == id) {
            for (int j = i; j < carCount - 1; j++)
                cars[j] = cars[j + 1];
            carCount--;
            cout << "Car removed from seller " << name << endl;
            break;
        }
    }
}
    void display() const override {
    cout << "Seller: " << name << " Rating: " << ratings << "\n";}
};
class VerifiedSeller : public Seller {
private:
    bool verifiedBadge;

public:
    VerifiedSeller(string n,string ci,string a,string r,bool v)
        : Seller(n,ci,a,r), verifiedBadge(v) {}

    void display() const override {
        cout << "Verified Seller: " << name
             << " Badge: " << (verifiedBadge ? "Yes" : "No") << endl;
    }
};
class Favorites{ //default ctor needed since Buyer has it as a member, parameterized if created alone
private:
    string buyerName;
    Vehicle* favoriteCars[10];
    int favoriteCount;
    const int maxFavorites;
    string dateOfLastUpdate;
public:
    Favorites():maxFavorites(10),favoriteCount(0){}
    Favorites(string bName,string date):buyerName(bName),dateOfLastUpdate(date),favoriteCount(0),maxFavorites(10){}
    int getFavoriteCount()const {return favoriteCount; }
    void addFavorite(Vehicle* v) {
        if(favoriteCount < maxFavorites) {
            favoriteCars[favoriteCount++]=v;
            cout <<"Saved: "<< v->getBrand()<<" " << v->getModel()<< "\n";
        }
    }
    void removeFavorite(int id) {
    for (int i = 0; i < favoriteCount; i++) {
        if (favoriteCars[i]->getID() == id) {
            for (int j = i; j < favoriteCount - 1; j++)
                favoriteCars[j] = favoriteCars[j + 1];
            favoriteCount--;
            return;
        }
    }
    }
    void showFavorites() const {
    for (int i = 0; i < favoriteCount; i++)
        favoriteCars[i]->display();
    }
    void clearFavorites(){ favoriteCount = 0; }
    friend void showBuyerFavorites(const Buyer& b, const Favorites& f);
};
class Message{ //  default needed for messages[20] array, parameterized for actual messages
private:
    Buyer* senderPtr;   //aggregation
    Seller* receiverPtr;  //aggregation
    string content;
    string timestamp;
    bool readStatus;
public:
    Message(){}
     Message(Buyer* s,Seller* r,string c,string t,bool rs):senderPtr(s),receiverPtr(r),content(c),timestamp(t),readStatus(rs){}
     bool isRead() const { return readStatus; }
    void markAsRead() { readStatus = true; }
    void display() const { cout <<"Message: " << content <<" | Read: " << (readStatus ? "Yes" : "No") << "\n"; }
    void updateContent(string c){content = c; }
};
// Buyer IS-A User: inherits contact info; adds favorites and messaging
class Buyer:public User{ //default for array use, parameterized for creating buyers
private:
    Favorites myFavorites;   //composition
    Message messages[20];  //messages from sellers (composition)
    int messageCount;
public:
    Buyer():messageCount(0) {}
    Buyer(string n,string ci,string a): User(n,ci,a), messageCount(0){}
    int getMessageCount()const { return messageCount; }
    void saveFavorite(Vehicle* v) { myFavorites.addFavorite(v); }
    void showFavorites()const { myFavorites.showFavorites(); }
    void sendMessage(string msg) {
        cout << name << " sent: " << msg << "\n"; }
    void sendMessage(string msg, string time) {
        cout << name << " sent at " << time << ": " << msg << "\n"; }
    void showMessages()const { cout << name << "'s messages shown.\n"; }
    void receiveMessage(const Message& m) {
        if(messageCount < 20) {
            messages[messageCount++]=m;
        }
    }
    void deleteMessage(int index) {
        if(index >=0 && index < messageCount) {
            for(int i=index;i<messageCount-1;i++)
                messages[i]=messages[i+1];
            messageCount--;
        }
    }
    const Favorites& getFavorites() const { return myFavorites; }
    void display() const override {
    cout << "Buyer: " << name << endl;}
    friend void showBuyerFavorites(const Buyer& b, const Favorites& f);
    bool operator==(const Buyer& b) const {
    return this->name == b.name;
}
};
class PremiumBuyer : public Buyer {
private:
    int membershipPoints;
public:
    PremiumBuyer(string n,string ci,string a,int points)
        : Buyer(n,ci,a), membershipPoints(points) {}

    void display() const override {
        cout << "Premium Buyer: " << name
             << " Points: " << membershipPoints << endl;
    }
};
void showBuyerFavorites(const Buyer& b, const Favorites& f) {
    cout << b.getName() << "'s Favorite Cars:\n";
    for(int i = 0; i < f.favoriteCount; i++) {
        f.favoriteCars[i]->display();
    }
}
// Admin IS-A User: inherits identity; adds system management capabilities
class Admin:public User{  //default for array use, parameterized for creation, copy needed because adminID is const
private:
    const string adminID;
    string role;
    int pendingListingsCount;
    static int totalUsers; //Made static because it represents  tottal number of users in the marketplace and its not an individual property 
public:
    Admin(){}
    Admin(string n,string id,string ci,string r)
    : User(n,ci,"N/A"), adminID(id), role(r), pendingListingsCount(0){}
    Admin(const Admin& a) : User(a.name, a.contactInfo, "N/A"), adminID(a.adminID), role(a.role), pendingListingsCount(a.pendingListingsCount) {}
    static int getTotalUsers() {return totalUsers;}
   void approveListing(Listing& l)const;
    void incrementPending(){ pendingListingsCount++; }
    void display() const override {
    cout << "Admin: " << name << " Role: " << role << "\n";}
};
int Admin::totalUsers=0;
class Listing{  //default needed for listings[] array, parameterized for actual listings
private:
    string listingID;
    Vehicle* vehiclePtr; //aggregation
    Seller* const sellerPtr;     //aggregation
    string status;     //cd be "Pending","Approved","Sold"
    string postDate;
    int price;
public:
    friend class Admin;
    Listing():vehiclePtr(nullptr), sellerPtr(nullptr), price(0) {}
    Listing(string id,Vehicle* v,Seller* s,string st,string d,int p):listingID(id),vehiclePtr(v),sellerPtr(s),status(st),postDate(d),price(p){}
    string getStatus() const { return status; }
    string getListingID() const { return listingID; }
    Vehicle* getVehicle() const { return vehiclePtr; }
    void setStatus(string s) { status = s; }
    void setPrice(int p) { price = p; }
    Listing& operator=(const Listing& other) {
    if(this != &other) {
        listingID = other.listingID;
        vehiclePtr = other.vehiclePtr;
        status = other.status;
        postDate = other.postDate;
        price = other.price;  
    }
    return *this;
}
    void showListing() const {
        cout << "Listing ID: " << listingID 
             << ", Vehicle Brand: "<< vehiclePtr->getBrand()
            << ", Price: " << price
             << ", Status: "<< status << endl;
    }
    bool isPending() const { return status == "Pending"; }
    bool operator==(const Listing& l) const {
    return this->listingID == l.listingID;}
    Listing operator+(int extra) const {
    Listing temp = *this;
    temp.price += extra;
    return temp;}
    friend void showListingDetails(const Listing& l);
};
void showListingDetails(const Listing& l) {
    cout << "Listing ID: " << l.listingID
         << " Price: " << l.price << endl;
}
void Admin::approveListing(Listing& l) const {
    l.setStatus("Approved");
    cout << l.getListingID() << " approved.\n";
}
class ReviewBase {
public:
    virtual void display() const = 0;
    virtual ~ReviewBase() {}
};
class Reviews:public ReviewBase{  //default for array use, parameterized for creating reviews
private:
    string reviewerName;
    string reviewText;
    int ratingScore; // 1 to 5
    int relatedVehicleID;
    string relatedSellerName;
public:
    Reviews(){}
    Reviews(string rn,string rt,int rs,int vid,string sn):reviewerName(rn),reviewText(rt),ratingScore(rs),relatedVehicleID(vid),relatedSellerName(sn){}
  
    string getReviewerName() const { return reviewerName; }
    int getRatingScore() const { return ratingScore; }
    string getReviewText() const { return reviewText; }
    void setReviewText(string text) { reviewText = text; }
    void display() const { cout << reviewerName << "rated " << ratingScore << "/5: " << reviewText << "\n"; }
    bool isPositive() const { return ratingScore >= 4; }
    void updateRating(int r) { ratingScore = r; }
};
// Payments IS-A Payment: inherits paymentID and amount; adds listing and buyer/seller context
class Payments:public Payment{  //default for array use, parameterized for creating payments
private:
    Listing* listingPtr;
    string buyerName;
    string sellerName;
    string vehicleID;
public:
    Payments(){}
    Payments(string pid,Listing* l,string bn,string sn,string vid,int amt)
    : Payment(pid,amt), listingPtr(l),
      buyerName(bn), sellerName(sn), vehicleID(vid) {}
    string getPaymentID() const { return paymentID; }
    int getAmount() const { return amount; }
    string getBuyerName()const { return buyerName; }
    string getSellerName() const { return sellerName; }
    void display() const { cout <<"Payment " <<paymentID << " Amount: " << amount << "\n"; }
    void processPayment() const override {
    cout << "Processing payment of Rs." << amount << "\n";
}
    bool isValid()const { return amount > 0; }
    void updateAmount(int a) { amount = a; }
    bool operator==(const Payments& p) const {
    return this->paymentID == p.paymentID;}
    Payments operator+(int extra) const {
    Payments temp = *this;
    temp.amount += extra;
    return temp;}
    friend void showPaymentDetails(const Payments& p);
};
class OnlinePayment : public Payments {
private:
    string paymentMethod;
public:
    OnlinePayment(string pid,Listing* l,string bn,string sn,string vid,int amt,string method)
        : Payments(pid,l,bn,sn,vid,amt), paymentMethod(method) {}

    void processPayment() const override {
        cout << "Processing " << paymentMethod
             << " payment of Rs." << getAmount() << endl;
    }
};
void showPaymentDetails(const Payments& p) {
    cout << "Payment ID: " << p.paymentID
         << " Amount: " << p.amount << endl;
}
istream& operator>>(istream& in, Vehicle& v) {
    cout << "Enter Brand Model Price: ";
    in >> v.brand >> v.model >> v.price;
    return in;
}
ostream& operator<<(ostream& out, const Vehicle& v) {
    out << v.getBrand() << " " << v.getModel()
        << " Price: " << v.getPrice();
    return out;
}
int main(){
    Seller seller1("Ahmed","123456","Karachi","5 stars");
    Seller seller2("Ali","654321","Lahore","4 stars");
    Car car1("Sedan","Toyota","Corolla",101,5000000,2020,40000,"Used","Petrol",4);
    Car car2("SUV","Honda","CRV",102,6000000,2022,20000,"New","Petrol",4);
    LuxuryCar lc("Sedan","BMW","7 Series",201,15000000,2023,1000,"New","Petrol",4,true);
    lc.display();
    VerifiedSeller vs("Hassan","999","Karachi","5 stars",true);
    vs.display();
    PremiumBuyer pb("Sara","111","Lahore",500);
    pb.display();
    int maxListing = 5;
    Listing listings[maxListing];
    int listingCount = 0;
    listings[listingCount++] = Listing("L001",&car1,&seller1,"Pending","2026-02-28",car1.getPrice());
    listings[listingCount++] = Listing("L002",&car2,&seller2,"Pending","2026-02-28",car2.getPrice());
    cout << "\n Updating price of L001 \n";
    for(int i = 0; i < listingCount; i++){
        if(listings[i].getListingID()=="L001"){
            listings[i].setPrice(5200000);
            listings[i].setStatus("Approved");
            break;
        }
    }
    OnlinePayment op("P3",&listings[0],"Ali","Ahmed","101",4000000,"Credit Card");
    op.processPayment();
    cout << "\nDeleting listing L002 \n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getListingID()=="L002"){
            for(int j=i;j<listingCount-1;j++)
                listings[j]=listings[j+1];
            listingCount--;
            break;
        }
    }
    cout << "Listings after deletion\n";
    for(int i = 0; i < listingCount; i++)
        listings[i].showListing();
    cout << "\nSearch by Brand: Toyota \n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getVehicle()->getBrand()=="Toyota")
            listings[i].showListing();
    }
    cout << "\nFilter by Model: Civic\n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getVehicle()->getModel()=="Civic")
            listings[i].showListing();
    }
    cout << "\nFilter by Price < 6,000,000\n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getVehicle()->getPrice()<6000000)
            listings[i].showListing();
    }
    cout << "\nFilter by Year >= 2021\n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getVehicle()->getYear()>=2021)
            listings[i].showListing();
    }
    cout << "\nFilter by Mileage < 30000\n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getVehicle()->getMileage()<30000)
            listings[i].showListing();
    }
    Buyer buyer1("Ali","ali@email.com","Karachi");
    cout << "\n--- Buyer Saving Favorites ---\n";
    buyer1.saveFavorite(listings[0].getVehicle());
    buyer1.showFavorites();
    cout << "\n  Buyer Sending Messages\n";
    buyer1.sendMessage("Hi Ahmed, is the Toyota Corolla still available?");
    buyer1.sendMessage("Hi Ali, can I negotiate price for Honda Civic?");
    buyer1.showMessages();
    Admin admin1("SuperAdmin","ADM001","admin@email.com","Manager");
    cout << "\nAdmin Approving Listings \n";
    for(int i=0;i<listingCount;i++){
        if(listings[i].getListingID()=="L001"){
            admin1.approveListing(listings[i]);
        }
    }
    cout << "\nAdmin Removing Listing\n";
    //removing listing
    for(int i = 0; i < listingCount; i++){
        if(listings[i].getListingID() == "L002"){
            cout << "Listing " << listings[i].getListingID() << " removed.\n";
            for(int j = i; j < listingCount-1; j++)
                listings[j] = listings[j+1]; 
            listingCount--;
            break;
        }
    }
        cout << "\n Polymorphism Demo\n";
    for(int i = 0; i < listingCount; i++) {
        listings[i].getVehicle()->display(); // runtime polymorphism
    }
    cout << "\n Overloading Demo\n";
    for(int i = 0; i < listingCount; i++) {
        if(listings[i].getVehicle()->isAffordable(6000000))
            listings[i].showListing();
    }
    // Demonstrate >> operator
    // cin >> car1;
    if (car1 != car2)
    cout << "Vehicles are different\n";
    cout << "\n--- Price Range Filter (4M - 6M) ---\n";
    for(int i = 0; i < listingCount; i++) {
        if(listings[i].getVehicle()->isAffordable(4000000,6000000))
            listings[i].showListing();
    }
    cout << "\nOperator Overloading Demo\n";
    // Vehicle ==
    if(car1 == car2)
        cout << "Same Vehicle\n";
    else
        cout << "Different Vehicles\n";
    // Vehicle +
    cout << "Total Price: " << (car1 + car2) << endl;
    // << operator
    cout << car1 << endl;
    // Listing ==
    if(listings[0] == listings[0])
        cout << "Same Listing\n";
    // Listing +
    Listing updated = listings[0] + 500000;
    updated.showListing();
    // Payments demo
    Payments pay1("P1",&listings[0],"Ali","Ahmed","101",5000000);
    Payments pay2("P2",&listings[0],"Ali","Ahmed","101",3000000);
    showPaymentDetails(pay1);
    showListingDetails(listings[0]);
    cout << "Updated Payment: ";
    Payments pay3 = pay1 + 100000;
    pay3.display();
    showBuyerFavorites(buyer1, buyer1.getFavorites());
return 0;
}
