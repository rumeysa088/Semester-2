#include <iostream>
#include <fstream>
using namespace std;

// ================= TELEMETRY =================
class TelemetryData {
    float fuelConsumption;
    float speed;
    bool engineStatus;

public:
    TelemetryData() {}

    TelemetryData(float fc, float s, bool e)
        : fuelConsumption(fc), speed(s), engineStatus(e) {}

    void display() const {
        cout << "Fuel Consumption: " << fuelConsumption << endl;
        cout << "Speed: " << speed << endl;
        cout << "Engine Status: " << (engineStatus ? "Running" : "Stopped") << endl;
    }
};

// ================= VEHICLE =================
class Vehicle {
protected:
    string ID;
    string model;
    string fuelType;
    string currentLocation;
    TelemetryData data;

public:
    Vehicle() {}

    Vehicle(string i, string m, string f, string c, TelemetryData d)
        : ID(i), model(m), fuelType(f), currentLocation(c), data(d) {}

    virtual void displayDetails() {
        cout << "ID: " << ID << endl;
        cout << "Model: " << model << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Location: " << currentLocation << endl;
        data.display();
    }

    void updateLocation(const string& newLocation) {
        currentLocation = newLocation;
    }

    string getVehicleID() const {
        return ID;
    }

    string getLocation() const {
        return currentLocation;
    }

    friend class VehicleManager;
};

// ================= VEHICLE MANAGER =================
class VehicleManager {
public:

    void trackVehicleLocation(Vehicle& vehicle) {
        cout << "Vehicle ID: " << vehicle.ID
             << " | Location: " << vehicle.currentLocation << endl;
    }

    // IMPORTANT: pass size
    void writeToFile(Vehicle* arr, int size) {
        ofstream out("vehicle_info.txt");

        for (int i = 0; i < size; i++) {
            out << arr[i].ID << " "
                << arr[i].model << " "
                << arr[i].fuelType << " "
                << arr[i].currentLocation << endl;
        }

        out.close();
    }

    void readFromFile() {
        ifstream in("vehicle_info.txt");

        string id, model, fuel, location;

        while (in >> id >> model >> fuel >> location) {
            if (location == "Karachi") {
                cout << "ID: " << id
                     << " Location: " << location << endl;
            }
        }

        in.close();
    }
};

// ================= DERIVED CLASSES =================
class MeterReadingVehicle : public Vehicle {
    int readingCapacity;

public:
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Reading Capacity: " << readingCapacity << endl;
    }
};

class PipelineInspectionVehicle : public Vehicle {
    int inspectionRange;

public:
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Inspection Range: " << inspectionRange << endl;
    }
};

class MaintenanceVehicle : public Vehicle {
    int equipmentCapacity;

public:
    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Equipment Capacity: " << equipmentCapacity << endl;
    }
};

