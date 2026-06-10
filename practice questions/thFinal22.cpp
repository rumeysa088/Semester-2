// #include<iostream>
// using namespace std;

// template<typename T>
// void PrintIt(T a)
// {
//     cout << a << endl;
// }

// class Sport
// {
//     string current_champ;
//     int start_year;
//     string headquarter_location;

// public:

//     Sport(string cc="Unknown",
//           int sy=0,
//           string hq="Unknown")
//     {
//         current_champ = cc;
//         start_year = sy;
//         headquarter_location = hq;
//     }

//     string getHDL() const
//     {
//         return headquarter_location;
//     }

//     int getYear() const
//     {
//         return start_year;
//     }
// };

// class Tournament
// {
// protected:
//     Sport* sport;

// public:

//     // Default constructor
//     Tournament()
//     {
//         sport = new Sport();
//     }

//     // Overloaded constructor
//     Tournament(string cc,int sy,string hq)
//     {
//         sport = new Sport(cc,sy,hq);
//     }

//     virtual void Begin_Tournament(const Sport& s)
//     {
//         if(s.getHDL()=="Karachi" ||
//            s.getHDL()=="Toronto")
//         {
//             cout<<"Tournament begins"<<endl;
//         }
//     }

//     virtual ~Tournament()
//     {
//         delete sport;
//     }
// };

// class WorldCup : public Tournament
// {
// public:

//     WorldCup() : Tournament() {}

//     WorldCup(string cc,int sy,string hq)
//         : Tournament(cc,sy,hq)
//     {}

//     void Begin_Tournament(const Sport& s) override
//     {
//         if(
//            s.getYear() > 1950 &&
//            s.getHDL() != "Karachi" &&
//            s.getHDL() != "Toronto"
//           )
//         {
//             cout<<"World Cup begins"<<endl;
//         }
//     }
// };
// #include<iostream>
// #include<exception>

// using namespace std;

// class MyException : public exception
// {
//     string msg;

// public:

//     MyException(string m)
//     {
//         msg = m;
//     }

//     const char* what() const noexcept override
//     {
//         return msg.c_str();
//     }
// };

// class JumpingCastle
// {
//     int count;

// public:

//     JumpingCastle()
//     {
//         count = 0;
//     }

//     void Enter()
//     {
//         if(count >= 10)
//             throw MyException("Count Overflow");

//         count++;
//     }

//     void Exit()
//     {
//         if(count <= 0)
//             throw MyException("Count Underflow");

//         count--;
//     }

//     void Display()
//     {
//         cout<<"Current Count = "<<count<<endl;
//     }
// };

// int main()
// {
//     JumpingCastle jc;

//     int choice = 0;

//     while(choice != 3)
//     {
//         jc.Display();

//         cout<<"\n1. Enter\n";
//         cout<<"2. Exit\n";
//         cout<<"3. End\n";

//         cin>>choice;

//         try
//         {
//             switch(choice)
//             {
//                 case 1:
//                     jc.Enter();
//                     break;

//                 case 2:
//                     jc.Exit();
//                     break;

//                 case 3:
//                     break;

//                 default:
//                     cout<<"Invalid choice\n";
//             }
//         }
//         catch(exception& e)
//         {
//             cout<<e.what()<<endl;
//         }
//     }

//     return 0;
// }
// #include<iostream>
// #include<string>
// using namespace std;

// class File;

// // Friend function prototype
// bool isDuplicate(const File& f1, const File& f2);

// class File{
// protected:
//     float size;
//     string location;
//     string createdDate;
//     string modifiedDate;

// public:
//     File(float s=0,
//          string loc="",
//          string c="",
//          string m="")
//     {
//         size = s;
//         location = loc;
//         createdDate = c;
//         modifiedDate = m;
//     }

//     virtual void open() = 0;

//     virtual void print()
//     {
//         cout<<"Generic File"<<endl;
//     }

//     virtual ~File(){}

//     friend bool isDuplicate(const File& f1,
//                             const File& f2);
// };

// class PDFFile : public File{
// public:
//     PDFFile(float s,
//             string loc,
//             string c,
//             string m)
//         : File(s,loc,c,m)
//     {
//     }

//     void open() override
//     {
//         cout<<"Opening PDF File"<<endl;
//     }

