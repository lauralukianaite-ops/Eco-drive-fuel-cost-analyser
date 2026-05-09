#include "savedroutes.h"
#include <QStandardPaths>
#include <utility>

QString SavedRoutes::getFilePath() {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
    + "/EcoDrive_routes.json";
}

QJsonObject SavedRoutes::routeToJson(const SavedRoute &route) {
    QJsonObject obj;
    obj["date"] = route.date;
    obj["route"] = route.route;
    obj["distance"] = route.distance;
    obj["fuel"] = route.fuel;
    obj["price"] = route.price;
    return obj;
}

SavedRoute SavedRoutes::jsonToRoute(const QJsonObject &obj) {
    SavedRoute route;
    route.date = obj["date"].toString();
    route.route = obj["route"].toString();
    route.distance = obj["distance"].toString();
    route.fuel = obj["fuel"].toString();
    route.price = obj["price"].toString();
    return route;
}

bool SavedRoutes::saveRoute(const SavedRoute &newRoute) {
    QVector<SavedRoute> routes = loadAllRoutes();
    routes.append(newRoute);

    QJsonArray jsonArray;
    for (const auto &r : std::as_const(routes)) jsonArray.append(routeToJson(r));

    QFile file(getFilePath());
    if (!file.open(QIODevice::WriteOnly)) return false;
    file.write(QJsonDocument(jsonArray).toJson());
    file.close();
    return true;
}

bool SavedRoutes::deleteRoute(const SavedRoute &targetRoute) {
    QVector<SavedRoute> routes = loadAllRoutes();
    for (int i = 0; i < routes.size(); ++i) {
        if (routes[i].date == targetRoute.date &&
            routes[i].route == targetRoute.route &&
            routes[i].distance == targetRoute.distance) {

            routes.removeAt(i);

            QJsonArray jsonArray;
            for (const auto &r : std::as_const(routes)) jsonArray.append(routeToJson(r));

            QFile file(getFilePath());
            if (!file.open(QIODevice::WriteOnly)) return false;
            file.write(QJsonDocument(jsonArray).toJson());
            file.close();
            return true;
        }
    }
    return false; // Jei nerasta
}

QVector<SavedRoute> SavedRoutes::loadAllRoutes() {
    QVector<SavedRoute> routes;
    QFile file(getFilePath());
    if (!file.exists() || !file.open(QIODevice::ReadOnly)) return routes;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (doc.isArray()) {
        for (const QJsonValue &val : doc.array()) {
            routes.append(jsonToRoute(val.toObject()));
        }
    }
    return routes;
}