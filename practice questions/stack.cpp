#include<iostream>
using namespace std;
template <class T,int size>
class Stack{
    T arr[size];
    int max;
    int index;
public:
    Stack():index(-1),max(size){}
    void push(T a){
        if(index==(size-1)){cout<<"STACK FULL!"<<endl;}
        arr[++index]=a;
    }
    T pop(){
        if(index==-1){cout<<"STACK EMPTY!"<<endl;}
        return arr[index--];
    }
    T peek(){
        if(index==-1){cout<<"STACK EMPTY!"<<endl;}
        return arr[index];
    }
};
int main(){
    Stack<int,10> intstack;
    intstack.push(0);
    intstack.push(1);
    intstack.push(2);
    cout<<intstack.peek()<< "Peek"<<endl;
    cout<<intstack.pop()<<" Popped! "<<endl;
}