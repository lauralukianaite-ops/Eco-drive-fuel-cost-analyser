#ifndef APIMANAGER_H
#define APIMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslSocket>
#include <QMap>

class APIManager : public QObject
{
    Q_OBJECT
public:
    explicit APIManager(QObject *parent = nullptr);
    virtual ~APIManager() = default;

protected:
    void makeGetRequest(const QString &urlString);
    void makeGetRequest(const QString &urlString,
                        const QMap<QString, QString> &headers);

    void makePostRequest(const QString &urlString,
                         const QByteArray &body,
                         const QString &fieldMask); // Routes API reikalauja X-Goog-FieldMask

signals:
    void requestFinished(const QByteArray &data);
    void errorOccurred(const QString &errorStr);

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_networkManager;
};

#endif // APIMANAGER_H