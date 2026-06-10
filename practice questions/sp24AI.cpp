#include <iostream>
using namespace std;
class Event {
protected:
    string name;
    string date;
    string venue;
public:
    Event() {}
    Event(string n, string d, string v) : name(n), date(d), venue(v) {}
    virtual void calcEventPrice() = 0;
    virtual void calcEventPrice(int seatingTiers) {
        cout << "Base seating tier pricing\n";
    }
    virtual void calcEventPrice(int attendees, int speakers) {
        cout << "Base conference pricing\n";
    }
    virtual void calcEventPrice(string category) {
        cout << "Base exhibition pricing\n";
    }
};
class Concert : public Event {
public:
    Concert(string n, string d, string v) : Event(n, d, v) {}
    void calcEventPrice() override {
        cout << "Concert event: ";
        calcEventPrice(3); // example tier
    }
    void calcEventPrice(int seatingTiers) override {
        cout << "Price based on seating tiers: " << seatingTiers << endl;
    }
};
class Conference : public Event {
public:
    Conference(string n, string d, string v) : Event(n, d, v) {}
    void calcEventPrice() override {
        cout << "Conference event: ";
        calcEventPrice(100, 10); // example values
    }
    void calcEventPrice(int attendees, int speakers) override {
        cout << "Price based on attendees: " << attendees
             << " and speakers: " << speakers << endl;
    }
};
class Exhibition : public Event {
public:
    Exhibition(string n, string d, string v) : Event(n, d, v) {}
    void calcEventPrice() override {
        cout << "Exhibition event: ";
        calcEventPrice("VIP"); // example category
    }
    void calcEventPrice(string category) override {
        cout << "Price based on category: " << category << endl;
    }
};
int main() {
    Event* arr[3];
    arr[0] = new Concert("Rock Show", "20-2-16", "US");
    arr[1] = new Conference("Tech Conf", "21-2-16", "PK");
    arr[2] = new Exhibition("Art Expo", "22-2-16", "KHI");
    for (int i = 0; i < 3; i++) {
        arr[i]->calcEventPrice(); // ✅ runtime polymorphism
    }
    return 0;
}

#include<iostream>
using namespace std;
class Item {
    int ID;
    float price;
    float highestbiddingAmount;
    int highestBidderId;
public:
    Item() { highestbiddingAmount = 0; highestBidderId = -1; }
    Item(int i, float p) {
        ID = i;
        price = p;
        highestbiddingAmount = 0;
        highestBidderId = -1;
    }
    int getId() { return ID; }
    void placeBid(int bidderID, float bidAmount) {
        try {
            if (bidAmount <= 0)
                throw "Negative or zero bid not allowed!";
            if (bidAmount < price)
                throw "Bid lower than starting price!";
            if (bidAmount <= highestbiddingAmount)
                throw "Bid lower than current highest bid!";

            highestbiddingAmount = bidAmount;
            highestBidderId = bidderID;

        } catch (const char* s) {
            cout << s << endl;
        }
    }
    int getWinningBidderID() {
        if (highestBidderId == -1) {
            cout << "No bids yet!" << endl;
            return -1;
        }
        return highestBidderId;
    }
    float getWinningBidAmount() {
        return highestbiddingAmount;
    }
    friend class AuctionSystem;
};
class AuctionSystem {
    int cap;
    Item* arr;
    int itemCount;
public:
    AuctionSystem(int c) {
        cap = c;
        itemCount = 0;
        arr = new Item[cap];
    }
    void addItem(int id, float price) {
        if (itemCount < cap) {
            arr[itemCount++] = Item(id, price);
        } else {
            cout << "Capacity full!" << endl;
        }
    }
    void placeBid(int itemID, int bidderID, double bidAmount) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (arr[i].ID == itemID) {   // direct access because friend
                arr[i].placeBid(bidderID, bidAmount);
                found = true;
                break;
            }
        }
        try {
            if (!found) throw "Item not found!";
        } catch (const char* s) {
            cout << s << endl;
        }
    }
    int getWinningBidderID(int itemID) {
        for (int i = 0; i < itemCount; i++) {
            if (arr[i].ID == itemID) {
                return arr[i].getWinningBidderID();
            }
        }
        cout << "Item not found!" << endl;
        return -1;
    }

    float getWinningBidAmount(int itemID) {
        for (int i = 0; i < itemCount; i++) {
            if (arr[i].ID == itemID) {
                return arr[i].getWinningBidAmount();
            }
        }
        cout << "Item not found!" << endl;
        return 0;
    }

    void removeItem(int itemID) {
        int index = -1;

        for (int i = 0; i < itemCount; i++) {
            if (arr[i].ID == itemID) {
                index = i;
                break;
            }
        }

        try {
            if (index == -1) throw "Item not found!";

            for (int i = index; i < itemCount - 1; i++) {
                arr[i] = arr[i + 1];
            }
            itemCount--;

        } catch (const char* s) {
            cout << s << endl;
        }
    }
};
int main() {
    AuctionSystem system(3);

    system.addItem(101, 200);
    system.addItem(102, 300);

    system.placeBid(101, 1, 250);
    system.placeBid(101, 2, 240); // invalid
    system.placeBid(102, 3, 350);

    cout << "Item 101 Winner: " 
         << system.getWinningBidderID(101)
         << " Amount: " 
         << system.getWinningBidAmount(101) << endl;

    cout << "Item 102 Winner: " 
         << system.getWinningBidderID(102)
         << " Amount: " 
         << system.getWinningBidAmount(102) << endl;

    return 0;
}

