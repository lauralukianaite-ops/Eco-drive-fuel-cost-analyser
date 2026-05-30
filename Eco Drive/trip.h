#ifndef TRIP_H
#define TRIP_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include "route.h"
#include "vehicleprofile.h"
#include "distanceapi.h"
#include "fuelpriceapi.h"

class Trip : public QObject
{
    Q_OBJECT
public:
    Trip(const Route &route, const VehicleProfile &profile, QObject *parent = nullptr);

    void startCalculation();

    double calculateFuelRequired() const;
    double calculateTotalPrice() const;
    double getDistance() const;
    QVector<RouteOption> getRoutes() const { return m_routes; }

signals:
    void calculationFinished();
    void calculationError(const QString &error);

private slots:
    void onDistanceFetched(double distance);
    void onFuelPriceFetched(double price);
    void onApiError(const QString &errorStr);

private:
    void checkCompletion();

    Route          infRoute;
    VehicleProfile infProfile;

    DistanceAPI  *m_distanceApi;
    FuelPriceAPI *m_fuelPriceApi;
    QTimer       *m_watchdog;

    double m_distance  = 0.0;
    double m_fuelPrice = 0.0;

    QVector<RouteOption> m_routes;

    bool m_distanceReady  = false;
    bool m_fuelPriceReady = false;
};

#endif // TRIP_H
