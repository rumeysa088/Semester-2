#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string type, brand, model;
    int ID, price, year, mileage;
    string condition, fuelType;
    static int totalVehicles;

public:
    Vehicle() : ID(0) {}
    Vehicle(string t, string b, string m, int id, int p, int y,
            int mil, string c, string f)
        : type(t), brand(b), model(m), ID(id), price(p),
          year(y), mileage(mil), condition(c), fuelType(f) { totalVehicles++; }
    Vehicle(const Vehicle& v)
        : type(v.type), brand(v.brand), model(v.model), ID(v.ID),
          price(v.price), year(v.year), mileage(v.mileage),
          condition(v.condition), fuelType(v.fuelType) {}

    virtual void display() const = 0;

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getPrice() const { return price; }
    int getYear() const { return year; }
    int getMileage() const { return mileage; }
    int getID() const { return ID; }
    string getType() const { return type; }

    static int getTotalVehicles() { return totalVehicles; }
    void setPrice(int p) { price = p; }
    void setYear(int y) { year = y; }
    void setMileage(int m) { mileage = m; }
    void setCondition(string c) { condition = c; }
    void resetMileage() { mileage = 0; }
    bool isNew() const { return condition == "New"; }

    bool isAffordable(int budget) const { return price <= budget; }
    bool isAffordable(int min, int max) const { return price >= min && price <= max; }

    bool operator==(const Vehicle& v) const { return this->ID == v.ID; }
    bool operator!=(const Vehicle& v) const { return this->ID != v.ID; }
    int operator+(const Vehicle& v) const { return this->price + v.price; }

    friend ostream& operator<<(ostream& out, const Vehicle& v);
    friend istream& operator>>(istream& in, Vehicle& v);

    virtual ~Vehicle() {}
};

#endif