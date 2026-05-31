#include "trip.h"

static constexpr int kTimeoutMs = 10000;

Trip::Trip(const Route &route, const VehicleProfile &profile, QObject *parent)
    : QObject(parent), infRoute(route), infProfile(profile)
{
    m_distanceApi  = new DistanceAPI(this);
    m_fuelPriceApi = new FuelPriceAPI(this);

    connect(m_distanceApi,  &DistanceAPI::distanceFetched,   this, &Trip::onDistanceFetched);
    connect(m_fuelPriceApi, &FuelPriceAPI::fuelPriceFetched, this, &Trip::onFuelPriceFetched);
    connect(m_distanceApi,  &APIManager::errorOccurred,      this, &Trip::onApiError);
    connect(m_fuelPriceApi, &APIManager::errorOccurred,      this, &Trip::onApiError);

    m_watchdog = new QTimer(this);
    m_watchdog->setSingleShot(true);
    connect(m_watchdog, &QTimer::timeout, this, [this]() {
        emit calculationError("Request timed out. Please check your connection.");
    });
}

void Trip::startCalculation() {
    m_distanceReady  = false;
    m_fuelPriceReady = false;
    m_routes.clear();

    m_watchdog->start(kTimeoutMs);

    m_distanceApi->fetchDistance(infRoute.getStartLocation(), infRoute.getDestLocation());
    m_fuelPriceApi->fetchFuelPrice(infProfile.getFuelType());
}

void Trip::onDistanceFetched(double distance) {
    m_distance = distance;
    m_routes = m_distanceApi->lastRoutes();
    m_distanceReady = true;
    checkCompletion();
}

void Trip::onFuelPriceFetched(double price) {
    m_fuelPrice      = price;
    m_fuelPriceReady = true;
    checkCompletion();
}

void Trip::onApiError(const QString &errorStr) {
    m_watchdog->stop();
    emit calculationError(errorStr);
}

void Trip::checkCompletion() {
    if (m_distanceReady && m_fuelPriceReady) {
        for (auto &r : m_routes) {
            r.fuelCost = (r.distanceKm / 100.0) * infProfile.getConsumption() * m_fuelPrice;
        }
        m_watchdog->stop();
        emit calculationFinished();
    }
}

double Trip::getDistance() const { return m_distance; }

double Trip::calculateFuelRequired() const {
    return (m_distance / 100.0) * infProfile.getConsumption();
}

double Trip::calculateTotalPrice() const {
    return calculateFuelRequired() * m_fuelPrice;
}
