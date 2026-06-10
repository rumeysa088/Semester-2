 #include<iostream>
using namespace std;
struct Book{
    string title;
    string author;
    float price;
};
int main(){
  Book b1;
  cout<<"Enter book title: ";
  getline(cin,b1.title);
  cout<<"\nEnter book author: ";
  getline(cin,b1.author);
   cout<<"\nEnter book price: ";
  cin>>b1.price;

  cout<<"\nTitle: "<<b1.title<<endl;
  cout<<"Author: "<<b1.author<<endl;
  cout<<"price: "<<b1.price<<endl;
return 0;
}