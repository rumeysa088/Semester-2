#include <iostream>
using namespace std;
class Complex
{
public:
    int real, imag;
    Complex(int r, int i)
    {
        real = r;imag = i;
    }
    Complex operator + (Complex obj)
    {
        Complex temp(0,0);
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
    Complex operator -(Complex obj)
    {
        Complex temp(0,0);
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;
        return temp;
    }
    Complex operator *(Complex obj){
        Complex temp(0,0);
        temp.real=real*obj.real;
        temp.imag = imag*obj.imag;
        return temp;
    }
};
int main()
{
    Complex c1(2,3); // 2+3i
    Complex c2(4,5); // 4+5i
    Complex c3 = c1 + c2; 
    Complex c4=c2-c1;
    Complex c5=c1*c2;
    cout << c3.real << " + " << c3.imag << "i"<<endl;
    cout << c4.real << " + " << c4.imag << "i"<<endl;
    cout << c5.real << " + " << c5.imag << "i"<<endl;
    return 0;
}