// ================= MAIN =================
int main() {
    TelemetryData t1(2.5, 60, true);
    TelemetryData t2(3.0, 40, false);

    Vehicle v1("V1234", "Toyota", "Petrol", "Karachi", t1);
    Vehicle v2("V5678", "Honda", "Diesel", "Lahore", t2);

    Vehicle arr[2] = {v1, v2};

    VehicleManager vm;

    vm.trackVehicleLocation(v1);

    vm.writeToFile(arr, 2);

    vm.readFromFile();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// ================== JEWELRY ITEM ==================

class JewelryItem {
protected:
    string itemCode;
    string itemName;
    double weightInGrams;
    int purity;

public:
    JewelryItem() {}

    JewelryItem(string code, string name,
                double weight, int p)
    {
        itemCode = code;
        itemName = name;
        weightInGrams = weight;
        purity = p;
    }

    virtual void displayDetails() = 0;
    virtual double calculatePrice() = 0;

    virtual ~JewelryItem() {}

    friend bool operator>(JewelryItem* j1,
                          JewelryItem* j2);

    friend bool operator<(JewelryItem* j1,
                          JewelryItem* j2);

    friend bool operator==(JewelryItem* j1,
                           JewelryItem* j2);
};

// ================== OPERATOR OVERLOADING ==================

bool operator>(JewelryItem* j1, JewelryItem* j2)
{
    return j1->calculatePrice() >
           j2->calculatePrice();
}

bool operator<(JewelryItem* j1, JewelryItem* j2)
{
    return j1->calculatePrice() <
           j2->calculatePrice();
}

bool operator==(JewelryItem* j1, JewelryItem* j2)
{
    return j1->calculatePrice() ==
           j2->calculatePrice();
}

// ================== GOLD JEWELRY ==================

class GoldJewelry : public JewelryItem {
    int goldKarat;

public:
    GoldJewelry(string code,
                string name,
                double weight,
                int purity,
                int karat)
        : JewelryItem(code, name, weight, purity)
    {
        goldKarat = karat;
    }

    void setGoldKarat(int karat)
    {
        goldKarat = karat;
    }

    double calculatePrice() override
    {
        return weightInGrams *
               purity *
               goldKarat;
    }

    void displayDetails() override
    {
        cout << "\nGold Jewelry\n";
        cout << "Code: " << itemCode << endl;
        cout << "Name: " << itemName << endl;
        cout << "Weight: " << weightInGrams << endl;
        cout << "Purity: " << purity << endl;
        cout << "Gold Karat: "
             << goldKarat << endl;
        cout << "Price: "
             << calculatePrice() << endl;
    }
};

// ================== DIAMOND JEWELRY ==================

class DiamondJewelry : public JewelryItem {
    int numDiamonds;
    double diamondCarat;

public:
    DiamondJewelry(string code,
                   string name,
                   double weight,
                   int purity)
        : JewelryItem(code, name, weight, purity)
    {
        numDiamonds = 0;
        diamondCarat = 0;
    }

    void addDiamonds(int num,
                     double carat)
    {
        numDiamonds = num;
        diamondCarat = carat;
    }

    double calculatePrice() override
    {
        return (weightInGrams * purity) +
               (numDiamonds *
                diamondCarat *
                10000);
    }

    void displayDetails() override
    {
        cout << "\nDiamond Jewelry\n";
        cout << "Code: " << itemCode << endl;
        cout << "Name: " << itemName << endl;
        cout << "Weight: " << weightInGrams << endl;
        cout << "Purity: " << purity << endl;
        cout << "Diamonds: "
             << numDiamonds << endl;
        cout << "Diamond Carat: "
             << diamondCarat << endl;
        cout << "Price: "
             << calculatePrice() << endl;
    }
};

// ================== CUSTOMER ==================

class Customer {
    string customerID;
    string name;

    JewelryItem** purchasedItems;

    int count;
    int capacity;

public:
    Customer(string id,
             string n,
             int cap)
    {
        customerID = id;
        name = n;

        capacity = cap;
        count = 0;

        purchasedItems =
            new JewelryItem*[capacity];
    }

    void purchaseItem(JewelryItem* item)
    {
        if(count < capacity)
        {
            purchasedItems[count++] = item;
        }
    }

    double calculateTotalPurchasePrice()
    {
        double total = 0;

        for(int i=0;i<count;i++)
        {
            total +=
            purchasedItems[i]->calculatePrice();
        }

        return total;
    }

    ~Customer()
    {
        delete[] purchasedItems;
    }
};

// ================== STORE INVENTORY ==================

class StoreInventory {
    JewelryItem** inventory;

    int count;
    int capacity;

public:
    StoreInventory(int cap)
    {
        capacity = cap;
        count = 0;

        inventory =
            new JewelryItem*[capacity];
    }

    void addItemToInventory(
        JewelryItem* item)
    {
        if(count < capacity)
        {
            inventory[count++] = item;
        }
    }

    void displayInventory()
    {
        cout << "\n===== INVENTORY =====\n";

        for(int i=0;i<count;i++)
        {
            inventory[i]->displayDetails();
        }
    }

    ~StoreInventory()
    {
        delete[] inventory;
    }
};

// ================== MAIN ==================

int main()
{
    GoldJewelry g1(
        "G101",
        "Gold Ring",
        15,
        24,
        22);

    DiamondJewelry d1(
        "D201",
        "Diamond Necklace",
        20,
        18);

    d1.addDiamonds(5,1.5);

    StoreInventory store(10);

    store.addItemToInventory(&g1);
    store.addItemToInventory(&d1);

    store.displayInventory();

    Customer c1(
        "C001",
        "Ali",
        10);

    c1.purchaseItem(&g1);
    c1.purchaseItem(&d1);

    cout << "\nTotal Purchase Price = "
         << c1.calculateTotalPurchasePrice()
         << endl;

    if(&g1 > &d1)
        cout << "\nGold item is more expensive\n";
    else
        cout << "\nDiamond item is more expensive\n";

    return 0;
}

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class MyException : public exception
{
    string msg;

public:
    MyException(string m) : msg(m) {}

    const char* what() const noexcept override
    {
        return msg.c_str();
    }
};

template <class T>
class UniqueCart
{
    T arr[10];
    int count;

public:
    UniqueCart()
    {
        count = 0;
    }

    void add(const T& item)
    {
        // Duplicate check
        for(int i = 0; i < count; i++)
        {
            if(arr[i] == item)
            {
                throw MyException("Duplicate Item Exception");
            }
        }

        // Capacity check
        if(count >= 10)
        {
            throw MyException("Out of bound");
        }

        arr[count++] = item;
    }

    void remove(const T& item)
    {
        int index = -1;

        for(int i = 0; i < count; i++)
        {
            if(arr[i] == item)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            throw MyException("Item Not Found Exception");
        }

        for(int i = index; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        count--;
    }

    bool contains(const T& item)
    {
        for(int i = 0; i < count; i++)
        {
            if(arr[i] == item)
            {
                return true;
            }
        }

        return false;
    }

    void display()
    {
        for(int i = 0; i < count; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    UniqueCart<string> cart;

    try
    {
        cart.add("Book");
        cart.add("Laptop");
        cart.add("Shirt");

        cart.add("Book"); // Duplicate
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
}