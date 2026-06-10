#include<iostream>
using namespace std;
static int i=0;
int fib(int n,int i){
    i++;
    if(n<=1)return n;
    else return fib(n-2,i)+fib(n-1,i);
}

int main(){
  fib(4,i);
  cout<<i;
}