#include<iostream>
using namespace std;
class Property {
protected:
    string address;
    int size;
    string type;
    string ownerInfo;
public:
    Property(string a, int s, string t, string o)
        : address(a), size(s), type(t), ownerInfo(o) {}
    string getType() { return type; }
    float operator+(float taxRate) {
        float amount;
        cout << "Enter booking amount: ";
        cin >> amount;
        return amount + (amount * taxRate);
    }

    void showBothTaxes(float amount) {
        float highTax = amount + amount * 0.40;
        float lowTax = amount + amount * 0.10;

        cout << "With 40% tax: " << highTax << endl;
        cout << "With 10% tax: " << lowTax << endl;
    }
};
class ResidentialProperty : public Property {
    int noOfBedrooms;
    int noOfBathrooms;
public:
    ResidentialProperty(int bd, int bth, string a, int s, string t, string o)
        : Property(a, s, t, o), noOfBedrooms(bd), noOfBathrooms(bth) {}
};
class CommercialProperty : public Property {
    float rentalRates;
public:
    CommercialProperty(float r, string a, int s, string t, string o)
        : Property(a, s, t, o), rentalRates(r) {}
};
class VacationRental : public Property {
    string amenities;
public:
    VacationRental(string am, string a, int s, string t, string o)
        : Property(a, s, t, o), amenities(am) {}
};
template <class T>
void Booking(T a) {
    cout << a.getType() << " Booked" << endl;
}

int main() {
    ResidentialProperty r(3, 2, "ABC Street", 1200, "Residential", "Ali");
    CommercialProperty c(5000, "Main Road", 2000, "Commercial", "Sara");
    Booking(r);
    Booking(c);
    float result1 = r + 0.40;  // 40% tax
    cout << "Total with 40% tax: " << result1 << endl;

    float result2 = c + 0.10;  // 10% tax
    cout << "Total with 10% tax: " << result2 << endl;

    r.showBothTaxes(1000); // both taxes

    return 0;
}

#include<iostream>
using namespace std;
class Tour {
protected:
    string name;
    int duration;
    string destination;
public:
    Tour(string n, int d, string dest)
        : name(n), duration(d), destination(dest) {}
    virtual void calculateTicketPrice() = 0;
    virtual void scheduleTour() = 0;
};
class AdventureTour : public Tour {
public:
    AdventureTour(string n, int d, string dest)
        : Tour(n, d, dest) {}
    void calculateTicketPrice() override {
        cout << "Adventure Tour price based on activities + duration\n";
    }
    void scheduleTour() override {
        cout << "Adventure Tour scheduled with outdoor activities\n";
    }
};
class CulturalTour : public Tour {
public:
    CulturalTour(string n, int d, string dest)
        : Tour(n, d, dest) {}
    void calculateTicketPrice() override {
        cout << "Cultural Tour price based on sites visited\n";
    }
    void scheduleTour() override {
        cout << "Cultural Tour scheduled with museum & heritage visits\n";
    }
};
class WildlifeTour : public Tour {
public:
    WildlifeTour(string n, int d, string dest)
        : Tour(n, d, dest) {}
    void calculateTicketPrice() override {
        cout << "Wildlife Tour price based on rarity of sightings\n";
    }
    void scheduleTour() override {
        cout << "Wildlife Tour scheduled with guided safari\n";
    }
};
int main() {

    Tour* t1 = new AdventureTour("Mount Trek", 5, "Hunza");
    Tour* t2 = new CulturalTour("Heritage Walk", 3, "Lahore");
    Tour* t3 = new WildlifeTour("Safari Trip", 4, "Kenya");

    t1->calculateTicketPrice();
    t1->scheduleTour();

    t2->calculateTicketPrice();
    t2->scheduleTour();

    t3->calculateTicketPrice();
    t3->scheduleTour();

    return 0;
}

