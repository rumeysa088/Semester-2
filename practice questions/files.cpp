#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream f;
    f.open("io.txt",ios::out | ios ::in);
    for(int i=65;i<=90;i++){
        f.put(i);
    } 
    f.close();
    f.open("io.txt");
    char c;
    while(f.get(c)){ cout<<c;}
    f.close();
    return 0;
}