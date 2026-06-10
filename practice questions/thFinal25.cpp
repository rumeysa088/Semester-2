#include<iostream>
#include<fstream>
#include<cstring>
#include<exception>

using namespace std;

//==================== EXCEPTIONS ====================

class FileAccessException : public exception{
public:
    const char* what() const noexcept override{
        return "File could not be opened!";
    }
};

class ExtractionException : public exception{
public:
    const char* what() const noexcept override{
        return "No high-risk records found for extraction!";
    }
};

class DeleteTraceException : public exception{
public:
    const char* what() const noexcept override{
        return "No traces marked as deleted!";
    }
};

//==================== ABSTRACT CLASS ====================

class CyberOperation{
public:
    virtual void accessIntel() = 0;
    virtual void extractPayload() = 0;
    virtual void deleteTraces() = 0;
};

//==================== INTEL RECORD ====================

class IntelRecord{
    int recordID;
    char targetLocation[50];
    int riskLevel;
    char payload[100];
    bool isDeleted;

public:

    void input()
    {
        cout<<"Enter Record ID: ";
        cin>>recordID;

        cin.ignore();

        cout<<"Enter Target Location: ";
        cin.getline(targetLocation,50);

        cout<<"Enter Risk Level: ";
        cin>>riskLevel;

        cin.ignore();

        cout<<"Enter Payload: ";
        cin.getline(payload,100);

        // Encrypt payload (+3)
        for(int i=0; payload[i]!='\0'; i++)
        {
            payload[i] += 3;
        }

        isDeleted = false;
    }

    void display(bool decrypt)
    {
        cout<<"Record ID: "<<recordID<<endl;
        cout<<"Location : "<<targetLocation<<endl;
        cout<<"Risk Level : "<<riskLevel<<endl;

        cout<<"Payload : ";

        if(decrypt)
        {
            for(int i=0; payload[i]!='\0'; i++)
            {
                cout<<char(payload[i]-3);
            }
        }
        else
        {
            cout<<payload;
        }

        cout<<endl;
        cout<<"Deleted : "<<isDeleted<<endl;
        cout<<"--------------------------"<<endl;
    }

    int getRiskLevel()
    {
        return riskLevel;
    }

    bool isMarkedDeleted()
    {
        return isDeleted;
    }

    void markDeleted()
    {
        isDeleted = true;
    }

    friend class Operation;
};

//==================== OPERATION ====================

class Operation : public CyberOperation{
public:

    // Phase 3
    void accessIntel()
    {
        ifstream fin("intel.dat",ios::binary);

        if(!fin)
            throw FileAccessException();

        IntelRecord rec;

        cout<<"\n--- ACTIVE RECORDS ---\n";

        while(fin.read((char*)&rec,sizeof(rec)))
        {
            if(!rec.isMarkedDeleted())
            {
                rec.display(true);
            }
        }

        fin.close();
    }

    // Phase 4
    void extractPayload()
    {
        ifstream fin("intel.dat",ios::binary);

        if(!fin)
            throw FileAccessException();

        ofstream fout("extracted.dat",ios::binary);

        IntelRecord rec;
        bool found = false;

        while(fin.read((char*)&rec,sizeof(rec)))
        {
            if(rec.getRiskLevel() >= 8)
            {
                fout.write((char*)&rec,sizeof(rec));
                found = true;
            }
        }

        fin.close();
        fout.close();

        if(!found)
            throw ExtractionException();
    }

    // Phase 5
    void deleteTraces()
    {
        fstream file("intel.dat",
                     ios::binary |
                     ios::in |
                     ios::out);

        if(!file)
            throw FileAccessException();

        IntelRecord rec;
        bool found = false;

        while(file.read((char*)&rec,sizeof(rec)))
        {
            if(rec.getRiskLevel() >= 8)
            {
                rec.markDeleted();

                long pos = file.tellg();

                file.seekp(pos - sizeof(rec));

                file.write((char*)&rec,sizeof(rec));

                found = true;
            }
        }

        file.close();

        if(!found)
            throw DeleteTraceException();
    }
};

//==================== MAIN ====================

int main()
{
    try
    {
        ofstream fout("intel.dat",ios::binary);

        if(!fout)
            throw FileAccessException();

        int n;

        cout<<"How many records? ";
        cin>>n;

        IntelRecord rec;

        for(int i=0;i<n;i++)
        {
            cout<<"\nRecord "<<i+1<<endl;
            rec.input();

            fout.write((char*)&rec,sizeof(rec));
        }

        fout.close();

        Operation op;

        cout<<"\n===== ACCESS INTEL =====\n";
        op.accessIntel();

        cout<<"\n===== EXTRACT PAYLOAD =====\n";
        op.extractPayload();

        cout<<"High-risk records copied to extracted.dat\n";

        cout<<"\n===== DELETE TRACES =====\n";
        op.deleteTraces();

        cout<<"High-risk records marked as deleted\n";

        cout<<"\n===== AFTER DELETION =====\n";
        op.accessIntel();
    }

    catch(const exception& e)
    {
        cout<<"Exception: "<<e.what()<<endl;
    }

    return 0;
}

#include<iostream>
using namespace std;

class Product
{
    int id;
    string name;
    string description;
    int quantity;
    double price;

public:

    Product(){}

    Product(int i,string n,string d,int q,double p)
    {
        id=i;
        name=n;
        description=d;
        quantity=q;
        price=p;
    }

