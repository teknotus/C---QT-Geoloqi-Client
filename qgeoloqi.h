#ifndef LOQICLIENT_H
#define LOQICLIENT_H

#include "qgeoloqireply.h"

class QGeoloqi : public QObject
{
    Q_OBJECT
public:
    QGeoloqi();
    QGeoloqi(QString, QString);

    QGeoloqiReply* getAuthToken(QString, QString);
    void setClientId(QString);
    void setClientSecret(QString);
    QString getToken();
    void setToken(QString);
    QGeoloqiReply* getUsername();
    QGeoloqiReply* getProfile();
    QGeoloqiReply* getLastLocation();
    QGeoloqiReply* getHistory();
    QGeoloqiReply* getPlaces(QString, QString , QString);
    QGeoloqiReply* getNearbyPlaces(QString, QString , QString, QString);
    QGeoloqiReply* getPlaceInfo(QString);
    QGeoloqiReply* deletePlace(QString);

    QByteArray encodeJson(QVariant);
    QVariant decodeJson(QByteArray);
    QByteArray encodeUrlEncoded(QVector<QPair<QString,QString> >&);
    QVector<QPair<QString,QString> > decodeUrlEncoded(QByteArray);
    QString api_url;
    QString token;
    QGeoloqiReply* get(QUrl);

public slots:
    void sslErrors(QNetworkReply*, QList<QSslError>);
/*signals:
    void onError();
    void onUsername(QVariantMap);
    void onProfile(QVariantMap);
    void onLastLocation(QVariantMap);
    void onHistory(QVariantMap);*/
private:
    QNetworkAccessManager* manager;
    QString client_id;
    QString client_secret;
    void QGeoloqiCommon();
    QGeoloqiReply* post(QUrl, QByteArray);
};

#endif // LOQICLIENT_H
