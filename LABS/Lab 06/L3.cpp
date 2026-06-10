#include<iostream>
using namespace std;
class Write{
public:
    void writes(){cout<<"He writes.."<<endl;}
};
class Speak{
public:
    void speaks(){cout<<"He speaks.."<<endl;}
};
class Author:public Write,public Speak{
};
int main(){
   Author a;
   a.writes();a.speaks();
}