//     void print() override
//     {
//         cout<<"Printing PDF document"<<endl;
//     }
// };

// class ASCIIFile : public File{
// public:
//     ASCIIFile(float s,
//               string loc,
//               string c,
//               string m)
//         : File(s,loc,c,m)
//     {
//     }

//     void open() override
//     {
//         cout<<"Opening ASCII File"<<endl;
//     }

//     void print() override
//     {
//         cout<<"Printing ASCII text file"<<endl;
//     }
// };

// class PSFile : public File{
// public:
//     PSFile(float s,
//            string loc,
//            string c,
//            string m)
//         : File(s,loc,c,m)
//     {
//     }

//     void open() override
//     {
//         cout<<"Opening PS File"<<endl;
//     }

//     void print() override
//     {
//         cout<<"Printing PostScript file"<<endl;
//     }
// };

// // Global friend function
// bool isDuplicate(const File& f1,
//                  const File& f2)
// {
//     return (f1.size == f2.size &&
//             f1.location == f2.location);
// }

// int main()
// {
//     File* ptr1 = new PDFFile(
//         100,
//         "Karachi",
//         "01-01-24",
//         "02-01-24"
//     );

//     File* ptr2 = new ASCIIFile(
//         100,
//         "Karachi",
//         "05-01-24",
//         "06-01-24"
//     );

//     File* ptr3 = new PSFile(
//         200,
//         "Lahore",
//         "10-01-24",
//         "12-01-24"
//     );

//     ptr1->print();
//     ptr2->print();
//     ptr3->print();

//     cout<<endl;

//     if(isDuplicate(*ptr1,*ptr2))
//         cout<<"ptr1 and ptr2 are duplicates"<<endl;
//     else
//         cout<<"ptr1 and ptr2 are not duplicates"<<endl;

//     if(isDuplicate(*ptr1,*ptr3))
//         cout<<"ptr1 and ptr3 are duplicates"<<endl;
//     else
//         cout<<"ptr1 and ptr3 are not duplicates"<<endl;

//     delete ptr1;
//     delete ptr2;
//     delete ptr3;

//     return 0;
// }

#include<iostream>
#include<fstream>
using namespace std;

class Laptop{
protected:
    int id;
    float price;
    int hdd;
    int ram;

public:
    Laptop(){}

    float getPrice()
    {
        return price;
    }

    virtual void print()
    {
        cout<<"ID: "<<id
            <<" Price: "<<price
            <<" HDD: "<<hdd
            <<" RAM: "<<ram;
    }
};

class HP : public Laptop{
    int portsCount;

public:
    void print()
    {
        Laptop::print();
        cout<<" Ports: "<<portsCount<<endl;
    }
};

class Dell : public Laptop{
    float screenSize;

public:
    void print()
    {
        Laptop::print();
        cout<<" Screen Size: "<<screenSize<<endl;
    }
};

class Asus : public Laptop{
    int graphicsCardSize;

public:
    void print()
    {
        Laptop::print();
        cout<<" Graphics Card: "<<graphicsCardSize<<endl;
    }
};

int main()
{
    ifstream in("datafile.bin", ios::binary);

    if(!in)
    {
        cout<<"File not found\n";
        return 0;
    }

    float hpTotal = 0;
    float dellTotal = 0;
    float asusTotal = 0;

    for(int i=0;i<4;i++)
    {
        HP hp;
        in.read((char*)&hp,sizeof(hp));

        hp.print();
        hpTotal += hp.getPrice();


        Asus a;
        in.read((char*)&a,sizeof(a));

        a.print();
        asusTotal += a.getPrice();


        Dell d;
        in.read((char*)&d,sizeof(d));

        d.print();
        dellTotal += d.getPrice();
    }

    in.close();

    ofstream out("report.txt");

    if(out)
    {
        out<<"ELECTRONICS SHOP\n";
        out<<"------------------\n";

        out<<"HP: "<<hpTotal<<" PKR\n";
        out<<"DELL: "<<dellTotal<<" PKR\n";
        out<<"ASUS: "<<asusTotal<<" PKR\n";

        out<<"------------------\n";

        out<<"Total: "
           << hpTotal + dellTotal + asusTotal
           << " PKR\n";
    }

    out.close();

    return 0;
}