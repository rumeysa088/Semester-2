// #include<iostream>
// using namespace std;
// int returnLargest(int s,int arr[]){ int max=arr[0];int index;
//     for(int i=0;i<s;i++){if(arr[i]>max){max=arr[i];index=i;}}  // 3,4,2,4,3
//     return index;
// }
// int main(){
//     int arr[]={58 , 26 , 91 , 34 , 70 , 91 , 88};
//     cout<<"Index: "<<returnLargest(7,arr);
// }

// #include<iostream>
// using namespace std;
// class RestrauntMeal{
// protected:
//     string name;
//     int price;
// public:
//     RestrauntMeal(){}
//     RestrauntMeal(string n,int p):name(n),price(p){}
//     void displayRM(){ cout<<"Name: "<<name<<"Price: "<<price<<endl;}
// };
// class HotelService{
// protected:
//     string servicename;
//     int fee;
//     int roomNo;
// public:
//     HotelService(){}
//     HotelService(string n,int f,int r):servicename(n),fee(f),roomNo(r){}
//     void displayHS(){cout<<"Service: "<<servicename<<"Fee: "<<fee<<"Room No: "<<roomNo<<endl;}
// };
// class RoomService:public RestrauntMeal,public HotelService{
// public:
//     RoomService(int rn,string n,int p):HotelService("room service",400,rn),RestrauntMeal(n,p){}
//     void display(){ displayRM(); displayHS();}
// };
// int main(){
//    RoomService s1(21,"biryani",300);
//    s1.display();
// }

#include<iostream>
using namespace std;
class Person{
    string name;
    int age;
    string work;
public:
    Person(){name="zero"; age=0; work="zero";}
    Person(string n,int a,string w){name=n; age=a; work=w;}
    string getName(){ return name;}
    int getAge(){ return age;}
    string getWork(){ return work;}
};
class Player:public person{
    int runs;
    int matches;
    int ODIs;
    int T20s;
    int wickets;
    int fours;
    int sixes;
public:
   string getWork(string w="Playing cricket.."; return w;)
   Player(int r,int m,int o,int t,int w,int f,int s,string n,int a,string wo):runs(r),matches(m),ODIs(o),T20s(t),wickets(w),fours(f),sixes(s),Person(n,a,wa){}
};
class Umpire:public Player{
    string ump_career_start_year;
    int noT20s;
    int noODIs;
    int noTests;
public:
    string getWork(string w="Umpiring..."; return w;)
    Umpire(string y,int t,int o,int te,string n,int a,string wo):ump_career_start_year(y),noT20s(t),noODIs(o),noTests(te),Person(n,a,wa){}
};
int main(){
  

}