#include<iostream>
using namespace std;

class Seat {
    int row;
    int snum;
    bool reserved;

public:
    Seat() { reserved = 0; }

    Seat(int r, int s) {
        row = r;
        snum = s;
        reserved = 0;
    }

    friend class Theatre;

    void reserveSeat() { reserved = 1; }
    void cancelReservation() { reserved = 0; }
    bool getStatus() { return reserved; }
};

class Theatre {
    Seat* arr;
    int rows;
    int seatsPerRow;

public:
    Theatre() {
        arr = nullptr;
        rows = 0;
        seatsPerRow = 0;
    }

    // initialize seating
    void initializeSeats(int r, int s) {
        rows = r;
        seatsPerRow = s;
        arr = new Seat[rows * seatsPerRow];

        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seatsPerRow; j++) {
                arr[index++] = Seat(i, j);
            }
        }
    }
    bool isValidSeat(int r, int s) {
        return (r >= 0 && r < rows && s >= 0 && s < seatsPerRow);
    }
    int getIndex(int r, int s) {
        return r * seatsPerRow + s;
    }
    void reserve(int r, int s) {
        try {
            if (!isValidSeat(r, s))
                throw "Invalid Seat!";

            int idx = getIndex(r, s);

            if (arr[idx].reserved)
                throw "Seat already reserved!";

            arr[idx].reserveSeat();
            cout << "Seat reserved successfully\n";
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    void cancelReservation(int r, int s) {
        try {
            if (!isValidSeat(r, s))
                throw "Invalid Seat!";

            int idx = getIndex(r, s);

            if (!arr[idx].reserved)
                throw "Seat is not reserved!";

            arr[idx].cancelReservation();
            cout << "Reservation cancelled\n";
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    void viewAvailableSeats() {
        cout << "\nSeating Chart (0 = available, 1 = reserved)\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seatsPerRow; j++) {
                int idx = getIndex(i, j);
                cout << arr[idx].reserved << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Theatre t;
    t.initializeSeats(3, 4);
    t.viewAvailableSeats();
    t.reserve(1, 2);
    t.reserve(1, 2); // error case
    t.viewAvailableSeats();
    t.cancelReservation(1, 2);
    t.viewAvailableSeats();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Flight {
public:
    string flightNo, dep, arr;
    float baseFare;

    Flight(string fn, string d, string a, float fare) 
        : flightNo(fn), dep(d), arr(a), baseFare(fare) {}

    // Overloading + for 50% tax
    float operator+() { return baseFare * 1.50; }

    // Overloading - for 20% tax
    float operator-() { return baseFare * 1.20; }

    void showTaxBreakdown() {
        cout << "Price (High Tax 50%): $" << +(*this) << endl;
        cout << "Price (Med Tax 20%): $" << -(*this) << endl;
    }

    virtual void display() = 0; // Pure virtual for abstraction
};
class StandardFlight : public Flight {
public:
    StandardFlight(string fn, string d, string a, float fare) : Flight(fn, d, a, fare) {}
    void display() override {
        cout << "Standard Flight " << flightNo << " [" << dep << " to " << arr << "]" << endl;
    }
};
class PremiumFlight : public Flight {
public:
    string meal;
    PremiumFlight(string fn, string d, string a, float fare, string m) 
        : Flight(fn, d, a, fare), meal(m) {}
    void display() override {
        cout << "Premium Flight " << flightNo << " | Meal: " << meal << endl;
    }
};
class LuxuryFlight : public Flight {
public:
    LuxuryFlight(string fn, string d, string a, float fare) : Flight(fn, d, a, fare) {}
    void display() override {
        cout << "Luxury Flight " << flightNo << " | Amenities: Private Lounge & Bed" << endl;
    }
};
template <typename T>
class BookingSystem {
public:
    void process(T* flight) {
        cout << "--- BOOKING DETAILS ---" << endl;
        flight->display();
        flight->showTaxBreakdown();
        cout << "-----------------------" << endl << endl;
    }
};
int main() {
    // 1. Fixed objects
    StandardFlight s1("S10", "NYC", "LON", 500);
    PremiumFlight p1("P20", "DXB", "SIN", 1200, "Steak");
    LuxuryFlight l1("L30", "PAR", "TOK", 5000);
    // 2. Using Template System
    BookingSystem<StandardFlight> b1;
    BookingSystem<PremiumFlight> b2;
    BookingSystem<LuxuryFlight> b3;

    b1.process(&s1);
    b2.process(&p1);
    b3.process(&l1);
    return 0;
}
