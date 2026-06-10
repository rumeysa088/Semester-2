 #include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int* arr = new int[size];
    cout<<"Enter array elements: ";
    for(int i=0;i<size;i++){
      cin>>arr[i];
   }
    int max=arr[0];int min=arr[0];
   for(int i=0;i<size;i++){
      if(arr[i]>max)max=arr[i];
   }
    for(int i=0;i<size;i++){
      if(arr[i]<min)min=arr[i];
   }
   cout<<"Maximum : "<<max<<endl;
    cout<<"Minimum : "<<min<<endl;

    delete arr;
    arr=nullptr;
}