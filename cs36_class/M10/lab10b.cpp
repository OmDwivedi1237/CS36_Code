#include <iostream>
using namespace std;

class Car {
private:
    int year;
    int miles_driven;
    int miles_per_gal;
    int fuel_level;
    int fuel_capacity;
    int num_passengers;
    int num_passengers_max;

public:
    Car() : year(2024), miles_driven(0), miles_per_gal(30), fuel_level(100),
            fuel_capacity(100), num_passengers(0), num_passengers_max(5) {}

    void drive(int miles) {
        int required_fuel = miles / miles_per_gal;
        if (required_fuel > fuel_level) {
            cout << "Error: Not enough fuel to drive " << miles << " miles." << endl;
            return;
        }
        miles_driven += miles;
        fuel_level -= required_fuel;
    }

    void load(int passengers) {
        if (num_passengers + passengers > num_passengers_max) {
            cout << "Error: Not enough capacity for " << passengers << " passengers." << endl;
            return;
        }
        num_passengers += passengers;
    }

    void fill() {
        fuel_level = fuel_capacity;
    }

    int level() const {
        return fuel_level;
    }

    void print_data() const {
        cout << "Year: " << year << endl;
        cout << "Miles Driven: " << miles_driven << endl;
        cout << "Miles per Gallon: " << miles_per_gal << endl;
        cout << "Fuel Level: " << fuel_level << endl;
        cout << "Fuel Capacity: " << fuel_capacity << endl;
        cout << "Number of Passengers: " << num_passengers << endl;
        cout << "Max Number of Passengers: " << num_passengers_max << endl;
    }
};

int main() {
    Car myCar;

    myCar.fill();

    cout << "Fuel Level: " << myCar.level() << endl;

    myCar.load(3);

    myCar.drive(60);

    myCar.print_data();

    return 0;
}
