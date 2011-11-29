#ifndef NETMANAGER_H
#define NETMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslError>
#include <QByteArray>
#include "nettracker.h"

class NetManager : public QObject
{
    Q_OBJECT
public:
    explicit NetManager(QObject *parent = 0);
    QNetworkAccessManager *manager;

signals:
    void replyRecieved(QNetworkReply*);
    void replySslErrors(QNetworkReply*, QList<QSslError>);

public slots:
    void replyFinished(QNetworkReply*);
    void sslErrors(QNetworkReply*, QList<QSslError>);
};

#endif // NETMANAGER_H
