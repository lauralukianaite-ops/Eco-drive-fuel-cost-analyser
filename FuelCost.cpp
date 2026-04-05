#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FuelCost {
    private:
        double distanceKm;
        double fuelConsumptionPerHundred;
        double fuelPricePerLiter;

    public:
        FuelCost(double distanceKm, double fuelConsumptionPerHundred, double fuelPricePerLiter) {
            init(distanceKm, fuelConsumptionPerHundred, fuelPricePerLiter);
        }

    private:
        void init(double distanceKm, double fuelConsumptionPerHundred, double fuelPricePerLiter) {
            setDistance(distanceKm);
            setConsumption(fuelConsumptionPerHundred);
            setFuelPrice(fuelPricePerLiter);
        }

    public:
        void setDistance(double distanceKm) {
            this->distanceKm = distanceKm;
        }

        void setConsumption(double fuelConsumptionPerHundred) {
            this->fuelConsumptionPerHundred = fuelConsumptionPerHundred;
        }

        void setFuelPrice(double fuelPricePerLiter) {
            this->fuelPricePerLiter = fuelPricePerLiter;
        }

        double getDistanceKm() {
            return distanceKm;
        }

        double getFuelConsumptionPerHundred() {
            return fuelConsumptionPerHundred;
        }

        double getFuelPricePerLiter() {
            return fuelPricePerLiter;
        }

        double calculateFuelNeeded() {
            return (distanceKm / 100.0) * fuelConsumptionPerHundred;
        }

        double calculateCost() {
            return calculateFuelNeeded() * fuelPricePerLiter;
        }

        string toString() {
            stringstream ss;
            ss << "Distance: " << distanceKm << " km" << endl;
            ss << "Consumption: " << fuelConsumptionPerHundred << " L/100km" << endl;
            ss << "Fuel price: " << fuelPricePerLiter << " EUR/L" << endl;
            return ss.str();
        }
};

int main(){

    double distance, consumption, price;

    cout << "Eco Drive Fuel Cost Calculator" << endl;
    cout << "Enter distance (km): ";
    cin >> distance;
    cout << "Enter fuel consumption (L/100km): ";
    cin >> consumption;
    cout << "Enter fuel price (EUR/L): ";
    cin >> price;
    cout << endl;
    FuelCost trip(distance, consumption, price);
    
    cout << "Information" << endl;
    cout << trip.toString() << endl;

    cout << "Fuel needed: " << trip.calculateFuelNeeded() << " L" << endl;
    cout << "Total cost: " << trip.calculateCost() << " EUR" << endl;

    return 0;
}
