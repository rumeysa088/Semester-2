#include<iostream>
using namespace std;
class Library{
	bool availibility;
	string title;
public:
	Library(){ availibility=1;
	}
	friend class Librarian;
};
class Librarian{
public:
	void issueBook(Library &obj){
		if(obj.availibility){
			
			cout<<"Book Issued.."<<endl; obj.availibility=0;
		}
	}
	void returnBook(Library &obj){
		if(obj.availibility==0){
			cout<<"Book Returned.."<<endl; obj.availibility=1;
		}
	}
};
int main(){
	Library book;
	Librarian l;
	l.issueBook(book);
	l.returnBook(book);
}