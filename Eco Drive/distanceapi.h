#ifndef DISTANCEAPI_H
#define DISTANCEAPI_H

#include "apimanager.h"
#include <QVector>

struct RouteOption {
    double distanceKm      = 0.0;
    int    durationMinutes = 0;
    double fuelCost        = 0.0;
};

class DistanceAPI : public APIManager
{
    Q_OBJECT
public:
    explicit DistanceAPI(QObject *parent = nullptr);
    void fetchDistance(const QString &start, const QString &destination);

    // Grąžina paskutinį maršrutų sąrašą (užpildoma prieš distanceFetched)
    QVector<RouteOption> lastRoutes() const { return m_lastRoutes; }

signals:
    void distanceFetched(double distanceKm);

private slots:
    void handleResponse(const QByteArray &data);

private:
    QVector<RouteOption> m_lastRoutes;
};

#endif // DISTANCEAPI_H