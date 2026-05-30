#ifndef ROUTE_H
#define ROUTE_H

#include <QString>

class Route
{
public:
     Route(const QString &start = QString(), const QString &destination = QString());

    double getDistance() const;
    int getTravelTimeMinutes() const;
    QString getStartLocation() const { return infStart; }
    QString getDestLocation() const { return infDestination; }

private:
    QString infStart;
    QString infDestination;
 };

#endif // ROUTE_H
