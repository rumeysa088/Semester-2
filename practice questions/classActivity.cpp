#include<iostream>
using namespace std;
class waterBottle{
    string company;
    string color;
    int litres;
    int mls;
public:

    void setter(string comp,string col,int ml){
         company=comp;
         color=col;
         mls=ml;
         litres=mls/1000;
    }
    string getCompany(){return company;}
    string getColor(){return color;}
    int getMls(){return mls;}

    void update(){
        int drank;
        cout<<"Enter water drank: ";
        cin>>drank;
        mls-=drank;
        litres=mls/1000;
    }
};
int main(){
    waterBottle w;
    w.setter("nestle","blue",1000);
    cout<<"Company: "<<w.getCompany()<<endl;
     cout<<"Color: "<<w.getColor()<<endl;
      cout<<"Capacity mls: "<<w.getMls()<<endl;
return 0;
}