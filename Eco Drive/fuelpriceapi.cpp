#include "fuelpriceapi.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

FuelPriceAPI::FuelPriceAPI(QObject *parent)
    : APIManager(parent)
{
    connect(this, &APIManager::requestFinished,
            this, &FuelPriceAPI::handleResponse);
}

void FuelPriceAPI::fetchFuelPrice(const QString &fuelType)
{
    m_currentFuelType = fuelType.trimmed().toLower();

    /*
     * For now this project uses fallback values instead of a real fuel price API,
     * because the real API endpoint/key can be added later without changing Trip.
     */
    double price = getFallbackPrice(m_currentFuelType);

    if (price <= 0.0) {
        emit errorOccurred("Could not determine fuel price.");
        return;
    }

    QTimer::singleShot(0, this, [this, price]() {
        emit fuelPriceFetched(price);
    });

    /*
     * Later, if a real endpoint is used, this method should look more like:
     *
     * QString url = QString("https://some-fuel-api.example/prices?fuel=%1")
     *                   .arg(m_currentFuelType);
     * makeGetRequest(url);
     *
     * Then handleResponse() would parse the JSON response.
     */
}

void FuelPriceAPI::handleResponse(const QByteArray &data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull() || !doc.isObject()) {
        emit errorOccurred("Invalid response from Fuel Price API.");
        return;
    }

    QJsonObject root = doc.object();

    if (root.contains("error")) {
        emit errorOccurred("Fuel Price API error.");
        return;
    }

    /*
     * Placeholder parsing logic.
     * This can be adjusted when the real fuel price API response format is known.
     */
    double price = root["price"].toDouble();

    if (price <= 0.0) {
        emit errorOccurred("Fuel price was not found in API response.");
        return;
    }

    emit fuelPriceFetched(price);
}

double FuelPriceAPI::getFallbackPrice(const QString &fuelType) const
{
    QString normalizedFuelType = fuelType.trimmed().toLower();

    if (normalizedFuelType == "petrol") {
        return 1.74;
    }

    if (normalizedFuelType == "diesel") {
        return 1.88;
    }

    return 0.0;
}