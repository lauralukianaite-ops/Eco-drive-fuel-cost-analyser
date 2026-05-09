#include "trip.h"

Trip::Trip(const Route &route,  const VehicleProfile &profile, double fuelPrice)
    : infRoute(route), infProfile(profile), infFuelPrice(fuelPrice){}

double Trip::getDistance() const {
    return infRoute.getDistance();
}

double Trip::calculateFuelRequired() const {
    return (infRoute.getDistance() / 100.0) * infProfile.getConsumption();
}

double Trip::calculateTotalPrice() const {
    return calculateFuelRequired() * infFuelPrice;
}