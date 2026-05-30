#include "distanceapi.h"
#include "config.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <algorithm>

DistanceAPI::DistanceAPI(QObject *parent) : APIManager(parent) {
    connect(this, &APIManager::requestFinished, this, &DistanceAPI::handleResponse);
}

void DistanceAPI::fetchDistance(const QString &start, const QString &destination) {
    QJsonObject body;
    body["origin"]                   = QJsonObject{{"address", start.trimmed()}};
    body["destination"]              = QJsonObject{{"address", destination.trimmed()}};
    body["travelMode"]               = "DRIVE";
    body["computeAlternativeRoutes"] = true;

    QString url = QString(
                      "https://routes.googleapis.com/directions/v2:computeRoutes?key=%1"
                      ).arg(GOOGLE_API_KEY);

    makePostRequest(url, QJsonDocument(body).toJson(),
                    "routes.distanceMeters,routes.duration");
}

void DistanceAPI::handleResponse(const QByteArray &data) {
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) {
        emit errorOccurred("Invalid response from Routes API.");
        return;
    }

    QJsonObject root = doc.object();
    if (root.contains("error")) {
        emit errorOccurred("Routes API error: " +
                           root["error"].toObject()["message"].toString());
        return;
    }

    QJsonArray jsonRoutes = root["routes"].toArray();
    if (jsonRoutes.isEmpty()) {
        emit errorOccurred("No routes found.");
        return;
    }

    m_lastRoutes.clear();
    for (const QJsonValue &r : jsonRoutes) {
        QJsonObject route = r.toObject();
        RouteOption opt;
        opt.distanceKm      = route["distanceMeters"].toDouble() / 1000.0;
        QString durStr      = route["duration"].toString(); // "11589s"
        opt.durationMinutes = durStr.left(durStr.length() - 1).toInt() / 60;
        m_lastRoutes.append(opt);
    }

    // Rūšiuojam pagal atstumą
    std::sort(m_lastRoutes.begin(), m_lastRoutes.end(),
              [](const RouteOption &a, const RouteOption &b) {
                  return a.distanceKm < b.distanceKm;
              });

    if (m_lastRoutes.size() > 2) m_lastRoutes.resize(2);

    // m_lastRoutes jau užpildytas — dabar siunčiam signalą
    emit distanceFetched(m_lastRoutes.first().distanceKm);
}