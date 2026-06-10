#include<iostream>
#include<string>
using namespace std;
class Customer{
    string name;
    string address;
public:
    Customer(){}
    Customer(string n,string a):name(n),address(a){}
    void placeOrder(Shop& s){ string name;
        cout<<"Enter product name"<<endl;
        cin>>productname;
        s.receiveOrder(productname);
    }
    //void cancelOrder(){}
};
class Product{
    public:
    int id;
    string name;
public:
    Product(){}
    string getname(){
        return name;
    }
     Product(int i,string n):id(i),name(n){}
    void display(){
        cout<<"Product ID: "<<id<<"\nName: "<<name<<endl;
    }
};
class Shop{
    string name;
    string address;
    Product* arr;
    int maxProducts=15;
    static int count;
public:
 Shop(){}
 Shop(string n,string a){
    name=n;address=a;
    arr=new Product[maxProducts];
 }
 void receiveOrder(string productname){
    cout<<"Order processing..."<<endl;
    bool found=0;int index;
     for(int i=0;i<15;i++){
        if(arr[i].name==productname){found=1;index=i;}
        
     }if(found==0)cout<<"Product not found"<<endl;
     else{cout<<"Order Taken!"<<arr[index].display();}
 }
  void addproduct(int id,string name){
     if(count<maxProducts){
         arr[count++].getname()=name;arr[count].id=id;
     }
     else{cout<<"Inventory Full!"<<endl;}
  }
  void deleteProduct(int id,string name){
    bool found;
     for(int i=0;i<count;i++){
        if(arr[i].getname()==name)found=1;
     }
     if(found){/*free that memory maybe?*/}
     else{cout<<"Product doesnt exist"<<endl;}
  }
  ~Shop(){
    delete[] arr;
  }
};
int Shop::count=0;
int main(){
   Shop s1("Imtiaz","Gulshan");
   Customer c1("Ali","R-1696");
   s1.addproduct(201,"sugar");
   c1.placeOrder(s1);
}

#include <iostream>
#include <string>
using namespace std;

// ------------------- Product Class -------------------
class Product {
    int productID;
    string name;
    double price;

public:
    Product(int id, string n, double p = 5000) 
        : productID(id), name(n), price(p) {}

    void display() {
        cout << "Product ID: " << productID 
             << ", Name: " << name 
             << ", Price: PKR " << price << endl;
    }
};

// ------------------- Shop Class -------------------
class Shop {
    string name;
    Product* products[10];   // Aggregation: shop has products
    int numProducts;

public:
    Shop(string n) : name(n), numProducts(0) {}

    void addProduct(Product* p) {
        if(numProducts < 10)
            products[numProducts++] = p;
        else
            cout << "Shop inventory full!" << endl;
    }

    // Takes an order from customer
    void takeOrder(const string& productName) {
        cout << "\nShop taking order for product: " << productName << endl;
        // Find product by name
        bool found = false;
        for(int i = 0; i < numProducts; i++) {
            if(products[i]->getName() == productName) {
                cout << "Order processed. Delivering product...\n";
                products[i]->display();
                found = true;
                break;
            }
        }
        if(!found)
            cout << "Product not found in inventory!\n";
    }

    void showInventory() {
        cout << "\nShop Inventory:\n";
        for(int i = 0; i < numProducts; i++)
            products[i]->display();
    }
};

// ------------------- Customer Class -------------------
class Customer {
    string firstName;
    string lastName;
    string address;

public:
    Customer(string f, string l, string a) 
        : firstName(f), lastName(l), address(a) {}

    void display() {
        cout << "Customer: " << firstName << " " << lastName << endl;
        cout << "Address: " << address << endl;
    }

    // Customer places order via shop
    void placeOrder(Shop &shop, const string& productName) {
        cout << "\nCustomer placing order...\n";
        display();
        shop.takeOrder(productName);
    }
};

// ------------------- Main Function -------------------
int main() {
    // Create products
    Product p1(101, "RobotA");
    Product p2(102, "RobotB");

    // Create shop
    Shop geass("Geass Corp");

    // Add products to shop
    geass.addProduct(&p1);
    geass.addProduct(&p2);

    // Show inventory
    geass.showInventory();

    // Create customer
    Customer c1("Lelouch", "Vi Britannia", "Street 2, Area 11");

    // Customer places order
    c1.placeOrder(geass, "RobotA"); // order RobotA

    return 0;
}