#ifndef FUELPRICEAPI_H
#define FUELPRICEAPI_H

#include "apimanager.h"
#include <QString>

class FuelPriceAPI : public APIManager
{
    Q_OBJECT

public:
    explicit FuelPriceAPI(QObject *parent = nullptr);

    void fetchFuelPrice(const QString &fuelType);

signals:
    void fuelPriceFetched(double price);

private slots:
    void handleResponse(const QByteArray &data);

private:
    QString m_currentFuelType;

    QString getOilPriceCode(const QString &fuelType) const;
    double getFallbackPrice(const QString &fuelType) const;
};

#endif // FUELPRICEAPI_H