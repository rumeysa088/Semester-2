#include<iostream> 
#include<string>
using namespace std;
class Buyer;
class Seller;
class Listing;
class Vehicle {  // Vehicle: default needed for array declarations, parameterized for creating cars,
                 //          copy for storing in Favorites or Seller arrays
private:
    string type;
    string brand;
    string model;     
    int ID;
    int price;
    int year;        
    int mileage;     
    string condition;
    string fuelType;

    static int totalVehicles; 
    // Static because total number of vehicles is shared by all the objects

public:
    Vehicle() : ID(0) {}

    Vehicle(string t,string b,string m,int id,int p,int y,int mil,
            string c, string f):type(t),brand(b),model(m),ID(id),price(p),year(y),mileage(mil),condition(c), fuelType(f) {totalVehicles++; }
  //Copyconstructor
    Vehicle(const Vehicle& v):type(v.type),brand(v.brand),model(v.model),ID(v.ID),price(v.price),year(v.year),mileage(v.mileage),condition(v.condition), fuelType(v.fuelType) {}

    string getBrand()const { return brand; }
    string getModel()const { return model; }
    int getPrice()const { return price; }
    int getYear()const { return year; }
    int getMileage()const { return mileage; }
    int getID()const { return ID; }
    string getType()const { return type; }

    static int getTotalVehicles() { return totalVehicles; }
    void setPrice(int p) { price= p; }
    void setYear(int y) { year= y; }
    void setMileage(int m) { mileage= m; }
    void setCondition(string c) { condition= c; }
    void display() const {
        cout<<brand<< " " <<model << " (" << year << ") Price:" <<price << " Mileage:" <<mileage <<"\n";
    }
    void resetMileage() { mileage = 0; }
    bool isAffordable(int budget) const { return price <= budget; }
    bool isNew() const { return condition == "New"; }
};
int Vehicle::totalVehicles=0;
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
class Seller{ // default constructor for array/pointer use, parameterized for initialization
private:
    string name;
    string contactInfo;
    string address;
    Vehicle cars[10]; //seller can have up to 10 cars(composition)
    int carCount;
    string ratings;
public:
    Seller():carCount(0) {}
    Seller(string n,string ci,string a,string r):name(n),contactInfo(ci),address(a),ratings(r),carCount(0) {}
    string getName() const{ return name; }
    string getRatings() const{ return ratings; }
    int getCarCount() const{ return carCount; }
    void setRatings(string r) { ratings = r; }
    void display() const { cout << "Seller: " << name << " Rating: " << ratings << "\n"; }
    void updateContact(string ci) { contactInfo = ci; }
    void updateAddress(string a) { address = a; }
    bool hasAvailableCars() const { return carCount > 0; }
    void addCar(const Vehicle& v) {
        if(carCount < 10) {
            cars[carCount++]= v;
            cout <<"Car added to seller "<< name << endl;
        }
    }
    void removeCar(int id) {
        for(int i=0;i<carCount;i++) {
            if(cars[i].getID() == id) {
                for(int j=i;j<carCount-1;j++)
                    cars[j] = cars[j+1];
                carCount--;
                cout << "Car removed from seller " << name << endl;
                break;
            }
        }
    }
};
class Favorites{ //default ctor needed since Buyer has it as a member, parameterized if created alone
private:
    string buyerName;
    Vehicle favoriteCars[10];
    int favoriteCount;
    const int maxFavorites;
    string dateOfLastUpdate;
public:
    Favorites():maxFavorites(10),favoriteCount(0){}
    Favorites(string bName,string date):buyerName(bName),dateOfLastUpdate(date),favoriteCount(0),maxFavorites(10){}
    int getFavoriteCount()const {return favoriteCount; }
    void addFavorite(Vehicle* v) {
        if(favoriteCount < maxFavorites) {
            favoriteCars[favoriteCount++]=*v;
            cout <<"Saved: "<< v->getBrand()<<" " << v->getModel()<< "\n";
        }
    }
    void removeFavorite(int id) {
        for(int i=0;i< favoriteCount;i++) {
            if(favoriteCars[i].getID() == id) {
                for(int j= i;j<favoriteCount-1;j++) favoriteCars[j]= favoriteCars[j+1];
                favoriteCount--;
                return;
            }
        }
    }
    void showFavorites() const {
        for(int i=0;i<favoriteCount;i++) favoriteCars[i].display();
    }
    void clearFavorites(){ favoriteCount = 0; }
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

class Buyer{ //default for array use, parameterized for creating buyers
private:
    string name;
    string contactInfo;
    string address;
    Favorites myFavorites;   //composition
    Message messages[20];  //messages from sellers (composition)
    int messageCount;
public:
    Buyer():messageCount(0) {}
    Buyer(string n,string ci,string a): name(n),contactInfo(ci),address(a),messageCount(0){}
    string getName()const { return name; }
    int getMessageCount()const { return messageCount; }
    void saveFavorite(Vehicle* v) { myFavorites.addFavorite(v); }
    void showFavorites()const { myFavorites.showFavorites(); }
    void sendMessage(string msg) { cout << name << " sent: " << msg << "\n"; }
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
};
class Admin{  //default for array use, parameterized for creation, copy needed because adminID is const
private:
    string name;
    const string adminID;
    string contactInfo;
    string role;
    int pendingListingsCount;
    static int totalUsers; //Made static because it represents  tottal number of users in the marketplace and its not an individual property 
public:
    Admin(){}
    Admin(string n,string id,string ci,string r): name(n),adminID(id),contactInfo(ci),role(r),pendingListingsCount(0){}
    Admin(const Admin& a):name(a.name),adminID(a.adminID),contactInfo(a.contactInfo),role(a.role),pendingListingsCount(a.pendingListingsCount){}
    static int getTotalUsers() {return totalUsers;}
    void display()const { cout << "Admin: " << name << " Role: " << role << "\n"; }
   void approveListing(Listing& l)const;
    void incrementPending(){ pendingListingsCount++; }
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

};
void Admin::approveListing(Listing& l) const {
    l.setStatus("Approved");
    cout << l.getListingID() << " approved.\n";
}
class Reviews{  //default for array use, parameterized for creating reviews
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
class Payments{  //default for array use, parameterized for creating payments
private:
    const string paymentID;
    Listing* listingPtr;
    string buyerName;
    string sellerName;
    string vehicleID;
    int amount;
public:
    Payments(){}
    Payments(string pid,Listing* l,string bn,string sn,string vid,int amt):paymentID(pid),listingPtr(l),buyerName(bn),sellerName(sn),vehicleID(vid),amount(amt){}
    
    string getPaymentID() const { return paymentID; }
    int getAmount() const { return amount; }
    string getBuyerName()const { return buyerName; }
    string getSellerName() const { return sellerName; }
    void display() const { cout <<"Payment " <<paymentID << " Amount: " << amount << "\n"; }
    void processPayment()const { cout << "Processing payment of Rs." << amount << "\n"; }
    bool isValid()const { return amount > 0; }
    void updateAmount(int a) { amount = a; }
};
int main(){
    Seller seller1("Ahmed","123456","Karachi","5 stars");
    Seller seller2("Ali","654321","Lahore","4 stars");
    Vehicle car1("Sedan","Toyota","Corolla",101,5000000,2020,40000,"Used","Petrol");
    Vehicle car2("SUV","Honda","CRV",102,6000000,2022,20000,"New","Petrol");
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
return 0;
}