    ~Product(){}

    string getName()
    {
        return name;
    }

    double getPrice()
    {
        return price;
    }

    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Description: "<<description<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class ShoppingCart
{
    Product products[20];
    int count;

public:

    ShoppingCart()
    {
        count=0;
    }

    void addItem(Product& p,int quantity)
    {
        if(quantity<=0)
        {
            cout<<"Invalid Quantity!"<<endl;
            return;
        }

        for(int i=0;i<quantity;i++)
        {
            if(count<20)
            {
                products[count]=p;
                count++;
            }
            else
            {
                cout<<"Cart Full!"<<endl;
                break;
            }
        }
    }

    double getTotal()
    {
        double total=0;

        for(int i=0;i<count;i++)
        {
            total+=products[i].getPrice();
        }

        return total;
    }

    bool searchP(string name)
    {
        for(int i=0;i<count;i++)
        {
            if(products[i].getName()==name)
            {
                products[i].display();
                return true;
            }
        }

        return false;
    }
};

class Customer
{
    int id;
    string name;
    ShoppingCart cart;

public:

    Customer(int i,string n)
    {
        id=i;
        name=n;
    }

    ~Customer(){}

    ShoppingCart& getCart()
    {
        return cart;
    }

    void searchProducts(Product* p,string productName)
    {
        bool found=false;

        for(int i=0;i<20;i++)
        {
            if(p[i].getName()==productName)
            {
                p[i].display();
                found=true;
                break;
            }
        }

        if(!found)
        {
            cout<<"Not Available"<<endl;
        }
    }
};

int main()
{
    Product p1(1,"Book","OOP Book",10,1000);
    Product p2(2,"Laptop","Gaming Laptop",5,150000);

    Customer c1(101,"Ali");

    c1.getCart().addItem(p1,2);
    c1.getCart().addItem(p2,1);

    cout<<"Total Bill = "<<c1.getCart().getTotal()<<endl;

    Product list[2]={p1,p2};

    c1.searchProducts(list,"Laptop");

    return 0;
}
#include <iostream>
#include <exception>
using namespace std;

const int ROWS = 2;
const int COLS = 2;

//================ EXCEPTION =================

class IllegalArgumentException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Matrix dimensions do not match!";
    }
};

//================ CLASS =================

template<class T1, class T2>
class ImagePixelCalculator
{
private:
    T1 image1[ROWS][COLS];
    T2 image2[ROWS][COLS];

public:

    ImagePixelCalculator(
        T1 img1[ROWS][COLS],
        T2 img2[ROWS][COLS],
        int rows,
        int cols)
    {
        if(rows != ROWS || cols != COLS)
            throw IllegalArgumentException();

        setImage1(img1);
        setImage2(img2);
    }

    void setImage1(T1 img[ROWS][COLS])
    {
        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                image1[i][j]=img[i][j];
            }
        }
    }

    void setImage2(T2 img[ROWS][COLS])
    {
        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                image2[i][j]=img[i][j];
            }
        }
    }

    T1 (*getImage1())[COLS]
    {
        return image1;
    }

    T2 (*getImage2())[COLS]
    {
        return image2;
    }
};

//================ GENERIC FUNCTIONS =================

// Addition
template<class T1,class T2>
void denormalizeImage(
    T1 a[ROWS][COLS],
    T2 b[ROWS][COLS])
{
    cout<<"\nAddition:\n";

    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<a[i][j]+b[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Subtraction
template<class T1,class T2>
void normalizeImage(
    T1 a[ROWS][COLS],
    T2 b[ROWS][COLS])
{
    cout<<"\nSubtraction:\n";

    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<a[i][j]-b[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Multiplication
template<class T1,class T2>
void applyFilter(
    T1 a[ROWS][COLS],
    T2 b[ROWS][COLS])
{
    cout<<"\nMultiplication:\n";

    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<a[i][j]*b[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Average
template<class T1,class T2>
void smoothImage(
    T1 a[ROWS][COLS],
    T2 b[ROWS][COLS])
{
    cout<<"\nAverage:\n";

    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<(a[i][j]+b[i][j])/2.0<<" ";
        }
        cout<<endl;
    }
}

// Transpose
template<class T>
void transposeImage(T a[ROWS][COLS])
{
    cout<<"\nTranspose:\n";

    for(int i=0;i<COLS;i++)
    {
        for(int j=0;j<ROWS;j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}

// Generic print function
template<class T>
void printImageMatrix(T a[ROWS][COLS])
{
    cout<<"\nMatrix:\n";

    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

//================ MAIN =================

int main()
{
    try
    {
        float img1[ROWS][COLS] =
        {
            {1.5,2.5},
            {3.5,4.5}
        };

        double img2[ROWS][COLS] =
        {
            {10.0,20.0},
            {30.0,40.0}
        };

        ImagePixelCalculator<float,double>
        obj(img1,img2,ROWS,COLS);

        printImageMatrix(obj.getImage1());
        printImageMatrix(obj.getImage2());

        denormalizeImage(
            obj.getImage1(),
            obj.getImage2());

        normalizeImage(
            obj.getImage1(),
            obj.getImage2());

        applyFilter(
            obj.getImage1(),
            obj.getImage2());

        smoothImage(
            obj.getImage1(),
            obj.getImage2());

        transposeImage(
            obj.getImage2());
    }

    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}