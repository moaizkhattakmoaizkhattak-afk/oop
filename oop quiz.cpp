#include <iostream>
using namespace std;

class Ride {
protected:
    string passengerName;
    int rideID;
    double baseFare;

public:
    Ride(string name, int id, double fare) {
        passengerName = name;
        rideID = id;
        baseFare = fare;
    }
};

class EconomyRide : public Ride {
private:
    double distanceKm;

public:
    EconomyRide(string name, int id, double fare, double distance)
        : Ride(name, id, fare)
    {
        distanceKm = distance;
    }

    double calculateFare() {
        double finalFare;
        finalFare = baseFare + (distanceKm * 8);
        return finalFare;
    }
};

class LuxuryRide : public Ride {
private:
    double distanceKm;
    double serviceCharge;

public:
    LuxuryRide(string name, int id, double fare,
               double distance, double service)
        : Ride(name, id, fare)
    {
        distanceKm = distance;
        serviceCharge = service;
    }

    double calculateFare() {
        double finalFare;
        finalFare = baseFare + (distanceKm * 12) + serviceCharge;
        return finalFare;
    }
};

int main() {

    EconomyRide e1("Ali", 101, 100, 5);
    LuxuryRide l1("Ahmed", 102, 200, 5, 50);

    cout << "Economy Ride Fare: " << e1.calculateFare() << endl;
    cout << "Luxury Ride Fare: " << l1.calculateFare() << endl;

    return 0;
}