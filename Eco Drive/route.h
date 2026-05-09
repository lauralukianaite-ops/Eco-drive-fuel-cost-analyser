#ifndef ROUTE_H
#define ROUTE_H

#include <QString>

class Route
{
public:
     Route(const QString &start = QString(), const QString &destination = QString());

    double getDistance() const;
    int getTravelTimeMinutes() const;

private:
    QString infStart;
    QString infDestination;
 };

#endif // ROUTE_H
