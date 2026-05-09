#ifndef TRIP_H
#define TRIP_H

#include "route.h"
#include "vehicleprofile.h"

class Trip
{
public:
    //constructor that gets route, profile and fuel price
    Trip(const Route &route,  const VehicleProfile &profile, double fuelPrice);

    double calculateFuelRequired() const;
    double calculateTotalPrice() const;
    double getDistance() const;

private:
    Route infRoute;
    VehicleProfile infProfile;
    double infFuelPrice;
};

#endif // TRIP_H
