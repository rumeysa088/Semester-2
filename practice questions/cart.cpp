#include <iostream>
#include <exception>
#include <string>
using namespace std;

class MartExceptions : public exception
{
    string msg;

public:
    MartExceptions(string m) : msg(m) {}

    const char* what() const noexcept override
    {
        return msg.c_str();
    }
};

class UniqueCart
{
private:
    string items[10];
    int count;

public:
    UniqueCart()
    {
        count = 0;
    }

    bool exists(string item)
    {
        for(int i = 0; i < count; i++)
        {
            if(items[i] == item)
                return true;
        }
        return false;
    }

    bool full()
    {
        return count == 10;
    }

    void add(string item)
    {
        if(full())
            throw MartExceptions("Out of Bound Exception: Cart Full!");

        if(exists(item))
            throw MartExceptions("Duplicate Item Exception!");

        items[count++] = item;
    }

    void remove(string item)
    {
        if(!exists(item))
            throw MartExceptions("Item Not Found Exception!");

        for(int i = 0; i < count; i++)
        {
            if(items[i] == item)
            {
                for(int j = i; j < count - 1; j++)
                {
                    items[j] = items[j + 1];
                }

                count--;
                break;
            }
        }
    }

    bool contains(string item)
    {
        return exists(item);
    }

    void display()
    {
        if(count == 0)
        {
            cout << "Cart is empty\n";
            return;
        }

        cout << "Items in cart:\n";

        for(int i = 0; i < count; i++)
        {
            cout << items[i] << endl;
        }
    }
};

int main()
{
    UniqueCart c;

    try
    {
        c.add("Book");
        c.add("Laptop");
        c.add("Shirt");

        c.display();

        cout << "\nContains Laptop? "
             << (c.contains("Laptop") ? "Yes" : "No")
             << endl;

        c.remove("Laptop");

        cout << "\nAfter removing Laptop:\n";
        c.display();

        c.add("Book"); // Duplicate Item Exception
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}