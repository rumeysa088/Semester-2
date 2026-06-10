#include<iostream>
using namespace std;
class Student{
    int mathMarks;
    int engMarks;
    int CompMarks;
public:
    void setMarks(int a,int b,int c){ if((a<100 && a>0) && (b<100 && b>0) && (c<100 &&c>0)){
        mathMarks=a;engMarks=b;CompMarks=c;
    }}
    friend float calcAvg(Student obj);
};
 float calcAvg(Student obj){
         float avg=(obj.mathMarks+obj.engMarks+obj.CompMarks)/3.0;
          return avg;
          }
int main(){
   Student s;int a;int b;int c;
   cout<<"Enter student marks: ";
   cin>>a;cin>>b;cin>>c;
   s.setMarks(a,b,c);
   cout<<"Average: "<<calcAvg(s)<<endl;
}