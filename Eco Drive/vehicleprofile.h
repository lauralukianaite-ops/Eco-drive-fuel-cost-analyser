#ifndef VEHICLEPROFILE_H
#define VEHICLEPROFILE_H

#include <QString>

class VehicleProfile
{
public:
    VehicleProfile();

    void setModel(const QString &model);
    void setConsumption(double consumption);
    void setFuelType(const QString &fuelType);

    QString getModel() const;
    double getConsumption() const;
    QString getFuelType() const;

    QString getShortSummary() const;

private:
    QString infModel;
    double infConsumption;
    QString infFuelType;
};

#endif // VEHICLEPROFILE_H
