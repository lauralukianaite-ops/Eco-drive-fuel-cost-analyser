#include "apimanager.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QSslConfiguration>

APIManager::APIManager(QObject *parent) : QObject(parent) {
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &APIManager::onReplyFinished);
}

static void applySslFix(QNetworkRequest &request) {
    // Pataisymas macOS SSL handshake klaidai (-9824)
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_2OrLater);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(sslConfig);
}

void APIManager::makeGetRequest(const QString &urlString) {
    QNetworkRequest request((QUrl(urlString)));
    request.setHeader(QNetworkRequest::UserAgentHeader, "EcoDriveApp/1.0");
    applySslFix(request);
    m_networkManager->get(request);
}

void APIManager::makePostRequest(const QString &urlString,
                                 const QByteArray &body,
                                 const QString &fieldMask) {
    QNetworkRequest request((QUrl(urlString)));
    request.setHeader(QNetworkRequest::UserAgentHeader,   "EcoDriveApp/1.0");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    // Routes API reikalauja nurodyti kuriuos laukus grąžinti
    request.setRawHeader("X-Goog-FieldMask", fieldMask.toUtf8());
    applySslFix(request);
    m_networkManager->post(request, body);
}

void APIManager::onReplyFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        emit requestFinished(reply->readAll());
    } else {
        emit errorOccurred(reply->errorString());
    }
    reply->deleteLater();
}