#include <iostream>

using namespace std;

class Vehicle // abstract class
{
protected:
    int make;
    int model;
    int year;

public:
    Vehicle() = default;

    Vehicle(int make, int model, int year)
    :   make(make),
        model(model),
        year(year)
    {}

    Vehicle(const Vehicle& other)
    :   make(other.make),
        model(other.model),
        year(other.year)
    {}

    virtual ~Vehicle() {}

    Vehicle& operator=(const Vehicle& other)
    {
        if (this != &other)
        {
            make = other.make;
            model = other.model;
            year = other.year;
        }
        return *this;
    }

    virtual void drive() = 0;
};

class Car : public virtual Vehicle
{
protected:
    int wheel;

public:
    Car() = default;

    Car(int make, int model, int year, int wheel)
    :   Vehicle(make, model, year),
        wheel(wheel)
    {}

    Car(const Car& other)
    :   Vehicle(other),
        wheel(other.wheel)
    {}

    ~Car() override {}

    Car& operator=(const Car& other)
    {
        if (this != &other)
        {
            Vehicle::operator=(other);
            wheel = other.wheel;
        }
        return *this;
    }

    void drive() override
    {
        cout << "Driving " << make << " " << model << " " << year << " " << wheel << " edition" << endl;
    }
};

class Drone : public virtual Vehicle
{
protected:
    int wings;

public:
    Drone() = default;

    Drone(int make, int model, int year, int wings)
    :   Vehicle(make, model, year),
        wings(wings)
    {}

    Drone(const Drone& other)
    :   Vehicle(other),
        wings(other.wings)
    {}

    ~Drone() override {}

    Drone& operator=(const Drone& other)
    {
        if (this != &other)
        {
            Vehicle::operator=(other);
            wings = other.wings;
        }
        return *this;
    }

    void drive() override
    {
        cout << "Flying " << make << " " << model << " " << year << " " << wings << " edition" << endl;
    }
};

class UAM : public Car, public Drone
{
public:
    UAM() = default;

    UAM(int make, int model, int year, int wings, int wheel)
    :   Vehicle(make, model, year),
        Car(make, model, year, wheel),
        Drone(make, model, year, wings)
    {}

    UAM(const UAM& other)
    :   Vehicle(other),
        Car(other),
        Drone(other)
    {}

    ~UAM() override {}

    UAM& operator=(const UAM& other)
    {
        if (this != &other)
        {
            Vehicle::operator=(other);
            Car::operator=(other);
            Drone::operator=(other);
        }
        return *this;
    }

    void drive() override
    {
        cout << "Using UAM: " << make << " " << model << " " << year << " " << wings << " " << wheel << " edition" << endl;
    }
};

int main(void)
{
    Car seame(1, 2, 2023, 4);
    Drone drone(4, 5, 2000, 6);

    cout << "1st : ";
    seame.drive();
    cout << "2nd : ";
    drone.drive();

    Vehicle* vehicles[] = { &seame, &drone };

    for (const auto vehicle : vehicles)
    {
        cout << "for : ";
        vehicle->drive();
    }

    UAM uam(7, 8, 9, 6, 4);
    cout << "uam : ";
    uam.drive();

    return 0;
}
