#ifndef SAVEDROUTES_H
#define SAVEDROUTES_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

struct SavedRoute {
    QString date;
    QString route;
    QString distance;
    QString fuel;
    QString price;
};

class SavedRoutes {
public:
    static QString getFilePath();
    static bool saveRoute(const SavedRoute &route);
    static bool deleteRoute(const SavedRoute &route);
    static QVector<SavedRoute> loadAllRoutes();

private:
    static QJsonObject routeToJson(const SavedRoute &route);
    static SavedRoute jsonToRoute(const QJsonObject &obj);
};

#endif // SAVEDROUTES_H