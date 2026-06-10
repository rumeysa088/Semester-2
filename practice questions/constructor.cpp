#include<iostream>
#include<string>
using namespace std;


class Book{

    
    public: 

      Book(string t,string a,float p){
        title=t;
        author=a;
        price=p;
    }
           string title;
           string author;
           float price;
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
    
};
int main(){
    Book b1("harry potter","JK Rowling",1200.9);
    cout<< "Book Name: "<< b1.getTitle()<<endl;
    cout<< "Authhor Name:" << b1.getAuthor()<<endl;
    return 0;
}