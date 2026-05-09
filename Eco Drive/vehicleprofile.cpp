#include "vehicleprofile.h"
#include <QString>

VehicleProfile::VehicleProfile()
    : infModel("Unknown"), infConsumption(0.0), infFuelType("None"){}

void VehicleProfile::setModel(const QString &model){
    infModel = model;
}
void VehicleProfile::setConsumption(double consumption) {
    infConsumption = consumption;
}
void VehicleProfile::setFuelType(const QString &fuelType) {
    infFuelType = fuelType;
}

QString VehicleProfile::getModel() const {
    return infModel;
}
double VehicleProfile::getConsumption() const  {
    return infConsumption;
}
QString VehicleProfile::getFuelType() const {
    return infFuelType;
}

QString VehicleProfile::getShortSummary() const {
    return QString::number(infConsumption, 'f', 1) + " L/100km " + infFuelType;
}