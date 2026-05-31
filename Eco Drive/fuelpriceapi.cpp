#include "fuelpriceapi.h"
#include "config.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMap>
#include <QUrl>
#include <QUrlQuery>

FuelPriceAPI::FuelPriceAPI(QObject *parent)
    : APIManager(parent)
{
    connect(this, &APIManager::requestFinished,
            this, &FuelPriceAPI::handleResponse);
}

void FuelPriceAPI::fetchFuelPrice(const QString &fuelType)
{
    m_currentFuelType = fuelType.trimmed().toLower();

    const QString oilPriceCode = getOilPriceCode(m_currentFuelType);

    if (oilPriceCode.isEmpty()) {
        emit errorOccurred("Unsupported fuel type.");
        return;
    }

    QUrl url("https://api.oilpriceapi.com/v1/prices/latest");

    QUrlQuery query;
    query.addQueryItem("by_code", oilPriceCode);
    url.setQuery(query);

    QMap<QString, QString> headers;
    headers.insert("Authorization", QString("Token %1").arg(OILPRICE_API_KEY));
    headers.insert("Accept", "application/json");

    makeGetRequest(url.toString(), headers);
}

void FuelPriceAPI::handleResponse(const QByteArray &data)
{
    QJsonParseError parseError;
    const QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError || !doc.isObject()) {
        const double fallbackPrice = getFallbackPrice(m_currentFuelType);

        if (fallbackPrice > 0.0) {
            emit fuelPriceFetched(fallbackPrice);
            return;
        }

        emit errorOccurred("Invalid response from OilPriceAPI.");
        return;
    }

    const QJsonObject root = doc.object();

    if (root.value("status").toString() != "success") {
        const double fallbackPrice = getFallbackPrice(m_currentFuelType);

        if (fallbackPrice > 0.0) {
            emit fuelPriceFetched(fallbackPrice);
            return;
        }

        emit errorOccurred("OilPriceAPI returned an error.");
        return;
    }

    const QJsonObject dataObject = root.value("data").toObject();
    const double price = dataObject.value("price").toDouble();

    if (price <= 0.0) {
        const double fallbackPrice = getFallbackPrice(m_currentFuelType);

        if (fallbackPrice > 0.0) {
            emit fuelPriceFetched(fallbackPrice);
            return;
        }

        emit errorOccurred("Fuel price was not found in OilPriceAPI response.");
        return;
    }

    emit fuelPriceFetched(price);
}

QString FuelPriceAPI::getOilPriceCode(const QString &fuelType) const
{
    const QString normalizedFuelType = fuelType.trimmed().toLower();

    if (normalizedFuelType == "petrol" ||
        normalizedFuelType == "gasoline" ||
        normalizedFuelType == "benzinas" ||
        normalizedFuelType == "95" ||
        normalizedFuelType == "euro 95") {
        return "GASOLINE_RETAIL_LT_EUR";
    }

    if (normalizedFuelType == "diesel" ||
        normalizedFuelType == "dyzelinas") {
        return "DIESEL_RETAIL_LT_EUR";
    }

    return "";
}

double FuelPriceAPI::getFallbackPrice(const QString &fuelType) const
{
    const QString normalizedFuelType = fuelType.trimmed().toLower();

    if (normalizedFuelType == "petrol" ||
        normalizedFuelType == "gasoline" ||
        normalizedFuelType == "benzinas" ||
        normalizedFuelType == "95" ||
        normalizedFuelType == "euro 95") {
        return 1.8241;
    }

    if (normalizedFuelType == "diesel" ||
        normalizedFuelType == "dyzelinas") {
        return 1.926;
    }

    return 0.0;
}