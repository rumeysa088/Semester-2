#include<iostream>
using namespace std;
class Student{

    public:
    string name;
    int roll;
    
   
    Student(string name,int roll){
               this->name=name;
               this->roll=roll;
            }
         
      
};
int main(){    //Player p(); this is UNACCEPTIBLE compiler sees it as function
    Student s; //Will give error cz when u make parametrized const the program forgets abt default const , to fix we can define the default const ourselves
}