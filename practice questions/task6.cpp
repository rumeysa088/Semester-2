#include<iostream>
#include<string>
using namespace std;
class Product{
    int ID;
    string name;        
    int price;
public:
     void input() {
        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter name: ";
        cin>>name;  
        cout << "Enter price: ";
        cin >> price;
    }
    void display(){
        cout<<"Product ID: "<<ID
        <<"\nName: "<<name<<"\nPrice:
         "<<price<<endl;
        cout<<"----------------------
        ----------------------"<<endl;
    }
};
int main(){
  Product arr[4];
  for(int i=0;i<4;i++){
    arr[i].input();
  }cout << "\nAll Product Details:" << endl;
  for(int i=0;i<4;i++){
    arr[i].display();
  }
}