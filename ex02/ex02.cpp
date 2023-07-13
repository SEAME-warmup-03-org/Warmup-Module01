# include   <iostream>
using       namespace std;

class       Vehicle // abstract class
{
protected:
    int     make;
    int     model;
    int     year;

public:
    Vehicle(int make, int model, int year)
    :   make(make),
        model(model),
        year(year)
    {}

    virtual void drive() = 0;
};

class       Car :
            public virtual Vehicle
{

protected:
    int     wheel;

public:
    Car(int make, int model, int year, int wheel)
    :   Vehicle(make, model, year),
        wheel(wheel)
    {}

    void    drive() override
    {
        cout    << "Driving " << make << " " << model << " " << year << " " << wheel << " edition" << endl;
    }
};

class       Drone :
            public virtual Vehicle
{

protected:
    int     wings;

public:
    Drone(int make, int model, int year, int wings)
    :   Vehicle(make, model, year),
        wings(wings)
    {}

    void    drive() override
    {
        cout    << "Flying " << make << " " << model << " " << year << " " << wings << " edition" << endl;
    }
};

class       UAM :
            public Car,
            public Drone
{
public:
    UAM(int make, int model, int year, int wings, int wheel)
    :   Vehicle(make, model, year),
        Car(make, model, year, wheel),
        Drone(make, model, year, wings)
    {}

    void    drive() override
    {
        cout    << "Using UAM: " << make << " " << model << " " << year << " " << wings << " " << wheel << " edition" << endl;
    }
};


int         main(void)
{
    Car     seame(1, 2, 2023, 4);
    Drone   drone(4, 5, 2000, 6);
    cout << "1st : "w; seame.drive();
    cout << "2nd : "; drone.drive();

    Vehicle* vehicles[] = {&seame, &drone};

    for (const auto vehicle : vehicles)
    {
        cout << "for : ";
        vehicle->drive();
    }
    
    UAM     uam(7, 8, 9, 6, 4);
    cout << "uam : ";
    uam.drive();

    return 0;
}